// Girilen bir kelimedeki büyük harfleri küçük harfe, küçük harfleri ise büyük harfe dönüştüren programı yazınız.

#include <stdio.h>

int main()
{
    char kelime[100];
    int i = 0;

    printf("Kelimeyi giriniz: ");
    scanf("%s", kelime);

    while (kelime[i] != '\0')
    {
        if(kelime[i] >= 65 && kelime[i] <= 90)
        {
            kelime[i] += 32; // o anki harf küçük harfe dönüştürülüyor.
        }
        else 
        {
            kelime[i] -= 32; // o anki harf büyük harfe dönüştürülüyor.
        }

        i++;
    }

    printf("Kelimenin yeni hali: %s\n", kelime);
    

    return 0;
}