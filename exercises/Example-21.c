// Factorial of a number using recursion


#include <stdio.h>

int factorial(int n)
{
    if(n < 0)
    {
        return 0;
    }
    else if (n == 1 || n == 0)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}

int main()
{
    int n = 5, result = 0;

    result = factorial(n);

    printf("%d! = %d\n", n, result);

    return 0;
}