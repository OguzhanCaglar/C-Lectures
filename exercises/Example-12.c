// Kullanıcıdan pozitif sayılarak alarak bu sayıların toplamını hesaplayan bir program yazalım. Kullanıcı 0 girdiğinde döngü sona ersin.

#include <stdio.h>

int main()
{
    int sayi, toplam = 0;

    do {
        printf("Bir sayi giriniz (0 ile cikis): ");
        scanf("%d", &sayi);
        toplam += sayi;
    } while (sayi != 0);

    printf("Girilen sayilarin toplami: %d\n", toplam);
    
    return 0;
}