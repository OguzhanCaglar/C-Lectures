// Dörtgen olarak ekrana yıldız çizdiren programı yazınız.

/*
     *
    ***
   *****
  ******* 
   *****
    ***
     *
*/

// ilk satırda 3 boşluk 1 yıldız
// ikinci satırda 2 boşluk 3 yıldız
// üçüncü satırda 1 boşluk 5 yıldız
// dördüncü satırda 0 boşluk 7 yıldız

// Bir döngü olmalı ki boşlukları yazabilsin. Bir döngü olmalı ki yıldızları yazabilsin. Bir döngü olamlı ki satırları yazabilecek.

// 1) Loop print all lines
// 2) Loop print blank spaces
// 3) Loop print stars

#include <stdio.h>

int main()
{
    int n = 5, i = 0, j = 0;
    int ns = 1, nb = n - 1;

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < nb; j++)
        {
            printf(" ");
        }
        for(j = 0; j < ns; j++)
        {
            printf("*");
        }
        ns += 2;
        nb--;
        printf("\n");
    }
    nb += 2;
    ns -= 4;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < nb; j++)
        {
            printf(" ");
        }
        for(j = 0; j < ns; j++)
        {
            printf("*");
        }
        ns -= 2;
        nb++;
        printf("\n");
    }

    return 0;
}