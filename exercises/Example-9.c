// Check Prime Number: Check whether an integer number if a prime number or not.
// Prime Number: number that is only dividable by 1 and itself.

#include <stdio.h>

int main()
{
    int i = 2, N = 177;
    int is_prime = 1;

    while(i < N)
    {
        if(N % i == 0)
        {
            is_prime = 0;
            printf("%d is dividable by %d\n", N, i);
        }
        i++;
    }

    if(is_prime == 1)
    {
        printf("%d is a prime number!\n", N);
    }
    else
    {
        printf("%d is not a prime number!\n", N);
    }

    return 0;
}