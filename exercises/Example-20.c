// Mükemmel Sayı problemini fonksiyon kullanarak çözün.


#include <stdio.h>

int isPerfect(int n)
{
    int toplam = 0, i = 1;

    while(i < n)
    {
        if(n % i == 0)
        {
            toplam += i;
        }
        i++;
    }

    if(toplam == n)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int n;
    int sonuc;

    printf("Bir sayi girin: ");
    scanf("%d", &n);

    sonuc = isPerfect(n);

    if(sonuc)
    {
        printf("%d mukemmel bir sayidir.\n", n);
    }
    else
    {
        printf("%d mukemmel bir sayi degildir.\n", n);
    }

    return 0;
}