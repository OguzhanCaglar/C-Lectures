/*
do-while loop

do
 deyim;
while (koşul);

do while döngüsünde kontrol ifadesi sonda yer alıyor. while ayracından sonra sonlandırıcı atom bulunmalıdır. Do while
döngüsünün yürütülmesi şu şekilde olur:
- do anahtar sözcüğünü izleyen deyim döngüye girişte bir kez yapılır, daha sonra while ayracı içindeki kontrol
ifadesine bakılır. Kontrol ifadesi doğru olduğu sürece döngü gövdesini oluşturan deyim yapılır.
- while döngüsünde döngü gövdesindeki deyimin en az bir kez yapılması güvence altında değildir. Ancak do while döngüsünde
kontrol sonda yapıldığı için gövdedeki deyim en az bir kez yapılır.


*/


// #include <stdio.h>

// int main()
// {
//     int val;

//     do
//     {
//         printf("0 - 100 arası bir deger girin: ");
//         scanf("%d", &val);
//     } while (val < 0 || val > 100);
    
//     printf("val = %d\n", val);
    
//     return 0;
// }

// main fonksiyonnuda do while döngüsü ile kullanıcı, 0-100 aralığında bir değer girmeye zorlanıyor. Eğer girilen değer
// 0'dan küçük ya da 100'den büyükse, kullanıcıdan yeni bir değer isteniyor.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// int main()
// {
//     int i = 3;

//     // do 
//     // {
//     //     --i;
//     //     printf("i = %d\n", i);
//     // } while (i > 1);

//     while(i > 1)
//     {
//         --i;
//         printf("i = %d\n", i);
//     }
    
//     return 0;
// }

// 1) Calculte x = kök(a)
// 2) xn+1 = 1/2 (xn + a/xn)
// 3) |xn+1 - xn| < 0.00001 --> 10^-5

// int main()
// {
//     float a = 5, xk = 0, xn = 3.1, err = 0;
//     int i = 0;

//     do
//     {
//         xk = xn;
//         xn  = 0.5 * (xk + a / xk);
//         err = fabs(xn - xk);
//         i++;
//     } while (err >= 0.00001);

//     printf("iters = %d, sqrt(a) = %f\n", i, xn);
    

//     return 0;
// }

// For Loop

/*
for (ifade1; ifade2; ifade3)
{
    deyim; // loop body --> döngü gövdesi
}

Derleyici for anahtar sözcüğünden sonra bir ayraç açılmasını ve ayraç içinde iki noktalı virgül atomu bulunmasını bekler. Bu
iki noktalı virgül, for ayracını üç kısma ayırır. Bu üç kısımda da ifade tanımına uygun ifadeler yer alabilir.

for ayracı içinde iki noktalı virgül mutlaka bulunmalıdır. for ayracınnı içinni boş bırakılması, ya da for ayracı içinde bir, üç
ya da daha fazla noktalı virgül bulunması derleyici tarafından hata olarak algılanır.

for ayracı içindeki her üç ifadenin de ayrı ayrı işlevi vardır.

for ayracının ikinci kısmını oluşturan ifadeye kontrol ifadesi (control expression) denir. Tıpkı while ayracı içindeki
ifade gibi, döngünnü sürdürülmesi konusunda bu ifade söz sahibidir. Bu ifadenin değeri sıfırdan farklı ise, yani doğru olarak
yorumlanırsa döngü sürecektir. Döngü gövdesindeki deyim yürütülür. Kontrol ifadesinin değeri sıfır olursa döngü sona erer.

Programın akışı for deyimine gelince, for ayracının birinci kısmında ifade değerlendirilir. Birinci kısımda ifade genellikle
döngü değişkenine ilk değer verme amacıyla kullanılır. Ancak şüphesiz böyle bir zorulnuluk yoktur.

for ayracının üçüncü kısmındaki ifade, döngü gövdesindeki deyim ya da deyimlerin yürütüldektn sonra kontrol ifadesi yeniden sınanmadan
önce ele alınır. Bu kısım çoğunlukla bir döngü değişkeninni arttırılması ya da azaltılması amacıyla kullanılır.

*/

// #include <stdio.h>

// int main()
// {
//     int i;

//     for(i = 0; i < 2; ++i)
//     {
//         printf("i = %d\n", i);
//     }
//     printf("\n son deger = %d\n", i);

//     return 0;
// }

// Programın akışı for döngü deyimine gelince önce for ayracı içindeki birinci ifade ele alınır. Yani i değişkenine 0
// değeri atanır. Şimid programın akışı for ayracının ikinci kısmına gelir. Bu kısımda i'nin 2'den küçük olup olmadığı
// kontrol edilir. Bu koşul doğru olduğu sürece döngü gövdesindeki deyim yürütülür. Döngü gövdesindeki deyim yürütüldükten
// sonra for ayracının üçüncü kısmındaki ifade ele alınır. Bu kısımda i değişkeni 1 arttırılır. Döngü gövdesindeki deyim
// yürütüldükten sonra for ayracının ikinci kısmındaki koşul tekrar sınanır. Bu işlem döngü değişkeni i'nin 2'den küçük
// olup olmadığı kontrol edilerek devam eder. i'nin 2'den küçük olmadığı durumda döngü sona erer ve programın akışı
// döngüden sonraki deyime geçer.

// break deyimi

// break deyimi, döngü gövdesindeki deyimlerin yürütülmesi sırasında döngüyü sonlandırmak için kullanılır. break deyimi
// döngü gövdesinde yer alan herhangi bir yerde kullanılabilir. break deyimi döngü gövdesinde yer aldığı anda döngü
// sona erer ve döngüden sonraki deyime geçilir.

// #include <stdio.h>

// int main()
// {
//     int i;

//     for(i = 0; i < 10; ++i)
//     {
//         if(i == 5)
//         {
//             break;
//         }
//         printf("i = %d\n", i);
//     }

//     return 0;
// }

// #include <stdio.h>
// #include <math.h>

// int main()
// {
//     int val;

//     while(1)
//     {
//         printf("bir sayi girin: ");
//         scanf("%d", &val);

//         if(val < 0)
//             break;
        
//         printf("karekok %d = %f\n", val, sqrt(val));
//     }
//     printf("donguden cikildi, program sonlaniyor!\n");

//     return 0;

// }

// Program bilinçli olarak bir sonsuz döngü oluşturulmuştur. Kullanıcıdan bir sayı girmesi istenir. Eğer kullanıcı
// negatif bir sayı girerse, break deyimi ile döngü sonlandırılır ve programın akışı döngüden sonraki deyime geçer.

// NOT:
// break deyimi yalnızca bir döngü deyiminin ya da switch-case deyiminin gövdesinde kullanılabilir.
/*
if (x > 100)
{
    if(y < 200)
    {
        break; // hata
    }
}

*/

// continue deyimi

// continue deyimi, döngü gövdesindeki deyimlerin yürütülmesi sırasında döngüyü sonlandırmak yerine, doğrudan sonlandırıcı
// atomu izler.

// continue;
// Programın akışı bir döngü deyimi içinde continue deyimine geldiğinde, sanki döngünün turu bitmiş gibi döngünnü bir sonraki
// turuna geçilir. Yani döngü gövdesindeki deyimlerin geri kalanı yürütülmez ve döngü deyiminin başına dönülür.

#include <stdio.h>

int main()
{
    int i, s = 0;

    for(i = 1; i <= 10; ++i)
    {
        s += 2 * i;
        if(i % 4 == 0)
        {
            continue;
        }
    }
    printf("s = %d\n", s);

    return 0;
}

// Page Number: 43