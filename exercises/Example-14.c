// Kullanıcıdan bir sayı alın (negatif bir sayı girildiğinde giriş sona ersin) ve tek ve çift sayıları ayrı ayrı listeleyen bir program yazın.

#include <stdio.h>

int main()
{
    int sayi;

    printf("Sayilari girin (negatif bir sayi ile cikis): ");

    while (1)
    {
        scanf("%d", &sayi);

        if (sayi < 0)
        {
            break;
        }

        if (sayi % 2 == 0)
        {
            printf("%d cift bir sayidir.\n", sayi);
        }
        else
        {
            printf("%d tek bir sayidir.\n", sayi);
        }
    }
    
    return 0;
}