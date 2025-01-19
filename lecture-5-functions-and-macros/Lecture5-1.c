// C'de alt programlara işlev (function) denir. 

/* 
Programı İşlevlere Bölerek Yazmanın Faydaları:

1) Programın kaynak kodu küçükür. Böylece oluşturulması hedeflenen çalışabilir dosya da (.exe) küçülür.
2) Kaynak dosyanın okunabilirliği artar.
3) Belirli kod parçalarının programın farklı yerlerinde yinelenmesi, programda yapılacak olası bir değişiklliğin maliyetini arttırır. Programın farklı yerlerinde,
kodun kullanıldığı yere bağlı olarak değişiklikler yapmak gerekir. Kaynak dosyalarda böyle değişiklikler yapmak hem zaman alıcı hem de rsiklidir. Oysa artık
kod parçaları fonksiyonlar şeklinde paketlendiğinde yalnızca fonksiyonlarda değişiklik yapılmasıyla, istenen değişiklik gerçekleştirilmiş olur.
4) Programda hata arama daha kolay gerçekleşir.

Bir işlev (fonksiyon) başlıca iki farklı amaçla kullanılabilir:
1) İşlev, çalışması süresince belli işlemleri yaparak belirli amaçları gerçekleştirir.
2) İşlev çalışması sonunda üreteci bir değeri kendisini çağıran işleve gönderebilir.

İşlevlerin tanımlanması ve kullanılması:
1) İşlev tanımlanırken, işlevin adı, işlevin dönüş türü, işlevin parametreleri ve işlevin gövdesi belirtilir.
2) İşlevin adı, işlevin dönüş türü ve işlevin parametreleri işlevin prototipi veya bildirimi (declaration) olarak adlandırılır.
3) İşlevin gövdesi, işlevin prototipinden sonra gelir ve işlevin ne yapacağını belirtir. (definition)

[Geri dönüş değerinin türü] <işlev ismi> ([parametreler])
{
    //  İşlevin gövdesi
} 


*/



#include <stdio.h>

// int main()
// {
//     int a = 5, b = 8;
//     int temp;
    
//     printf("a = %d, b = %d\n", a, b);

//     temp = a;
//     a = b;
//     b = temp;

//     printf("a = %d, b = %d\n", a, b);
    
//     return 0;
// }

// Yanlis

// void swap(int sayi1, int sayi2)
// {
//     int temp;
//     temp = sayi1;
//     sayi1 = sayi2;
//     sayi2 = temp;

//     return;
// }

// int main()
// {
//     int a = 5, b = 8;

//     printf("a = %d, b = %d\n", a, b);

//     swap(a, b);

//     printf("a = %d, b = %d\n", a, b);
    
    
//     return 0;
// }

// Perfect Number:

// int isPerfect(int n)
// {
//     int toplam = 0, i = 1;

//     while(i < n)
//     {
//         if(n % i == 0)
//         {
//             toplam += i;
//         }
//         i++;
//     }

//     if(toplam == n)
//     {
//         return 1;
//     }
//     else
//     {
//         return 0;
//     }
// }

// int main()
// {
//     int n;
//     int sonuc;

//     printf("Bir sayi girin: ");
//     scanf("%d", &n);

//     sonuc = isPerfect(n);

//     if(sonuc)
//     {
//         printf("%d mukemmel bir sayidir.\n", n);
//     }
//     else
//     {
//         printf("%d mukemmel bir sayi degildir.\n", n);
//     }

//     return 0;
// }

// Recursive Fonksiyonlar:

/*
Bir işlev başka bir işlevi çağırdığı gibi kendisini de çağırabilir. Bu tür işlevlere özyinelemeli (recursive) işlevler denir.
Algoritmalar bu özelliğe göre üç ayrı gruba ayrılabilir.

1- Özyinelemeli olmayan işlevlerle yazılabilen algoritmalar
2- Hem özyinelemeli hem de özyinelemeli olmayan işlevlerle yazılabilen algoritmalar
3- Yalnızca özyinelemeli işlevlerle yazılabilen algoritmalar

Özyinelemeli işlevlerle yazılabilen tipik algoritmalar:

- Dizin ağacını dolaşan algoritmalar
- Parsing algoritmaları
- Ağaç algoritmaları
- Özel amaçlı pek çok algoritma

Bir algoritmanın kendi kendisini çağıran işlevlere yazılıp yazılamayacağının ölçütü nedir? Algoritma ilerlendiğinde yine ilk baştakine benzer bir durumla
karşılaşılıyorsa büyük olasılıkla bu algoritma kendi kendini çağıran bir işlevle yazılabilir.

Bir işlev kendini çağırdığında işlevin bütün yerel değişkenleri yeniden yaratılır. Aynı durum işlevin parametreleri için de geçerlidir. Bu yüzden
özyinelemeli işlevler genellikle yığın alanını (stack) diğer işlevlerle karılşatırıldığında daha çok kullanır. 

*/

// int factorial(int n)
// {
//     if(n < 0)
//     {
//         return 0;
//     }
//     else if (n == 1 || n == 0)
//     {
//         return 1;
//     }
//     else
//     {
//         return n * factorial(n - 1);
//     }
// }

// int main()
// {
//     int n = 5, result = 0;

//     result = factorial(n);

//     printf("%d! = %d\n", n, result);

//     return 0;
// }

// Hanoi Tower Problemi

// void hanoi(int n, char source, char target, char auxiliary)
// {
//     // Temel durum: Eğer yalnızca 1 disk varsa doğrudan hedefe taşı
//     if(n == 1)
//     {
//         printf("Diski %c'den %c'ye tasi\n", source, target);
//         return;
//     }

//     // Adım 1: n-1 diski kaynaktan yardımcıya taşı.
//     hanoi(n-1, source, auxiliary, target);

//     // Adım 2: En büyük diski kaynaktan hedefe taşı.
//     printf("Diski %c'den %c'ye tasi\n", source, target);

//     // Adım 3: n-1 diski yardımcıdan hedefe taşı:
//     hanoi(n - 1, auxiliary, target, source);
// }

// int main()
// {
//     int diskSayisi;

//     printf("Disk sayisini girin: ");
//     scanf("%d", &diskSayisi);

//     printf("Hanoi Kuleleri Cozumu:\n");
//     hanoi(diskSayisi, 'A', 'B', 'C');

//     return 0;
// }

// #include <stdio.h>
// #include "mylib.h"

// int mypow(int base, int exp)
// {
//     int r = 1;

//     if(exp == 0)
//     {
//         return 1;
//     }

//     for(int i = 1; i <= exp; i++)
//     {
//         r *= base; // r = r * base;
//     }

//     return r;
// }

// int main()
// {
//     int result = mypow(2, 3);

//     printf("2^3 = %d\n", result);

//     return 0;
// }

/*
Nesnelerin C dili açısından çok önem taşıyan üç özelliği daha söz konusudur. Bunlar bilinirlik alanı (scope), ömür (storage duration) ve bağlantı (linkage) özelliğidir.

Bilinirlik Alanı
Bilinirlik alanı (scope), bir ismin tanınabildiği program aralığıdır. Derleyiciye bildirilen
isimler, derleyici tarafından her yerde bilinmez. Her isim derleyici tarafından ancak "o
ismin bilinirlik alanı" içinde tanınabilir. Bilinirlik alanı doğrudan kaynak kod ile ilgili bir
kavramdır, dolayısıyla derleme zamanına ilişkindir. C dilinde derleyici, bildirimleri yapılan
değişkenlere kaynak kodun ancak belirli bölümlerinde ulaşılabilir. Yani bir değişkenin
tanımlanması, o değişkene kaynak dosyanın her yerinden ulaşılabilmesi anlamına gelmez.
Bilinirlik alanları C standartları tarafından 4 ayrı grupta toplanmıştır:
i. Dosya Bilinirlik Alanı (File scope) : Bir ismin bildirildikten sonra tüm kaynak dosya
içinde, yani tanımlanan tüm işlevlerin hepsinin içinde bilinmesidir.
ii. Blok Bilinirlik Alanı (Block scope): Bir ismin bildirildikten sonra yalnızca bir blok içinde,
bilinmesidir.
iii. İşlev Bilinirlik Alanı (Function Scope): Bir ismin, bildirildikten sonra yalnızca bir blok
içinde bilinmesidir. Yalnızca goto etiketlerini kapsayan özel bir tanımdır. Bu bilinirlik
alanına "goto deyimi" konusunda değinilecek.
iv. İşlev Bildirimi Bilinirlik Alanı (Function Prototype Scope): İşlev bildirimlerindeki, işlev
parametre ayracı içinde kullanılan isimlerin tanınabilirliğini kapsayan bir tanımdır. Bu
bilinirlik alanına "İşlev Bildirimleri" konusunda değinilecek.
Bir kaynak dosya içinde tanımlanan değişkenler, bilinirlik alanlarına göre "yerel" ve
"global" olmak üzere ikiye ayrılabilir:
Yerel Değişkenler
Blokların içinde ya da işlevlerin parametre ayraçları içinde tanımlanan değişkenlere, yerel
değişkenler (local variables) denir. C dilinde blokların içinde tanımlanan değişkenlerin
tanımlama işlemlerinin, bloğun en başında yapılması gerektiğini biliyorsunuz. Yerel
değişkenler, blok içinde tanımlanan değişkenlerdir, bir işlevin ana bloğu içinde ya da içsel
bir blok içinde bildirilmiş olabilirler.
Yerel değişkenlerin bilinirlik alanı, blok bilinirlik alanıdır. Yani yerel değişkenlere yalnızca
tanımlandıkları blok içinde ulaşılabilir. Tanımlandıkları bloğun daha dışındaki bir blok
içinde bu değişkenlere erişilemez. 

Global Değişkenler
C dilinde blokların dışında da değişkenlerin tanımlanabileceğini biliyorsunuz. Blokların
dışında tanımlanan değişkenler "global değişkenler" (global variables) olarak
isimlendirilir.
Derleme işleminin bir yönü vardır. Bu yön kaynak kod içinde yukarıdan aşağıya doğrudur.
Bir değişken yerel de olsa global de olsa, tanımlaması yapılmadan önce kullanılması
geçersizdir. Global değişkenler tanımlandıkları noktadan sonra kaynak dosyanın sonuna
kadar her yerde bilinir

*/

// Page Number: 51