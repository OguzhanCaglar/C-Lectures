// Girilen Bir Kelimenin Uzunluğunu bulan ve tersten yazdıran programı yazınız.

#include <stdio.h>

int main()
{
    char kelime[100];
    int i, uzunluk = 0;

    printf("Kelime giriniz: ");
    scanf("%s", kelime); // 'D''e''m''i''r''\0'

    while (kelime[uzunluk] != '\0')
    {
        uzunluk++;
    }

    printf("Kelimenin uzunlugu: %d\n", uzunluk);

    printf("Kelimenin Tersi: ");

    for (i = uzunluk - 1; i >= 0; i--)
    {
        printf("%c", kelime[i]);
    }
    

    return 0;
}