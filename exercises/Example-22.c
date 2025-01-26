// Given an array: a[10] = {3, 21, 5, 8, 5,11, 22,14,9,51}
// Flip the array to: 51, 9, 14, 22, 11, 5, 8, 5, 21, 3}

#include <stdio.h>

int main()
{
    int a[10] = {3, 21, 5, 8, 5,11, 22,14,9,51};
    int temp = 0;

    for(int i = 0; i < 5; i++)
    {
        temp = a[i];
        a[i] = a[10 - i - 1];
        a[10 - i - 1] = temp;
    }

    for(int i = 0; i < 10; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}
