// Convert lower case char to upper case

#include <stdio.h>

int main()
{
    char ch = getchar();

    if(ch >= 'a' && ch <= 'z')
    {
        ch = ch - 32;
    }

    printf("ch = %c\n", ch);

    return 0;
}

// ? : is called the conditional operator

int main()
{
    char ch = getchar();

    ch = (ch >= 'a' && ch <= 'z') ? (ch - 32) : ch; 
 
    printf("ch = %c\n", ch);

    return 0;
}