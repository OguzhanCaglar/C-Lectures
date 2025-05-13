// Kullanıcının girdiği bir kelimeyi karakter dizisine atayan ve ekrana yazdıran bir program yazınız.

#include <stdio.h>

int main()
{
    char kelime[50];
    int i;

    printf("Kelime giriniz: ");
    scanf("%s", kelime); // Dizinin ismi dizinin ilk elemanının adresi olduuğndan biz burada yine de bir adres göndermiş oluyoruz. kelime = &kelime[0]
    printf("Girilen kelime: %s\n", kelime);

    i = 0;

    while (kelime[i] != '\0')
    {
        printf("%c", kelime[i]);
        i++; 
    }

    printf("\n");

    // for (i = 0; kelime[i] != '\0'; i++)
    // {
    //     printf("%c", kelime[i]);
    // }

    return 0;
}