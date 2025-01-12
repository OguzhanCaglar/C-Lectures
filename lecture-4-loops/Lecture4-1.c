// Loop

/*
Döngüler, programlama dillerinde belirli bir işlemin tekrar tekrar yapılmasını sağlayan yapılardır. Döngüler, programlama
dillerinde belirli bir işlemin tekrar tekrar yapılmasını sağlayan yapılardır. 

Bir program parçasının yinelemeli olarak çalıştırılmasını sağlayan kontrol deyimlerine "döngü deyimi" (loop statement) denir. 
C dilinde 3 ayrı döngü deyimi vardır:
- while döngü deyimi
- do while döngü deyimi
- for döngü deyimi

Bunlardan en fazla kullanılanı, for döngü deyimidir. for döngü deyimi, yalnızca C dilinin değil, tüm programlama dillerinin 
en güçlü döngü yapısıdır. while ya da do while döngü deyimleri olmasa da, bu döngüler kullanılarak yazılan kodlar, 
for döngüsüyle yazılabilir. Ancak okunabilirlik açısından while ve do while döngülerinin tercih edildiği durumlar vardır. 

*/

// Loop: While Loop

/*
While, belirli bir koşul sağlandığı sürece döngü gövdesini çalıştıran bir döngü deyimidir. While döngü deyimi, döngü gövdesi
çalıştırılmadan önce kontrol ifadesini sınar. Eğer kontrol ifadesi doğruysa, döngü gövdesi çalıştırılır. Döngü gövdesi
çalıştırıldıktan sonra kontrol ifadesi tekrar sınanır. Eğer kontrol ifadesi doğruysa, döngü gövdesi tekrar çalıştırılır.
Bu işlem kontrol ifadesi yanlış olana kadar sürer.

while (koşul)
{
    deyim;
}

*/

// #include <stdio.h>

// int main()
// {
//     int i = 0;
//     while (i < 100) 
//     {
//         printf("%d ", i);
//         ++i;
//     }
//     return 0;
// } 

// Check Prime Number: Check whether an integer number if a prime number or not.
// Prime Number: number that is only dividable by 1 and itself.

#include <stdio.h>

int main()
{
    int i = 2, N = 177;
    int is_prime = 1;

    while(i < N)
    {
        if(N % i == 0)
        {
            is_prime = 0;
            printf("%d is dividable by %d\n", N, i);
        }
        i++;
    }

    if(is_prime == 1)
    {
        printf("%d is a prime number!\n", N);
    }
    else
    {
        printf("%d is not a prime number!\n", N);
    }

    return 0;
}

// Page Number: 19

