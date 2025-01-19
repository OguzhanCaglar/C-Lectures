// Kullanıcıdan bir sayı alın ve bu sayıya kadar olan fibonacci dizisini ekrana yazdıran bir program yazın.

// 0 1 1 2 3 5 8 13 21 34 55 89 144 ...

#include <stdio.h>

int main()
{   
    int n, t1 = 0, t2 = 1, nextTerm;

    printf("Fibonacci dizisinin eleman sayisini giriniz: ");
    scanf("%d", &n);

    printf("Fibonacci dizisi: %d, %d", t1, t2);

    for (int i = 3; i <= n; i++)
    {
        nextTerm = t1 + t2;
        printf(", %d", nextTerm);
        t1 = t2;
        t2 = nextTerm;
    }
    printf("\n");

    return 0;
}