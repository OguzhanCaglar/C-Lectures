#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define FILENAME            "notes.txt"
#define MAX_NOTE_LENGTH     256

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

int main()
{   
    int choice;

    do
    {
        printf("=== Kisisel Not Defteri ===\n");
        printf("1. Not Ekle\n");
        printf("2. Notlari Goruntule\n");
        printf("3. Not Ara\n");
        printf("4. Cikis\n");
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
                printf("Programdan cikiliyor...\n");
                break;
            
            default:
                printf("Gecersiz Secim!\n");
        }
    } while (choice != 3);
    

    return 0;
}