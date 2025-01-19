// Kullanıcıdan bir sayı alın ve bu sayının rakamlarının toplamını hesaplayan bir program yazın.

// 125 -> 1 + 2 + 5 = 8 => 125 % 10 = 5, 125 / 10 = 12, 12 % 10 = 2, 12 / 10 = 1, 1 % 10 = 1, 1 / 10 = 0

#include <stdio.h>

int main()
{
    int sayi, toplam = 0, kalan;

    printf("Bir sayi girin: ");
    scanf("%d", &sayi);

    do {
        kalan = sayi % 10; // son rakamı al
        toplam += kalan; // toplama ekle
        sayi /= 10; // son rakamı at
    } while (sayi > 0);

    printf("Rakamlarin toplami: %d\n", toplam);
    
    return 0;
}