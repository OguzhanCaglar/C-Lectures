/*
Girilen ve en az iki harften oluşan bir kelimenin peş peşe iki harfi aynı ise o kelimeye vurgulu kelime denir. Bu varsayıma göre;
girilen bir kelimenin vurgulu kelime olup olmadığını bulan C programını yazınız:

Örnek Çıktı:
Kelime giriniz: KEZZAP
Vurgulu Kelime

Kelime giriniz: KEDİ
Vurgulu Kelime Değildir.

*/

#include <stdio.h>

int main()
{
    char kelime[100];
    int vurgulu = 0;

    printf("Kelimenizi giriniz: ");
    scanf("%s", kelime);

    for (int i = 0; i < kelime[i + 1] != '\0'; i++)
    {
        if(kelime[i] == kelime[i + 1])
        {
            vurgulu = 1;
        } 
    }

    if(vurgulu == 1)
    {
        printf("Vurgulu Kelime\n");
    }
    else
    {
        printf("Vurgulu Kelime Degildir.\n");
    }
    
    
    return 0;
}