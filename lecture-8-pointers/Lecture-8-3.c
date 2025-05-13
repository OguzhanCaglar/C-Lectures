/*

------------------------------------

Pointer to Function

------------------------------------

Bir fonksiyon göstericis, bir fonksiyonun adresini tutan bir pointer'dır. Yani normal değişkenlerin
adresi tutulabildiği gibi, fonksiyonların adresleri de tutulabilir. 

Neden Fonksiyon Göstercisine İhtiyaç Duyarız?

- Fonksiyonu değişkene atamak (örneğin hangi fonksiyonu çağıracağı sonradan belli olan durumlarda)
- Callback mekanizmalarında (örneğin buton tıklanınca ne olacağını belirtmek)
- Fonksiyon dizileri (switch yerine fonksiyon tablosu)

type (*function_pointer_name)(type1 a, type2, b)

--> int (*fptr)(int, int)
--> fptr = &func;
--> result = fptr(3, 4);


------------------------------------

#include <stdio.h>

int add(int a, int b)
{
    return a + b;
}

int multiply(int c, int d)
{
    return c * d;
}

int main()
{
    int (*fptr)(int, int);
    
    fptr = add; 
    
    int result = fptr(5, 8);
    
    printf("Sonuc: %d\n", result);
    
    fptr = multiply;
    
    int result2 = fptr(5, 8);
    
    printf("Sonuc: %d\n", result2);

    return 0;
}

------------------------------------


#include <stdio.h>

void func()
{
    printf("func()\n");
}

int main()
{
    void (*pf)(void) = func;
    
    pf(); // func()
    (*pf)(); // func()

    return 0;
}

------------------------------------

#include <stdio.h>

void func(void (*pf)(void))
{
    pf();
}

void f1()
{
    printf("f1()\n");
}

void f2()
{
    printf("f2()\n");
}

int main()
{
    func(f1);
    func(f2);

    return 0;
}


Fonksiyon göstericileri, bir işlevin belirli bir kısmının dışarıdan değiştirilmesine olanak sağlar. Yani fonksiyon,
bir amacı gerçekleştirecek belirli işlemleri yapmak için, dışarıdan adresini aldığı bir işlevi çağırabilir. Böylece
fonksioynu çağıran kod parçası, çağırdığı fonksiyonun işinin belirli bir kısmının, kendi istediği gibi yapılmasını
sağlayabilir. Böylece yazılan kaynak kod miktarı da azalabilir. Kaynak kodlarının büyük bir kısmı aynı olan çok sayıda işlev
yazmak yerine, işlev göstercisiyle çağrılan tek bir işlev yazmak mümkün olabilir. Fonksiyon göstericileri ile çağrılan
fonksiyonar, genelleştirilmiş işlevlerdir. Dışarıdan adreslerini aldıkları işlevlerin çağrılmalarıyla işlevleri
daha özel hale getirilmiş olur.

------------------------------------

Bir fonksiyonun geri dönüş değeri de bir işlev adresi olabilir. 

------------------------------------

#include <stdio.h>

void foo()
{
    printf("foo()\n");
}

void (*func(void))(void)
{
    void (*fp)(void) = foo;
    
    return fp;
}

int main()
{
    func()();

    return 0;
}

------------------------------------

#include <stdio.h>

void process(int a, int b, int (*op)(int, int))
{
    printf("Sonuc: %d\n", op(a, b));
}

int mul(int a, int b) {
    return a * b;
}


int main()
{
    process(3, 5, mul); // Callback

    return 0;
}

------------------------------------

Typedef function pointer

#include <stdio.h>

typedef int (*mathOp)(int, int);

int add(int a, int b)
{
    return a + b;
}

int main()
{
    mathOp f = add;
    
    printf("%d\n", f(2,3));

    return 0;
}

------------------------------------

Fonksiyon Göstericileri Dizisi

------------------------------------


#include <stdio.h>

int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }


int main()
{
    int (*ops[2])(int, int) = { add, sub };
    
    printf("%d\n", ops[0](4, 2));
    printf("%d\n", ops[1](4, 2));

    return 0;
}

*/