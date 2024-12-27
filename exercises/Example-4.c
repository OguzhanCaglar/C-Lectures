
// Example: Judge the Type of an Input Character


#include <stdio.h>

int main()
{
    char ch = ' ';

    printf("Please enter a character: ");
    // scanf("%c", &ch);
    ch = getchar();
    printf("You entered: %c\n", ch);

    if(ch >= '0' && ch <= '9')
    {
        printf("It is a digit!\n");
    }
    else if(ch >= 'A' && ch <= 'Z')
    {
        printf("It is an uppercase letter!\n");
    }
    else if(ch >= 'a' && ch <= 'z')
    {
        printf("It is a lowercase letter!\n");
    }
    else if(ch == ' ')
    {
        printf("It is a space!\n");
    }
    else
    {
        printf("It is an another special character!\n");
    } 
    
    return 0;
}