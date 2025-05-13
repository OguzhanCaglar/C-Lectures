// Unions (Birlikler)

/*
Programcı tarafından yeni bir tür yaratmasına olanak veren bir başka araç da "birlikler"dir. 
Birlikler yapılara çok benzer. Bir birliğin kullanılabilmesi için, yani bir birlik türünden nesnelerin tanımlanabilmesi için önce birliğin bildirimi yapılmalıdır.
Birlik bildirimleri aynı yapı (struct) bildirimleri gibi yapılır. Tek fark struct yerine union kelimesinin kullanılmasıdır.

union Dword {
    unsigned char byte; 
    unsigned int word;
    unsigned long dword;
};

Yukarıdaki deyimle, ismi union Dword olan yeni bir tür bildirilmiş olur. Bu bildirimin görülür olduğu yerlerde, bu tür kullaınlabilir. Bir typedef bildirimi
yapılarak, bu türün isminin, yalnızca DWword olması da sağlanabilir:

typedef union{
    unsigned char byte; 
    unsigned int word;
    unsigned long dword;
}Dword;

Birlik değişkenleri aynı yapı değişkenleri gibi tanımlanır. Birliklerde de, bellekte yer ayırma işlemi yapı bildirimi ile değil, yapı nesnesinni tanımlanması ile yapılır.

Dword a, b;

union Dword {
    unsigned char byte; 
    unsigned int word;
    unsigned long dword;
}a, b, c;

Birlik Nesnelerinni Bellekteki Yerleşimi
----------------------------------------

Birlik nesneleri için birliin en uzun elemanı kadar yer ayrılır. Birlik elemanlarının hepsi aynı sayısal adresten başlayacak şekilde belleğe yerleşir.

#include <stdio.h>

struct Data1 {
    short i;
    float f;
    char str[10];
};

union Data2 {
    short i;
    float f;
    char str[10];
};


int main()
{
    struct Data1 d1;
    union Data2 d2;
    
    printf("Size of d1 %d\n", sizeof(d1)); // 20
    printf("Size of d2 %d\n", sizeof(d2)); // 12

    return 0;
}

Yukarıdaki örnekte, struct Data1 ve union Data2 türünden nesnelerin bellekteki yerleşimini göstermektedir. struct Data1 türünden nesne 20 byte, union Data2 türünden
nesne ise 12 byte yer kaplar. Bu durum, birliklerin, birlik elemanlarının en uzun olanı kadar yer kapladığını gösterir. Birliklerin bellekteki yerleşimi, birlik elemanlarının
hepsi aynı sayısal adresten başlayacak şekilde belleğe yerleşir.

#include <stdio.h>
#include <string.h>

union Data {
    int i;
    float f;
    char str[20];
};

int main()
{
    union Data data;
    data.i = 10;
    data.f = 220.5;
    strcpy(data.str, "Merhaba C");
    
    printf("data.i : %d\n", data.i);
    printf("data.f : %f\n", data.f);
    printf("data.str : %s\n", data.str);
    
    
    return 0;
}

----------------------------------------

#include <stdio.h>
#include <string.h>

union Data {
    int i;
    float f;
    char str[20];
};

int main()
{
    union Data data;
    data.i = 10;
    strcpy(data.str, "Merhaba C");
    data.f = 220.5;
    
    printf("data.i : %d\n", data.i);
    printf("data.f : %f\n", data.f);
    printf("data.str : %s\n", data.str);
    
    
    return 0;
}

----------------------------------------

#include <stdio.h>
#include <string.h>

union Data {
    int i;
    float f;
    char str[20];
};

int main()
{
    union Data data;
    data.i = 10;
    printf("data.i : %d\n", data.i);
    data.f = 220.5;
    printf("data.f : %f\n", data.f);
    strcpy(data.str, "Merhaba C");
    printf("data.str : %s\n", data.str);
    
    
    return 0;
}

ENUM
------------------------

#include <stdio.h>

enum Month {
    Jan, // 0
    Feb, // 1
    Mar, // 2
    Apr, // 3
    May,
    Jun,
    Jul,
    Aug,
    Sep,
    Oct,
    Nov,
    Dec // 11
};

// Feb is a symbol instead of a string
// They will be related to integer 0, 1, 2, ... automatically

int main()
{
    enum Month m;
    m = Dec;
    
    printf("Month is: %d\n", m);
    
    return 0;
}

#include <stdio.h>

enum Week {
    Mon=1,
    Tue=1,
    Wed=3,
    Thu=5,
    Fri,
    Sat=4,
    Sun
};

// This way is valid, but not suggested.

int main()
{
    enum Week wk;
    wk = Wed;
    printf("Wed: %d\n", wk); // 3
    
    wk = Fri;
    printf("Fri: %d\n", wk); // 6
    
    wk = Sun;
    printf("Sun: %d\n", wk); // 5
    
    return 0;
}

#include <stdio.h>

enum Week {
    Mon=1,
    Tue,
    Wed,
    Thu,
    Fri,
    Sat,
    Sun
};

int main()
{
    enum Week wk;
    wk = Wed;
    printf("Wed: %d\n", wk); // 3
    
    wk = Fri;
    printf("Fri: %d\n", wk); // 5
    
    wk = Sun;
    printf("Sun: %d\n", wk); // 7
    
    return 0;
}




*/