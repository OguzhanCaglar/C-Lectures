// Kullanıcıdan bir sayı alın ve bu sayının faktöriyelini hesaplayarak ekrana yazdıran bir program yazın.

#include <stdio.h>

int main()
{
    int n, faktoriyel = 1;

    printf("Bir sayi giriniz: ");
    scanf("%d", &n); // n! = n * (n-1) * (n-2) * ... * 1 => 5! = 5 * 4 * 3 * 2 * 1

    for (int i = 1; i <= n; i++)
    {
        faktoriyel *= i; // faktoriyel = faktoriyel * i;
    }
    
    printf("%d! = %d\n", n, faktoriyel);
    return 0;   
}