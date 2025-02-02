/*
Çok Boyutlu Diziler
----------------------------

C dilinde iki yada daha çok boyuta sahip diziler tanımlanabilir:

int a[5][10][20]; --> 3 boyutlu bir dizi

int m[5][10]; --> 2 boyutlu bir dizi

Uygulamalarda daha çok kullanılan 2 boyutlu dizilerdir. 2 boyutlu diziler matris olarak da isimlendirilir.

Matrisler
------------------------------
C'de iki boyutlu bir dizi aslında belirli bir boyuttaki tek boyutlu dizilerin dizi olarak ele alınır.

int a[5][10];

a dizisi her elemanı 10 elemanlı int türden bir dizi olan 5 elemanlı bir dizidir. Yani a dizsinin gerçek boyutu 5'tir. İkinci köşeli ayraç içinde
yer alan 10 ifadesi a dizisinin elemanları olan dizilerin boyutudur. 

Bir dizi tüm diziler gibi bellekte bitişik bir blok halinde bulunur. Yani derleyici böyle bir dizi için bellekte 50 * sizeof(int) byte büyüklüğünde 
bir blok ayarlar (50 * 4 = 200)

Yukraıdaki dizide yer alan toplam 50 tane int türden nesnenin her birine nasıl ulaşılabilir?
Bunun için köşeli ayraç işleci dizi ismiyle birlikte 2 kez kullanılabilir.

a[i][j] // a dizisinin i indisli elemanının j indisli elemanı

- - - - - - - - - -
- - - - - - - - - -
- - - - - - - - - -
- - - - - - - - - -
- - - - - - - - - -

*/

// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>

// #define ROW     5
// #define COL     10

// int main()
// {
//     int a[ROW][COL];
//     int i, j;

//     srand(time(0)); // Rastgele sayı üretmek için kullanılır.

//     for(i = 0; i < ROW; ++i)
//     {
//         for(j = 0; j < COL; ++j)
//         {
//             a[i][j] = rand() % 10; // 0 - 99 arasında rastgele sayı üretir.
//         }
//     }

//     for(i = 0; i < ROW; ++i)
//     {
//         for(j = 0; j < COL; ++j)
//         {
//             printf("%d ", a[i][j]);
//         }
//         printf("\n");
//     }

//     return 0;
// }

/*
a[0] -> bu dizilerin ilkine, a[4] bu dizilerden sonuncusuna karşılık gelir.

a[0][0] -> 1. dizinin 1. elemanı
a[0][5] -> 1. dizinin 6. elemanı

---------------------------------------------------------------------------------------

STRING (KARAKTER DİZİLERİ, DIZGELER)

Karakter dizileri, char türden dizilerdir. Karakter dizinlerinni bazı ek özellikleri dışında diğer dizi türlerinden bir farkı yoktur. char türden diziler
daha çok içlerinde yazı tutmak için tanımlanır:asm

char str[100];

Bütün elemanları char türden olan 100 elemanlı bir dizidir. char türden bir dizi içinde bir yazı tutmak, dizinni her bir elemanına sırayla yazının bir karakterinin
sıra numrasıın atamak anlamına gelir. Yukarıdaki tanımlanan dizi içinde "Ali" yazısı tutulmak istensin:

str[0] = 'A';
str[1] = 'l';
str[2] = 'i';

Dizi 100 karakterlik olmasına karşın dizi içinde 100 karakterden daha kısa olan yazılar da tutulabilir. Peki dizi içinde saklanan yazıya nasıl erişilebilir?
Yazının uzunluk bilgisi bilnimiyor. Örneğin yazı ekrana yazdırılmak istendiğinde, int türden diziler içni daha önce yazılan bir döngü kulalnaım:

for (k = 0; k < 100; ++k)
{
    // printf("%c", str[k]);
    putchar(str[k]);
}

Böyle bir döngü ile yalnızca Ali yazısı ekrana yazdırılmaz, dizinin diğer 97 elemanınn da görntüleri yani çöp değerler ekrana yazdırılır.

C dilinde karakterler üzerinde işlemlerin hızlı ve etkin bir biçimde yapılabilmesi için "sonlandırıcı karakter (null character)" kavramından faydalalnılır.
Sonlandırıcı karakter, ASCII tablosnunu ya da sistemde kullanılan karakter setinin sınır numralaı ('\0') karakteridir. Dolayısıyla sayısal değer olarak
0 sayısına eşittir. '0' karakterinni ASCII karakter setindeki kod numarası 48'dir. Dolayısıyla tamsayı olarak değeri 48'dir. Oysa '\0' karakterinin
ASCII sıra numarası 0'dır. Doalyısıyla tam sayı olarak değeri 0'dır. 

#include <stdio.h>

int main()
{
    printf("%d\n", '0');
    printf("%d\n", '\0');

    return 0;
}

Output:

48
0


char türden dizilere ilk değer verme işlemi (initializing)

char name[6] = {'D', 'e', 'm', 'i', 'r', '\0'};
char name[4] = {'D', 'e', 'm', 'i', 'r'}; // Geçersiz
char name[3] = {'A', 'l', 'i'}; // Geçersiz --> C de geçerli C++'da geçersiz.

C dilinde iki tırnak içindeki karaktterlere dizge ifacesi (string literal) ya da kısaca dizge (string) denir.
"Oğuzhan Çağlar"
"x = %d\n"
"lütfen bir sayı giriniz: "
ifadelerinni her biri dizgedir.

strcpy İşlevi
-----------------

Standart bir C işlevidir. İşlevin ismi olan strcpy, "string" ve "copy" sözcüklerinin birleşiminden oluşmuştur. 

char *strcpy(char *destination, const char *source);

#include <stdio.h>
#include <string.h>

int main()
{
    char dest[100] = "C ogreniyoruz!";
    char source[100];

    printf("Kopyalanacak yaziyi girin: ");
    gets(source);
    printf("Kopyalama yapilmadan onceki yazi: %s\n", dest);
    strcpy(dest, source);
    printf("Kopyalama yapildiktan sonraki yazi: %s\n", dest);

    return 0;
}

strcmp işlevi
-----------------

Standart bir C işlevidir. İşlevin ismi string compare sözcüklerinden gelir. İşlev iki karakter dizisini kaşrılaştırmakta kullanılır. Karşılaştırma
iki karakter dizisi içindeki yazınını kullanılan karakter seti tablosun gözönünde bulundurularak, öncelik ya da eşitlik durumunun soruglanmasıdır.

int strcmp(const char *s1, const char *s2);

İşlevin geri dönüş değeri,
birinci yazı ikinci yazıdan daha büyükse pozitif bir değerdir.
birinzi yazı ikinci yazıdan daha küçükse negatif bir değerdir.
birinzi yazı ile ikinci yazı birbirine eşit ise 0 değeridir.

#include <stdio.h>
#include <string.h>

int main()
{
    char s[20];
    char password[] = "beyaz don";

    printf("Parola giriniz: ");
    gets(s);

    if(strcmp(s, password) == 0)
    {
        printf("Parola dogru!\n");
    }
    else
    {
        printf("Parola yanlis!\n");
    }

    return 0;
}

strlen işlevi
--------------------

Standart bir C işlevidir. İşlevin ismi string length sözcüklerinden gelir. İşlev bir karakter dizisinin uzunluğunu döndürür.

size_t strlen(const char *str);

#include <stdio.h>
#include <string.h> 

int main()
{
    char s[100];

    printf("Bir yazi girin: ");
    gets(s);
    printf("%s yazisinin uzunlugu: %d\n", s, strlen(s));

    return 0;
}

strcat işlevi
--------------------------

Standart bir C işlevidir. İşlevin ismi string concatenate sözcüklerinden gelir. İşlev iki karakter dizisini birleştirmek için kullanılır.

char *strcat(char *destination, const char *source);

#include <stdio.h>
#include <string.h>

int main()
{
    char s1[100], s2[100];

    printf("Sonuna ekleme yapilacak yaziyi girin: ");
    gets(s1);

    printf("Girdiginiz yazinin uzunlugu = %d\n", strlen(s1));
    printf("Eklemek istediginiz yaziyi girin: ");
    gets(s2);

    printf("Eklenecek yazinin uzunlugu = %d\n", strlen(s2));
    strcat(s1, s2);
    printf("Ekleme yapildiktan sonra 1. yazi: ");
    puts(s1);

    printf("Ekleme yapildiktan sonra yazinin uzunlugu = %d\n", strlen(s1));


    return 0;
}

ODEV
-----

Diger fonksiyonlar: strncpy, strncat, strncmp, strset, strrev, strupr, strlwr bunların nasıl kullanıldığına dair örnekler yapılacaktır.

*/




