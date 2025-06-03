#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "password.h"

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