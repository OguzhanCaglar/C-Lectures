## Proje-5.0: Process Monitor

### Amaç

- Tüm çalışan işlemlerin (proseslerin) isimini, PID'sini isteğe göre RAM kullanımını listeleyen bir terminal
uygulaması.
- Kullanıcıdan bir PID alıp "kill" komutu gönderebilsin.
- Windows'ta C ile native API kullanılarak yazılacak.

API: https://learn.microsoft.com/en-us/windows/win32/api/

# =========================== V1 ======================================

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#include <tlhelp32.h>

#define  mListCommand   1
#define  mKillCommand   2
#define  mExitCommand   3

void fListProcess(void);
void fKillProcess(DWORD pid);

int main()
{
    int choice;
    
    while (1)
    {
        printf("\n=== PROCESS MONITOR ===\n");
        printf("1. Islemleri Listele\n");
        printf("2. PID ile Islem Sonlandir\n");
        printf("3. Cikis\n");
        printf("Seciminiz: ");
        scanf("%d", &choice);

        if(choice == mListCommand)
        {
            fListProcess();
        }
        else if (choice == mKillCommand)
        {
            DWORD pid;
            printf("Sonlandirmak istediginiz PID: ");
            scanf("%lu", &pid);
            fKillProcess(pid);
        }
        else if(choice == mExitCommand)
        {
            printf("Cikiliyor...\n");
            break;
        }
        else 
        {
            printf("Gecersiz Secim!\n");
        }
    }
    return 0;
}

void fListProcess(void)
{
    PROCESSENTRY32 pe32;
    HANDLE hProcessSnap;

    pe32.dwSize = sizeof(PROCESSENTRY32);
    hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

    if(hProcessSnap == INVALID_HANDLE_VALUE)
    {
        printf("Snapshot alinamadi!\n");
        return;
    }

    if(!Process32First(hProcessSnap, &pe32))
    {
        CloseHandle(hProcessSnap);
        printf("Process bilgisi alinamadi!\n");
        return;
    }

    printf("%-6s %-30s\n", "PID", "Process Adi");
    printf("----------------------------------------------------\n");
    do
    {
        printf("%-6u %-30s\n", pe32.th32ProcessID, pe32.szExeFile);
    } while (Process32Next(hProcessSnap, &pe32));
    
    CloseHandle(hProcessSnap);
}

void fKillProcess(DWORD pid)
{
    HANDLE hProcess = OpenProcess(PROCESS_TERMINATE, FALSE, pid);

    if(hProcess == NULL)
    {
        printf("İslem sonlandirilamadi (yetersiz izin veya PID yanlis): %lu\n", pid);
        return;
    }

    if(TerminateProcess(hProcess, 0))
    {
        printf("PID %lu basariyla sonlandirildi.\n", pid);
    }
    else
    {
        printf("PID %lu sonlandirilamadi.\n", pid);
    }

    CloseHandle(hProcess);
    return;
}
```

# =========================== V2 ======================================

- Ram kullanımını göstermek.
- Process adı filtrelemesi
- Listeyi dosyaya yazma.
- Sürekli güncelleme (anlık izleme)

```c
#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <tlhelp32.h>
#include <psapi.h>
#include <stdio.h>

#define  mListCommand        1
#define  mKillCommand        2
#define  mSearchCommand      3
#define  mSaveCommand        4
#define  mWatchCommand       5
#define  mExitCommand        6

#define  mMaxProcessName     20
#define  mMinInterval        1
#define  mDefaultInterval    2
#define  mMiliSecond         1000

int gExit;

void fListProcess(const char *filter);
void fKillProcess(DWORD pid);
void fListProcessToFile(const char* filter, FILE *fp);

int main()
{
    int choice;
    DWORD pid;
    char filter[mMaxProcessName] = "";
    FILE *fp;
    int interval = mDefaultInterval;
    int repeat = -1;
    int count = 0;
    
    while (1)
    {
        printf("\n=== PROCESS MONITOR ===\n");
        printf("1. Islemleri Listele\n");
        printf("2. PID ile Islem Sonlandir\n");
        printf("3. Process Ara\n");
        printf("4. Islem listesini dosyaya kaydet\n");
        printf("5. Anlik Izleme Modu\n");
        printf("6. Cikis\n");
        printf("Seciminiz: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case mListCommand:
                fListProcess("");
                break;
            
            case mKillCommand:
                printf("Sonlandirmak istediginiz PID: ");
                scanf("%lu", &pid);
                fKillProcess(pid);
                break;

            case mSearchCommand:
                printf("Process adi filtresi girin (veya enter'a basin, tumunu listeler): ");
                getchar(); // satır sonu temizlensin
                fgets(filter, sizeof(filter), stdin);
                filter[strcspn(filter, "\n")] = 0; // \n sil
                fListProcess(filter);
                break;
            
            case mSaveCommand:
                printf("Kaydetmek icin process adi filtresi (veya bos): ");
                getchar();
                fgets(filter, sizeof(filter), stdin);
                filter[strcspn(filter, "\n")] = 0;

                fp = fopen("processlist.txt", "w");
                if(!fp)
                {
                    printf("Dosya acilamadi!\n");
                }
                else
                {
                    fListProcessToFile(filter, fp);
                    fclose(fp);
                    printf("Process listesi 'processlist.txt' olarak kaydedildi.\n");
                }
                break;
            
            case mWatchCommand:
                printf("Kac saniyede bir guncellensin? (varsayilan: 2): ");
                scanf("%d", &interval);
                
                if(interval < mMinInterval)
                    interval = mDefaultInterval;

                printf("Kac tekrar? (sinirsiz ise -1): ");
                scanf("%d", &repeat);

                while(repeat < 0 || count < repeat)
                {
                    system("cls");
                    printf("CANLI PROCESS LISTESI (%d. goruntuleme)\n", count+1);
                    fListProcess("");
                    Sleep(interval * mMiliSecond);
                    count++;
                }
                break;

            case mExitCommand:
                printf("Cikiliyor...\n");
                gExit = 1;
                break;
            
            default:
                printf("Gecersiz Secim!\n");
                break;
        }

        if(gExit)
        {
            break;
        }
    }
    return 0;
}

void fListProcess(const char *filter)
{
    PROCESSENTRY32 pe32;
    HANDLE hProcessSnap;

    pe32.dwSize = sizeof(PROCESSENTRY32);
    hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

    if(hProcessSnap == INVALID_HANDLE_VALUE)
    {
        printf("Snapshot alinamadi!\n");
        return;
    }

    if(!Process32First(hProcessSnap, &pe32))
    {
        CloseHandle(hProcessSnap);
        printf("Process bilgisi alinamadi!\n");
        return;
    }

    printf("%-6s %-30s %10s\n", "PID", "Process Adi", "RAM (KB)");
    printf("----------------------------------------------------\n");
    do
    {
        if((strlen(filter) == 0) || strstr(pe32.szExeFile, filter))
        {
            HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, pe32.th32ProcessID);
            PROCESS_MEMORY_COUNTERS pmc;
            if(hProcess && GetProcessMemoryInfo(hProcess, &pmc, sizeof(pmc)))
            {
                printf("%-6u %-30s %10lu\n", pe32.th32ProcessID, pe32.szExeFile, pmc.WorkingSetSize/1024);
            }
            else
            {
                printf("%-6u %-30s %10s\n", pe32.th32ProcessID, pe32.szExeFile, "N/A");
            }
            
            if(hProcess)
            {
                CloseHandle(hProcess);
            }
        }

    } while (Process32Next(hProcessSnap, &pe32));
    
    CloseHandle(hProcessSnap);
}

void fKillProcess(DWORD pid)
{
    HANDLE hProcess = OpenProcess(PROCESS_TERMINATE, FALSE, pid);

    if(hProcess == NULL)
    {
        printf("İslem sonlandirilamadi (yetersiz izin veya PID yanlis): %lu\n", pid);
        return;
    }

    if(TerminateProcess(hProcess, 0))
    {
        printf("PID %lu basariyla sonlandirildi.\n", pid);
    }
    else
    {
        printf("PID %lu sonlandirilamadi.\n", pid);
    }

    CloseHandle(hProcess);
    return;
}

void fListProcessToFile(const char* filter, FILE *fp)
{
    PROCESSENTRY32 pe32;
    HANDLE hProcessSnap;

    pe32.dwSize = sizeof(PROCESSENTRY32);
    hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

    if(hProcessSnap == INVALID_HANDLE_VALUE)
    {
        fprintf(fp, "Snapshot alinamadi!\n");
        return;
    }

    if(!Process32First(hProcessSnap, &pe32))
    {
        CloseHandle(hProcessSnap);
        fprintf(fp, "Process bilgisi alinamadi!\n");
        return;
    }

    fprintf(fp, "%-6s %-30s %10s\n", "PID", "Process Adi", "RAM (KB)");
    fprintf(fp, "----------------------------------------------------\n");
    do
    {
        if((strlen(filter) == 0) || strstr(pe32.szExeFile, filter))
        {
            HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, pe32.th32ProcessID);
            PROCESS_MEMORY_COUNTERS pmc;
            if(hProcess && GetProcessMemoryInfo(hProcess, &pmc, sizeof(pmc)))
            {
                fprintf(fp, "%-6u %-30s %10lu\n", pe32.th32ProcessID, pe32.szExeFile, pmc.WorkingSetSize/1024);
            }
            else
            {
                fprintf(fp, "%-6u %-30s %10s\n", pe32.th32ProcessID, pe32.szExeFile, "N/A");
            }
            
            if(hProcess)
            {
                CloseHandle(hProcess);
            }
        }

    } while (Process32Next(hProcessSnap, &pe32));
    
    CloseHandle(hProcessSnap);
}
```

# =========================== V3 ======================================

- Filtreyi canlı izlemeye de ekle
- Sadece RAM'i 50 MB'tan fazla olanları göster gibi özel filtreler eklebilir.
- Canlı izleme sırasında CPU kullanımını da ekle
- RAM veya PID değişimlerini algılayıp vurgulama.
- RAM kullanımını sıralama