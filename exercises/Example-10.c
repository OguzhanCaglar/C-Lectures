// Given following series of fractin
// 2/1, 3/2, 5/3, 8/5, 13/8, 21/13, ...
// Work out the sum of first 20 terms.

#include <stdio.h>

int main()
{
    float n1 = 2, n2 = 3;
    int d1 = 1, d2 = 2, i = 0;
    float s = n1/d1 + n2/d2;

    for(i = 3; i <= 20; ++i)
    {
        n2 = n1 + n2;
        d2 = d1 + d2;
        s += n2/d2;
        n1 = n2 - n1;
        d1 = d2 - d1;
        printf("i = %d, n2 = %f, d2 = %d\n", i, n2, d2);
        printf("s = %f\n", s);
    }
    printf("%s = %f\n", s);
    return 0;
}