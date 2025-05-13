// Girilen kelimenin harflerinden oluşan bir dik üçgen figürü oluşturan programı yazınız.

/*
Girilen Kelime: ahmet

a
h h
m m m
e e e e
t t t t t

*/

#include <stdio.h>

int main()
{
    char kelime[100];
    int i, j, uzunluk;

    printf("Kelime giriniz: ");
    scanf("%s", kelime);

    for(uzunluk = 0; kelime[uzunluk] != '\0'; uzunluk++);

    for(i = 0; i < uzunluk; i++)
    {
        printf("\n");

        for (j = 0; j <= i; j++)
        {
            printf("%c ", kelime[i]);
        }
    }

    return 0;
}