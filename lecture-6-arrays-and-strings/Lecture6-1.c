/*
Veri Yapısı
------------------
Mantıksal ilişki içindeki verilerin bellekte saklanmasına yönelik düzenlemelere veri yapısı denir. Veri yapıları bellekte belirli bir
düzen içinde tutulmuş verilere ulaşılabilmesine, bu veriler üzerinde bazı işlemlerin etkin bir biçimde yapılmasına olanak sağlar.


Veri Yapıları Türleri
------------------
1. Dizi (Array)
2. Yığın (Stack)
3. Kuyruk (Queue)
4. Bağlı Liste (Linked List)
5. Ağaç (Tree)
6. Graf (Graph)
7. Tablo (Table)
8. Yığmalı Tablo (Heap Table)
9. Sıralı Tablo (Sorted Table)
10. İkili Arama Ağacı (Binary Search Tree)
11. Kuyruk Tabanlı Tablo (Queue Table)
12. İkili Tablo (Binary Table)
...

Dizi (Array) Nedir?
---------------------
Bellekte bitişik bir biçimde bulunan, aynı türden nesnelerin oluşturduğu veri yapısına dizi (array) denir. Dizi veri yapsının en önemli özelliği,
mantıksal bir ilişki içindeki aynı türden verilerin bellekte bitişik (contigous) olarak tutulmasıdır. Bunun da uygulamalarda sağladığı fayda şudur:
Dizinin bir elemanına, elemanın konum bilgisiyle değişmez bir zamanda ulaşılabilir. Yani dizinni eleman sayısı ne olursa olsun, konumu bilinen birt elemeana ulaşım
zamanı aynıdır. Bu da bazı uygulamaların etkin bir şekilde gerçekleştirilmesini kolaylaştırır.

C dilinde dizi (array), aynı türden bir ya da daha fazla nesnenin bellekte dizi veri yapısı biçiminde tutulmasını sağlayan araçtır.
C'de bir dizinin tanımlanmasıyla birden fazla sayıda nesne tek bir deyimle tanımlanabilir. 10 elemana sahip bir dizi tanımlamak yerine, şüphesiz
isimleri farklı 10 ayrı nesne de tanımlanabilir. Ama 10 ayrı nesne tanımlandığında bu nesnelerin bellekte bitişik olarak yerleşmeleri güvence altına alınmış
birt özellik değildir. Oysa dizi tanımlanamasında, dizinni elemanı olan bütün nesnelerin bellekte bitişik olarak yer almamları güvence altına alınmış bir özelliktir.
Dizi de bir veri türü olduğuna göre, dizilerin de kullanılmalarından önce tanımlanmaları gerekir.

Dizi Tanımlama
---------------------

<tür> <dizi_adı> [<eleman_sayısı>];

Örnek:
int sayilar[10];
double a[20];
char path[80];

Tanımlamada yer alan, eleman sayısı belirten ifadenin bir tamsayı türünden değişmez (constant) ifadesi olması zorunludur. Bir başka deyişle derleyici bu ifadenin
değerini derleme zamanında elde edebilmelidir. 

int x = 100;
int a[x]; // Geçersiz
int b[5.]; // Geçersiz
int c[5+5]; // Geçerli

Dizi bildirimnlerinde eleman sayısını belirten ifade yerine sıklıkla macrolar kullanılır.

#define ARRAY_SIZE 10
int a[ARRAY_SIZE];

Dizi elemanlarına erişim
---------------------

Dizi elemanlarının her biri ayrı birer nesnedir. Dizi elemanlarına köşeli ayraç işleciyle [] ulaşılabilir. Köşeli ayraç işleci bir gösterici (pointer) işlecidir. 
Bu işleç "Göstericiler" konusunda ayrıntılı olarak incelenecektir.
Köşeli ayraç işlecinin terimi dizi ismidir. Aslında bu bir adres bilgisidir, çünkü bir dizi ismi işleme sokulduğunda işlem öncesi derleyeci tarafından otomatik
olarak dizinin ilk elemanınnı adresine dönüştürülür. Köşeli ayraç içinde diziin kaçıncı indisli elemanına ulaşılacağını gösteren bir tamsayı ifadesi olmalıdır.
C dlinde bir dizinin ilk elemanı, dizinin sıfır inidsli elemanıdır.

T bir tür bilgisi olmak üzere

T a[SIZE];

gibi bir dizinin ilk elemanı a[0] son elemanı ise a[SIZE-1]'dir.

- dizi[20] // dizi dizisinin 20 indisli yani 21. elemanı olan nesne.
- ave[0] // ave dizisinin 0 indisli yani 1. elemanı olan nesne.

Bir dizi tanımlaması ile karşılaşan derleyici, tanımlanan dizi için bellekte yer ayırır. Ayrılacak yer:

dizinin eleman sayısı * bir elemanın bellekte kapladığı yer 

kadar byte olur. Örneğin

int a[5];

gibi bir dizi tanımlaması derleyici a dizisi için bellekte 4 * 5 = 20 byte yer ayıracaktır. 

*/

#include <stdio.h>

// int main()
// {
//     int a[10], b = 3;
//     char c[10];

//     printf("a: %d\n", sizeof(a)); // 4 * 10 = 40
//     printf("b: %d\n", sizeof(b)); // 4
//     printf("c: %d\n", sizeof(c)); // 1 * 10 = 10

//     return 0;
// }

// İlk değer verme işlemi 3 şekilde ele alınabilir. 1. Local, 2. Static, 3. External

// int main()
// {
//     // 1.Local

//     int a[10];

//     for(int i = 0; i < 10; i++)
//     {
//         printf("%d ", a[i]); // a[0], a[1] .....
//     }
    
//     // Buradaki dizinin elemanlarının değerleri rastgele (random) sayılar ile dolduruluyor.
    
//     return 0;
// }

// int main()
// {
//     // 2.Static

//     static int a[10];

//     for(int i = 0; i < 10; i++)
//     {
//         printf("%d ", a[i]); // a[0], a[1] .....
//     }
    
//     // Buradaki dizinin elemanlarının değerleri 0 ile dolduruluyor.
    
//     return 0;
// }

// int a[10]; // extern

// int main()
// {
//     // 3.External

//     for(int i = 0; i < 10; i++)
//     {
//         printf("%d ", a[i]); // a[0], a[1] .....
//     }
    
//     return 0;
// }

// int main()
// {
//     int a[10] = {3, 2, 5, 1};

//     for(int i = 0; i < 10; i++)
//     {
//         printf("%d ", a[i]); // a[0], a[1] .....
//     }
    
//     return 0;
// }

// int main()
// {
//     int a[] = {3, 2, 5, 1};
//     int b[] = {0};

//     for(int i = 0; i < 4; i++)
//     {
//         printf("%d ", a[i]); // a[0], a[1] .....
//     }
    
//     return 0;
// }

// Example-22.c

// Given an array: a[10] = {3, 21, 5, 8, 5,11, 22,14,9,51}
// Flip the array to: 51, 9, 14, 22, 11, 5, 8, 5, 21, 3}

#include <stdio.h>

// int main()
// {
//     int a[10] = {3, 21, 5, 8, 5,11, 22,14,9,51};
//     int temp = 0;

//     for(int i = 0; i < 5; i++)
//     {
//         temp = a[i];
//         a[i] = a[10 - i - 1];
//         a[10 - i - 1] = temp;
//     }

//     for(int i = 0; i < 10; i++)
//     {
//         printf("%d ", a[i]);
//     }

//     return 0;
// }

// Example-23.c

// Given an array: a[10] = 21, 3, 5, 8, 5,11, 22,14,51,9}
// Sort the array in ascending order: 3, 5, 5, 8, 9, 11, 14, 21, 22, 51}

/* 
Bubble Sort (Baloncuk Sıralaması) 
--------------------------------------------

Baloncuk sıralaması, temel sıralama algoritmalarındna birsiidr. Dizinin her bir konumundaki elemanı, sırasıyla bir sonraki
konumdaki eleman ile karşılaştırılır. Dizinin küçükten büyuüğe soğru sıralanması istenirse, bu karşılaştırma esnasında mevcut elemanın
sonraki dizi elemanından büyük olup olmadığı kontrol edilir. Bu şartın sağlandığı sonucuna varılırsa iki eleman yer değiştirlir. Aksi durumda ise
herhangi bir yer değiştirme işlemi yapılmaz ve karşılaştırmaya bir sonraki konumdaki dizi elemanı ile devam edilir. Bu işlem dizinin son elemanına
ulaşıncaya kadar sürdürlür. Dizinin başından sonuna doğru yapılan bu karşılaştıma tamamlandığında algoritmanın bir adımı (iterasyonu) tamamlanmış olur.
Sonuç olarak dizinin en büyük elemanı konum olarak dizinin en sonuna yerleşmiş olacaktır. Bu algoritmal adımları n elemanlı bir dizi için n-1 defa
tekrarlandığında tamamen sıralı bir dizi elkde edilmiş olur. 

*/ 

// #include <stdio.h>

// int main()
// {
//     int a[10] = {21, 3, 5, 8, 5,11, 22,14,51,9};

//     int temp = 0;

//     for(int i = 0; i < 10; i++)
//     {
//         for(int j = 0; j < (10 - i - 1); j++)
//         {
//             if(a[j] > a[j + 1])
//             {
//                 temp = a[j];
//                 a[j] = a[j + 1];
//                 a[j + 1] = temp;
//             } // if
//         } // for(j)
//     } // for(i)

//     for(int i = 0; i < 10; i++)
//     {
//         printf("%d ", a[i]);
//     }

//     return 0;
// }

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

// Page Number: 33

*/

