// Negatif bir rakam yazılana kadar girilen rakamlardan kaçının tek kaçının çift sayı olduğunu bulan programı yazınız.

#include <stdio.h>

int main()
{
    int sayi, tek = 0, cift = 0;

    while (1) // sonsuz döngü
    {
        printf("Sayi giriniz: ");
        scanf("%d", &sayi);

        if(sayi < 0)
        {
            printf("Negatif sayi girdiniz. Program sonlandiriliyor.\n");
            break;
        }

        if(sayi % 2 == 0)
        {
            cift++;
        }
        else
        {
            tek++;
        }
    }

    printf("\nTek sayi = %d\nCift sayi = %d\n", tek, cift);
    

    return 0;
}