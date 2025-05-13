// Girilen bir kelimedeki küçük ve büyük harf sayılarını yazdıran program

/*
Çıktı:

Girilen Kelime: Merhaba

Küçük Harf Sayısı: 6
Büyük Harf Sayısı: 1
*/

#include <stdio.h>

int main()
{
    char kelime[100];
    int buyukHarfSayisi = 0;
    int kucukHarfSayisi = 0;
    int i = 0;

    printf("Kelimeyi Giriniz: ");
    scanf("%s", kelime);

    while (kelime[i] != '\0')
    {
        if(kelime[i] >= 65 && kelime[i] <= 90)
        {
            buyukHarfSayisi++;
        }
        else if(kelime[i] >= 97 && kelime[i] <= 122)
        {
            kucukHarfSayisi++;
        }

        i++;
    }

    printf("Kucuk harf sayisi = %d\n", kucukHarfSayisi);
    printf("Buyuk harf sayisi = %d\n", buyukHarfSayisi);
    

    return 0;
}



