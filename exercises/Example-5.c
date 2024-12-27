// Example: Judge whether it is a Leap Year

#include <stdio.h>

int main()
{
    int year = 0, leap = 0;

    printf("Please enter a year: ");
    scanf("%d", &year);

    if(year % 400 == 0)
    {
        leap = 1;
    } 
    else if (year % 4 == 0)
    {
        if(year % 100 == 0)
        {
            leap = 0;
        }
        else
        {
            leap = 1;
        }
    }
    else 
    {
        leap = 0;
    }

    if(leap == 1)
    {
        printf("%d is a leap year!\n", year);
    }
    else
    {
        printf("%d is not a leap year!\n", year);
    }

    return 0;
}