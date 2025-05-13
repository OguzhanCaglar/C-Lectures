/*

Example: Extarct out specified bits from a number

#include <stdio.h>

int main()
{
    unsigned char a = 0xAE, b = 0xF0, c = 0;
    
    c = a & b;
    c = c >> 4; 
    
    printf("a = %x, c = %x\n", a, c);
    

    return 0;
}

-------------------------------------------

Example-3: Check whether a number is odd

#include <stdio.h>

int main()
{
    int a;
    
    scanf("%d", &a);
    
    if(a & 1)
        printf("It is odd\n");
    else
        printf("It is even\n");
    

    return 0;
}

-------------------------------------------

Example-4: Count how many bits is 1

#include <stdio.h>

int main()
{
    int a = 11, count = 0, b = 0;
    
    scanf("%d", &a);
    
    while(a > 0)
    {
        b = a & 1;
        
        if(b == 1)
            count++;
        
        a = a >> 1;
    }
    
    printf("Count = %d\n", count);

    return 0;
}

-------------------------------------------

Example-5: set the k-th bit to 1

#include <stdio.h>

int main()
{
    int a = 0x50, b = 0;
    
    // we want to set the 4-th bit to 1
    b = 1 << 3; // 1 = 0001 --> 1 << 3 --> 1000 => 0001 | 1000 =  1001
    a = a | b;
    
    printf("count = %x\n", a);
    

    return 0;
}

-------------------------------------------

Kullanıcıdan alınan pozitif bir tamsayının binary gösteriminde kaç adet 1 bit olduğunu bulan bir fonksiyon yazınız.

#include <stdio.h>

int countSetBits(unsigned int n)
{
    int count = 0;
    
    while(n > 0)
    {
        if(n & 1)
            count++;
        
        n = n >> 1;
    }
    
    return count;
}

int main()
{
    unsigned int num = 13;
    
    printf("Binary representation of %u has %d set bits.", num, countSetBits(num));
    

    return 0;
}

-------------------------------------------

Verilen n tamsayısının sadece k numaralı bitini tersine çeviren bir fonksiyon yazınız.

input: n = 5, k = 0 --> // 0101 --> 0100
output: 4

-------------------------------------------

#include <stdio.h>

int toggleBit(int n, int k)
{
    return n ^ (1 << k);
}

int main()
{
    int num = 5, k = 0;
    
    int result = toggleBit(num, k);
    
    printf("Original: %d, After toggling bit %d: %d\n", num, k, result);
    

    return 0;
}

-------------------------------------------

Ödev:

1) Verilen n tamsayısında sadece belirli aralıktaki bitleri (örneğin bit 2'den bit 5'e kadar) 1 yapacak bir fonksiyon yazın.

int setBitsInRange(int n, int start, int end)

Input: n = 0, start = 2, end = 5
Output: 60 // 0011 1100

2) Verilen tamsayının LSB (least significant bit - en düşük bit) ile MSB (most signifcant bit - en yüksek bit) yerlerini değiştiren
bir fonksiyon yazınız.

Input: n = 2147483649 // 1000...0001
Output: 2 // 0000...0010

3) Araştırma --> Endiannes nedir? --> Little endian, Big endian?

*/
