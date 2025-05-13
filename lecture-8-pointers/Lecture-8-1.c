
/*
#include <stdio.h>
#include <string.h>

int main()
{
    short *pt = NULL; //points to an short integer variable 
    float a = 3.1;
    
    float *fpt = &a; // fpt points to float a variable.
    
    printf("Size of pt: %ld\n", sizeof(pt));
    printf("Size of fpt: %ld\n", sizeof(pt));
    printf("Size of short: %ld\n", sizeof(short));

    return 0;
}
---------------------------------------------------------------

Visit variable by its pointer

#include <stdio.h>
#include <string.h>

int main()
{
    short a = 4;
    short *pa = &a;
    
    float b = 3.1;
    float *pb = &b;
    
    printf("a = %d\n", a);  // 4 
    printf("b = %f\n", b);  // 3.1
    printf("*pa = %d\n", *pa); // 4 --> a değişkeninin değeri
    printf("*pb = %f\n", *pb); // 3.1 --> b değişkeninin değeri
    
    printf("pa = %ld\n", pa); // a'nın adresi
    printf("pb = %ld\n", pb); // b'nin adresi
    
    
    return 0;
}

---------------------------------------------------------------

#include <stdio.h>
#include <string.h>

int main()
{
    float a = 4.5;
    float b = 3.1;
    
    float *p = &a;
    
    printf("p = %x\n", p); // a'nın adresi
    
    p = &b;
    
    printf("*p = %f\n", *p); // b'nin değeri --> 3.1
    printf("p = %x\n", p); // b'nin adresi
    
    *p = 7.2; // b'nin değerine 7.2 veriliyor
    p = &a; // a'nın adresi pointer'a veriliyor
    *p = 5.3; // a'nın değerine 5.3 veriliyor
    
    printf("a = %f\n", a); // a'nın değeri --> 5.3 
    printf("b = %f\n", b); // b'nin değeri --> 7.2
    
    
    return 0;
}

---------------------------------------------------------------

Swap Values of 2 variables

---------------------------------------------------------------


#include <stdio.h>
#include <string.h>

// ÖDEV: call by value, call by reference

void swap(int a, int b)
{
    printf("Fonksiyonun ici: %d, %d\n", a, b);
    int tmp = a;
    a = b;
    b = tmp;
    
    return;
}

int main()
{
    int a = 3;
    int b = 5;
    
    printf("a = %d, b = %d\n", a, b); // a = 3, b = 5
    swap(a, b);
    printf("a = %d, b = %d\n", a, b); // a = 3, b = 5 --> Neden?
    
    
    return 0;
}

---------------------------------------------------------------

#include <stdio.h>
#include <string.h>

// ÖDEV: call by value, call by reference

void swap(int *a, int *b) 
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
    
    return;
}

int main()
{
    int a = 3;
    int b = 5;
    
    printf("a = %d, b = %d\n", a, b); // a = 3, b = 5
    swap(&a, &b); // call by reference
    printf("a = %d, b = %d\n", a, b); // a = 5, b = 3 --> Neden?
    
    
    return 0;
}

---------------------------------------------------------------

#include <stdio.h>

int main()
{
    int a = 3;
    int *p;
    int b = 1;
    
    p = &a;
    printf("a = %d\n", *p);
    
    p = &b;
    printf("b = %d\n", *p);
    
    
    return 0;
}

---------------------------------------------------------------

#include <stdio.h>

void increment(int *a)
{
    *a = *a + 1;
}

int main()
{
    int a = 4;
    int *b = &a;
    
    printf("%d\n", *b); // 4
    increment(&a);
    printf("%d\n", a); // 5
    printf("%d\n", *b); // 5
    
    return 0;
}

---------------------------------------------------------------

#include <stdio.h>

int main()
{
    int a = 3, *p;
    int b = 1;
    float c = 2.2;
    
    p = &a;
    printf("%d\n", *p);
    *p = b;
    printf("%d\n", *p); // 1
    printf("%d\n", a); // 1
    
    return 0;
}

---------------------------------------------------------------

#include <stdio.h>

void increment(int *a)
{
    a = a + 4;
}

int main()
{
    int a = 4, *b = &a;
    
    printf("%d\n", *b); // 4
    
    increment(&a);
    
    printf("%d\n", a); // 4
    printf("%d\n", *b); // 4
    
    return 0;
}

---------------------------------------------------------------

int main()
{
    int a = 0;
    printf("Input value for a: ");
    scanf("%d", a);
    
    printf("a = %d", a);
    
    return 0;
}

---------------------------------------------------------------

Pointer Array

---------------------------------------------------------------

#include <stdio.h>


int main()
{
    int a1[4] = {31, 1, 11, 4};
    int i = 0, *p = a1; // *p1 = &a1[0] --> *p = 31
    
    for(i = 0; i < 4; i++,p++)
    {
        printf("%d ", *p); // p++ -> p += 1 -->  31, 1, 11, 4
    }
    
    return 0;
}

---------------------------------------------------------------

#include <stdio.h>


int main()
{
    int a1[4] = {31, 1, 11, 4};
    int i = 0, *p = a1; 
    
    for(i = 0; i < 4; i++)
    {
        printf("%d ", a1[i]);
    }
    
    return 0;
}

---------------------------------------------------------------


#include <stdio.h>


int main()
{
    int a1[6] = {12, 7, 11, 13, 53};
    short b1[6] = {12, 7, 11, 13, 53};
    
    int *pa = &a1; // a1[0]
    short *pb = &b1; // b1[0]
    
    pa++;
    pb++;
    
    printf("%d\n", *pa); // a1[1]
    printf("%d\n", *pb); // b1[1]
    
    return 0;
}

---------------------------------------------------------------

Pointer to String

---------------------------------------------------------------

#include <stdio.h>


int main()
{
    char *hi = "hello";
    hi[1] = 'a'; // --> illegal assignment
    
    printf("%s\n", hi);
    
    return 0;
}

int main()
{
    char hi[] = "hello";
    hi[1] = 'a';
    
    printf("%s\n", hi); --> Legal
    
    return 0;
}

---------------------------------------------------------------


#include <stdio.h>


int main()
{
    char *str1 = "hello world!";
    char str2[16];
    
    char *p1 = str1;
    char *p2 = str2;
    
    while(*p1 != '\0')
    {
        *p2 = *p1;
        p1++;
        p2++;
    }
    
    *p2 = '\0';
    
    printf("%s\n", str1);
    printf("%s\n", str2);
    
    return 0;
}

---------------------------------------------------------------


#include <stdio.h>

void strCopy(char *p1, char *p2)
{
    while(*p1 != '\0')
    {
        *p2 = *p1;
        p1++;
        p2++;
    }
    
    *p2 = '\0';
}


int main()
{
    char *str1 = "hello world!";
    char str2[16];
    
    strCopy(str1, str2);
    
    printf("%s\n", str1);
    printf("%s\n", str2);
    
    return 0;
}

---------------------------------------------------------------

Popular functions for string operation

#include <stdio.h>
#include <string.h>

int main()
{
    char *str1 = "hello", *str2 = "world";
    char hi[32];
    
    strcpy(hi, str1); // hi = hello
    strcat(hi, " "); // hi = hello 
    strcat(hi, str2); // hi = hello world
    printf("%s\n", hi);
    
    return 0;
}

---------------------------------------------------------------

#include <stdio.h>
#include <string.h>

int main()
{
    char *str1 = "hello", *str2 = "hi", *str3 = "hello";
    
    if(strcmp(str1, str2) == -1)
    {
        printf("str1 < str2!\n");
    } 
    else if(strcmp(str1, str2) == 1)
    {
        printf("str1 > str2!\n");
    }
    
    if(strcmp(str1, str3) == 0)
    {
        printf("They are equal!\n");
    }
    else
    {
        printf("They are inequal!\n");
    }

    
    return 0;
}

