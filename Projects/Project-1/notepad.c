#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "notepad.h"

const char *categories[] = {"kisisel", "is", "okul"};

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

    const char *category;
    int selection;

    printf("Kategori Secin:\n");
    for(int i = 0; i < CATEGORY_COUNT; i++)
    {
        printf("%d. %s\n", i + 1, categories[i]);
    }
    printf("Seciminiz: ");
    scanf("%d", &selection);

    if(selection < 1 || selection > CATEGORY_COUNT)
    {
        printf("Gecersiz kategori secimi!\n\n");
        fclose(fp);
        return;
    }

    category = categories[selection - 1];

    char note[MAX_NOTE_LENGTH];    
    getchar();
    printf("Yeni notunuzu girin: ");
    fgets(note, MAX_NOTE_LENGTH, stdin);
    note[strcspn(note, "\n")] = '\0';


    fprintf(fp, "[%s] [%02d-%02d-%d %02d:%02d] %s\n", category, t->tm_mday, t->tm_mon + 1, t->tm_year + 1900, t->tm_hour, t->tm_min, note);
    fclose(fp);
    printf("Not zaman damgasi ve kategori ile kaydedildi!\n\n");
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

void viewNotesByCategory(void)
{
    int selection;
    char line[MAX_NOTE_LENGTH];
    int found = 0;

    FILE *fp = fopen(FILENAME, "r");
    if(fp == NULL)
    {
        printf("Not dosyasi bulunamadi!\n");
        return;
    }

    printf("Kategori Secin:\n");
    for(int i = 0; i < CATEGORY_COUNT; i++)
    {
        printf("%d. %s\n", i + 1, categories[i]);
    }
    printf("Seciminiz: ");
    scanf("%d", &selection);

    if(selection < 1 || selection > CATEGORY_COUNT)
    {
        printf("Gecersiz kategori secimi!\n\n");
        fclose(fp);
        return;
    }

    const char *category = categories[selection - 1];

    printf("\n-- [%s] Kategorisindeki Notlar --\n", category);

    while(fgets(line, sizeof(line), fp))
    {
        if(strstr(line, category) == line + 1)
        {
            printf("- %s", line);
            found = 1;
        }
    }

    if(!found)
    {
        printf("Bu kategoriye ait not bulunamadi.\n");
    }

    printf("\n------------------------------------------\n\n");
    fclose(fp);
}