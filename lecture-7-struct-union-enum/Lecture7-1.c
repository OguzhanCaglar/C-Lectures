// Hatırlatma:

/*
Dizi (array), aynı tipteki verilerin tek bir değişken altında tutulmasını sağlayan veri yapısıdr. Sabit bir değere sahip olan diziin uzunluğu,
dizi oluşturulurken belirlenir. Bir dizide bulunan verilerin her biri, o dizinni bi relemanı olarak adlandırılı. Dizinin elemanlarına erişim indis (index)
adı verilen sayısal değerler aracılığıyla sağlanır. İndislerin numaralnadırılması 0 ile başlar, dizinin uzunluğunun 1 eksiğine kadar ardışık olarak
devam eder. 

<dizi_tipi> <dizi_adı>[<eleman_sayısı>];

int tamSayiDizisi[10]; // 10 elemanlı bir tam sayı dizisi tanımlanmıştır.
char karakterDizisi[20]; // 20 elemanlı bir karakter dizisi tanımlanmıştır.

Bir diziyi veri tipi, isim, kapasite belirterek tanımladığımızda bilgisayar hafızasında dizi için bir yer ayırılır, fakat dizi elemanlarına bir değer ataması
yapılmaz. Dizilere değer atamak için dizi tanımlaması ile birlikte veya tnımlamadan sonra kodlanan çeşitli komutlar vardır. Dizinni elemanları üzerinde
gezinecek döngüler aracılığıyla dizi elemanları sıfırlanabilir. Bir veri kaynağından (kullanıcı, metin dosyası, veri tabanı vb.) alınan değerler dizinin
elemanlarına atanabilir.

*/

// Örnek: Döngü kullanımı ile dizi elemanlarının sıfırlanması

// #include <stdio.h>

// int main()
// {
//     int dizi[6];

//     for (int i = 0; i < 6; i++)
//     {
//         dizi[i] = 0;
//         printf("dizi[%d] = %d\n", i, dizi[i]);
//     }
    
//     return 0;
// }

// ------------------------------------------------------------------------------------------------------------------------

/*
STRUCT, UNION, ENUM
--------------------

STRUCT: Yapılar (structures) programcının birden fazal nesne yaratmasına izin veren bir araçtır. Yapıların kullanılmasıyla bellekte birbirini izleyecek
şekilde yer alan birden fazla nesne yaratılabilir. Bellekte bitişik olarak yer alan nesnelerin dizi tanımlamalarıyla da yartılabilecğini biliyoruz. Ancak yapıların
dizilerden bazı farklılıkları vardır. Diziler aynı türden nesneleri için de tutabilirken, yapılar farklı ytürden nesneleri tutabilir. Yapıların kullanılmasının ana
nedeni budur. Çoğu zaman, türleri farklı bir takımk nesneler, mantıksal olarak bir bütün oluyşturabilir. İsim, yaş, cinsiyet, departman, ücret, öğrenim durumu gibi
bilgileri farklı türden nesneler içinde saklanabilir. Bunlarıun tamamı bir işyerinde çalışan bir kişiye ait bilgiler olabilir. Aralarında mantıksal ilişki olan farklı türden
veriler yapılar içinde saklanabilir.

int türden 10 elemanlı bir dizi tanımlamak için:

int dizi[10];

Kullanılan sistemde int türünü 4 byte yer kapladığını düşünürsek bu dizi için bellekte 40 byte'lık bir blok ayrılır. Programcı bu dizinin elemanlarına köşeli ayraç işleci
ile ulaşarak, eleman olan nesneler üzerinde doğrudan işlemler yapabilir. Ancak dizinin tamamı bir nesne olarak kullanılamaz! Yani C dili bir dizinin tamamını bir nesne olarak
görmez. Yapılarda durum biraz daha farklıdır. Yapı kullanılmasıyla da birden fazal nesne için ardışık bir blok ayrılır. Ancak bu kez bloğun tamamı da bir nesne olarak kullaniblir.
Yapının eleamnı olanm nesneler üzerinde işlemler yapabileceğimiz gibi, bu nesnelerin oluşturduğu bloğun tamamı üzerinde de doğrudan bazı işlemler yapabiliriz.

Yapıların kullanılmasıyla programcı yeni bir tür yaratabilir. C'nin var olan doğal veri türlerinin yanında, mantıksal bir anlamı soyutlayan yeni türler yaratabiliriz. Örneğin
değeri bir tarih bilgisi olan bir tür ya da değeri bir kompleks sayı olan bir tür oluşturulabilir. Böylece programlama ile bir çözüm oluşturmak istediğimiz problem düzlemi
daha iyi modellenebilir. Yapılaarın iyi bir şekilde öğrenmek, ileride nesne bazlı (object based) ve nesneye yönelimli (object oriented) programlama tekniklerinni iyi bir
biçimde anlaşılmasına yardımcı olur.

Yapıların  kullanılması için yapılması gereken ilk işlem bu yeni türü derleyeciyie tanıtmaktır. Tanıtma işlemi yapıu bildirimi ile olur. 

- türün ismi
- türün bellekte ne kadar yer kapladığı
- elemanların isimleri 

derleyiciye bildirilir.

struct <yapı_etiketi>
{
    <eleman_türü1> <eleman_adı1>;
    <eleman_türü2> <eleman_ad2>;
    ...
};

struct Date {
    init day, month, year;
};

struct Point {
    int x, y;
};

struct Complex {
    double real;
    double imag;
};

*/

// #include <stdio.h>

// struct Sample {
//     int i;
//     long l;
//     double d;
// };

// int main()
// {
//     struct Sample sam;
//     printf("%d\n", sizeof(sam)); // sizeof(sam) == sizeof(int) + sizeof(long) + sizeof(double) // Hizalama 
//     return 0;
// };

/*
Bir yapı bildirimi sonlandırıcı atom (;) ile sonlandırılmadan, yapı bildriminin kapanan küme ayracından hemen sonra bir değişken listesi yazılırsa yapı bildirimi ile
değişken tanımlaması bir arada yapılmış oluır.

struct Date {
    int day, month, year;}
} bdate, edate;

// struct Date bdate, edate;

struct {
    int day, month, year;
} bdate, edate;

Yapı nesnelerinin hemen yapı bildirimden sonra tanımlanması durumıundayapı ismi kullanma zorunluluğu da bulunmaz. Burada bdate ve edate yukarıda bildirilen ama isimlendirilmeyen
yapı türündne nesnnelerdir. Bu yöntemin dezavantajı artık aynı türden başka bir yapı değişkeninin tanımlanmasının mümkün olmayışıdır.  Örneğin yukarıdaki kod parçasından sonra
aynı yapı türüden bir yapı nesnesi daha tanımlamak istediğimizi düşünelim:

struct {
    int day, month, year;
} cdate;


*/

#include <stdio.h>

// struct Sample{
//     int i;
//     long l;
//     double d;
// };

// int main()
// {
//     struct Sample sam;

//     sam.i = 10;
//     sam.l = 20000L;
//     sam.d = 1.25;

//     printf("sam.i = %d\nsam.l = %ld\nsam.d = %f\n", sam.i, sam.l, sam.d);
    
    
//     return 0;
// }

// ------------------------------------------------------------------------------------------------------------------------

// struct Sample{
//     int i;
//     long l;
//     double d;
// };

// int main()
// {
//     struct Sample sam;

//     printf("sam.i'nin adresi: %p\n", &sam.i);
//     printf("sam.l'nin adresi: %p\n", &sam.l);
//     printf("sam.d'nin adresi: %p\n", &sam.d);

//     return 0;
// }

// ------------------------------------------------------------------------------------------------------------------------

// struct Point {
//     int x, y;
// };

// int main()
// {
//     struct Point p;

//     printf("sizeof(struct Point) = %u\n", sizeof(struct Point)); // tür ismi
//     printf("sizeof(p) = %u\n", sizeof(p)); // struct Point türünden bir nesne olan p'nin boyutu

//     return 0;
// }

// ------------------------------------------------------------------------------------------------------------------------


/*
 Bir yapı nesnesi atama operatörünnü (=) sol ya da sağ terimi olabilir. Bir yapsı nesnesine atama işleci ile ancak aynı türden başka bir yapı nesnesi atanabilir.
 Atama işlecinni sağındaki ve solundaki türlerin farklı yapı yürlerinden olması geçersizdir. Aynı türden iki yapı nesnesinin birbirine atanmasıyla yapı elemanları
 karlışılıklı olarak birbirlerine atanır. Yani bir blok kopyalaması söz konusudur. Atama işlemi için kesinlikle iki yapı değişkenin de aynı türden olması gerekir. İki yapı
 değişkeni de aynı türden değilse bu durum geçersizdir. 
*/

// struct POINT_1 {
//     int x, y;
// };

// struct POINT_2 {
//     int x, y;
// };

// void func()
// {
//     struct POINT_1 a;
//     struct POINT_2 b;

//     b.x = 10;
//     b.y = 20;

//     a = b; // hata: tür uyumsuzluğu
// }

/*
 İki yapı nesnesinin birbirine atanması, nesnelerin tüm elemanlarının karşılıklı olarak birbirlerine atanması sonucunu doğurur. Yani bir blok kopyalaması söz konusudur.
 Özellikle büyük yapılar söz konusu olduğunda atama işleci ile yapı nesnelerini birbirine atanmasının maliyetinhin yüksek olduğu unutuılmamalıdır. İlgili yapı türünün
 sizeof değeri büyüklüğpünde bir bellek bloğu, adeta memcpy benzeri bir işlevle kopyalanır.
*/

// #include <stdio.h>
// #include <string.h>

// struct Data{
//     int i;
//     long l;
//     double d;
// };

// int main()
// {
//     struct Data d1, d2, d3, d4;

//     d1.i = 10;
//     d1.l = 20000L;
//     d1.d = 1.25;

//     d2 = d1;

//     d3.i = d2.i;
//     d3.l = d2.l;
//     d3.d = d2.d;

//     memcpy(&d4, &d3, sizeof(struct Data));

//     printf("d1.i = %d\nd1.l = %ld\nd1.d = %f\n", d1.i, d1.l, d1.d);
//     printf("d2.i = %d\nd2.l = %ld\nd2.d = %f\n", d2.i, d2.l, d2.d);
//     printf("d3.i = %d\nd3.l = %ld\nd3.d = %f\n", d3.i, d3.l, d3.d);
//     printf("d4.i = %d\nd4.l = %ld\nd4.d = %f\n", d4.i, d4.l, d4.d);

//     return 0;
// }

// ------------------------------------------------------------------------------------------------------------------------

// Yapı elemanları belleğe, bildirimde ilk yazılan eleman küçük adreste olacak biçimde, bitişik olarak yerleştirilir.

// #include <stdio.h>

// struct Date {
//     int day, month, year;
// };

// int main()
// {
//     struct Date date;

//     printf("date.day'in adresi = %p\n", &date.day);
//     printf("date.month'un adresi = %p\n", &date.month);
//     printf("date.year'un adresi = %p\n", &date.year);

//     return 0;
// }

// Yapı elemanlı olarak diziler nasıl kullanılır?

/*
Yapının bir elemanı herhangi türden bir dizi olabilir. Bu durumda da yapının dizi elemanının ismi bir nesne belirtmez, bir adres bilgisidir.
*/

#include <stdio.h>

#define NAME_LEN 20

struct Person {
    char name[NAME_LEN]; // Bir elemanı char türden 20 elemanlı bir dizidir. Bu durumda kaynak kodumuz derlendiğinde sizeof(sruct Person) 24 olur. 
    int no;
};

int main()
{
    struct Person per;

    gets(per.name);
    puts(per.name);

    putchar(per.name[3]);
    per.name++; // Geçersiz. Dizi ismi nesne değildir.

    return 0;
}
