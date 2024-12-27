#include <stdio.h>
#include <math.h>

// Solving a Quadratic Equation

/*
ax^2 + bx + c = 0

p = -b/2a
q = sqrt(b^2-4.a.c) / 2a )

x1 = p + q, x2 = p - q

*/

int main()
{
    float a, b, c;
    float p, delta, q;
    float x1, x2;
    
    printf("Please enter a,b,c values as ax^2+bx+c format: \n");
    scanf("%f %f %f", &a, &b, &c);

    delta = b * b - 4 * a * c;
    p = -b / (2 * a);
    q = sqrt(delta) / (2 * a);

    x1 = p + q;
    x2 = p - q;

    printf("x1: %f, x2 = %f", x1, x2);


    return 0;
}