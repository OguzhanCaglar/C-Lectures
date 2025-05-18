#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define FILENAME            "notes.txt"
#define MAX_NOTE_LENGTH     256
#define EXIT_COMMAND        6
#define PASSWORD_FILE       "password.txt"
#define MAX_ATTEMPS         3

/* ================ PASSWORD OPERATIONS ===============*/

int checkPassword(void)
{
    FILE *fp = fopen(PASSWORD_FILE, "r");
    if(fp == NULL)
    {
        printf("HATA: %s dosyasi bulunamadi!\n", PASSWORD_FILE);
        return 0;
    }

    char realPassword[50];
    fgets(realPassword, sizeof(realPassword), fp);
    realPassword[strcspn(realPassword, "\n")] = '\0';
    fclose(fp);

    char input[50];
    int attempts = 0;

    while (attempts < MAX_ATTEMPS)
    {
        printf("Sifreyi girin (%d/%d): ", attempts + 1, MAX_ATTEMPS); // Sifreyi girin (1/3);
        scanf("%s", input);

        if(strcmp(input, realPassword) == 0)
        {
            printf("Giris basarili! Hos geldiniz!\n\n");
            return 1;
        } 
        else 
        {
            printf("Hatali Sifre. %d hakkiniz kaldi.\n", MAX_ATTEMPS - attempts - 1);
            attempts++;
        }
    }


    printf("3 yanlis giris yapildi. Program sonlandiriliyor...\n");
    return 0;    
}

void changePassword()
{
    FILE *fp = fopen(PASSWORD_FILE, "r");
    if(fp == NULL)
    {
        printf("Sifre dosyasi acilamadi!\n");
        return;
    }

    char currentPassword[50];
    fgets(currentPassword, sizeof(currentPassword), fp);
    currentPassword[strcspn(currentPassword, "\n")] = '\0'; // newline sil
    fclose(fp);

    char input[50];
    printf("Mevcut sifreyi girin: ");
    scanf("%s", input);

    if(strcmp(input, currentPassword) != 0)
    {
        printf("Hatali sifre. Sifre degistirilemedi!\n");
        return;
    }

    char newPassword[50];
    printf("Yeni sifreyi girin: ");
    scanf("%s", newPassword);

    fp = fopen(PASSWORD_FILE, "w");
    if(fp == NULL)
    {
        printf("Yeni sifre yazilamadi.\n");
        return;
    }

    fprintf(fp, "%s\n", newPassword);
    fclose(fp);

    printf("Sifre basariyla degistirildi.\n");
}


/* ================ NOTE OPERATIONS ===============*/

void addNote(void)
{
    FILE *fp = fopen(FILENAME, "a"); // open the file as append mode / "r" --> read, "w" --> write, "a" --> append
    if(fp == NULL)
    {
        printf("Dosya acilamadi!\n");
        return;
    }

    // Zaman Damgası
    time_t now;
    time(&now);
    struct tm *t = localtime(&now);

    char note[MAX_NOTE_LENGTH];
    printf("Yeni notunuzu girin: ");
    getchar(); // önceki girilen newline'ı temizliyoruz.
    fgets(note, MAX_NOTE_LENGTH, stdin);


    fprintf(fp, "[%02d-%02d-%d %02d:%02d] %s", t->tm_mday, t->tm_mon + 1, t->tm_year + 1900, t->tm_hour, t->tm_min, note);
    fclose(fp);
    printf("Not zaman damgasi ile kaydedildi!\n\n");
}   

void viewNotes(void)
{
    FILE *fp = fopen(FILENAME, "r");
    if(fp == NULL)
    {
        printf("Dosya acilamadi!\n");
        return;
    }

    char line[MAX_NOTE_LENGTH];
    printf("\n--- Notlariniz ---\n");

    while(fgets(line, sizeof(line), fp)) 
    {
        printf("- %s", line);
    }
    
    printf("\n------------------\n\n");
    fclose(fp);
}

void searchNotes(void)
{
    FILE *fp = fopen(FILENAME, "r");
    if(fp == NULL)
    {
        printf("Dosya acilamadi!\n");
        return;
    }

    char query[100];
    char line[MAX_NOTE_LENGTH];
    int found = 0;

    printf("Aramak istediginiz kelimeyi girin: ");
    getchar(); // önceki girilen newline'ı temizliyoruz.
    fgets(query, sizeof(query), stdin);
    query[strcspn(query, "\n")] = '\0';

    printf("\n--- Arama Sonuclari ---\n");

    while (fgets(line, sizeof(line), fp))
    {
        if(strstr(line, query) != NULL)
        {
            printf("- %s", line);
            found = 1;
        }
    }

    if(!found)
    {
        printf("Hicbir not bulunamadi!\n");
    }

    printf("\n------------------\n\n");
    fclose(fp);
}

void deleteNote() 
{
    FILE *fp = fopen(FILENAME, "r");
    if(fp == NULL) 
    {
        printf("Not dosyasi bulunamadi.\n");
        return;
    }

    // Tüm notları oku ve ekrana numaralı yaz.
    char lines[100][MAX_NOTE_LENGTH];
    int count = 0;

    while (fgets(lines[count], MAX_NOTE_LENGTH, fp))
    {
        printf("%d. %s", count + 1, lines[count]);
        count++;
    }
    fclose(fp);

    if(count == 0)
    {
        printf("Silinecek not bulunamadi.\n\n");
    }

    // Kullanıcıdan silinecek satır numarasını alalım.
    int choice;
    printf("\nSilmek istediginiz not numarasini girin: ");
    scanf("%d", &choice);
    
    if(choice < 1 || choice > count)
    {
        printf("Gecersiz secim.\n\n");
        return;
    }

    // Yeni dosyaya yeniden yaz (seçilen hariç)
    FILE *fp2 = fopen("temp.txt", "w");
    if(fp2 == NULL)
    {
        printf("Gecici dosya olusturulamadi\n");
        return;
    }

    for(int i = 0; i < count; i++)
    {
        if( i != choice - 1)
        {
            fputs(lines[i], fp2);
        }
    }

    fclose(fp2);

    // temp.tx --> notes.txt
    remove(FILENAME);
    rename("temp.txt", FILENAME);

    printf("Not silindi.\n\n");
}

int main()
{   
    if(!checkPassword())
    {
        return 1; // Sifre yanlis oldugundan programdan cikiliyor.
    }    
    
    int choice;

    do
    {
        printf("=== Kisisel Not Defteri ===\n");
        printf("1. Not Ekle\n");
        printf("2. Notlari Goruntule\n");
        printf("3. Not Ara\n");
        printf("4. Not Sil\n");
        printf("5. Sifre Degistir\n");
        printf("%d. Cikis\n", EXIT_COMMAND);
        printf("Seciminiz: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addNote();
                break;
            
            case 2:
                viewNotes();
                break;
            
            case 3:
                searchNotes();
                break;

            case 4:
                deleteNote();
                break;
            
            case 5:
                changePassword();
                break;
            
            case EXIT_COMMAND:
                printf("Programdan cikiliyor...\n");
                break;
            
            default:
                printf("Gecersiz Secim!\n");
        }
    } while (choice != EXIT_COMMAND);
    

    return 0;
}