// Kullanıcıdan bir pozitif sayı alın ve bu sayıya göre ters üçgen yazdıran bir program yazın.

// 5 
// *****
// ****
// ***
// **
// *

#include <stdio.h>

int main()
{
    int n;

    printf("Bir sayi girin: ");
    scanf("%d", &n);

    for(int i = n; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}