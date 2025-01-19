// Mükemmel Sayı Kontrolü: Bir mükemmel sayı, pozitif bölenlerinin toplamı kendisine eşit olan bir sayıdır (kendisi hariç). Örneğin 28, 1 + 2 + 4 + 7 + 14 = 28. 
// Kullanıcıdan bir sayı alın ve bu sayının mükemmel sayı olup olmadığını kontrol eden bir program yazın.

#include <stdio.h>

int main()
{
    int n, toplam = 0, i = 1;

    printf("Bir sayi girin: ");
    scanf("%d", &n);

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
        printf("%d mukemmel bir sayidir.\n", n);
    }
    else
    {
        printf("%d mukemmel bir sayi degildir.\n", n);
    }

    return 0;
}