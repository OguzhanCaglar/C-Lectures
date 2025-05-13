/*
Girilen ve 0-1'lerden oluşan rakam bloğundaki 1 rakamlarından oluşan blokların uzunluklarını bulan programı yazınız

Örnek Çıktı:

Rakam blogunu (0 ya da 1) giriniz: 0 0 1 1 1 0 1 1 0 0 0 1 0 0 1 1 1 1 -1
                                         3      2        1        4
*/

#include <stdio.h>

int main()
{
    int dizi[100] = {0}, i, j, adet, rakam, uzunluk = 0;

    printf("Rakam blogunu (0 ya da 1) giriniz: ");

    while(rakam != -1)
    {
        scanf("%d", &rakam);
        if(rakam > 1)
        {
            continue;
        }
        dizi[adet] = rakam;
        adet++;
    }

    for(i = 0; i < adet; i++)
    {
        uzunluk = 0;
        
        for(j = i; dizi[j] == 1; j++)
        {
            // 1'leri işliyoruz
            uzunluk++;
        }

        i = j;

        if (uzunluk > 0)
        {
            printf("%d ", uzunluk);
        }
        
    }

    return 0;
}