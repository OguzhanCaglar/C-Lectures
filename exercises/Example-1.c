#include <stdio.h>

// Calculate the area of a circle

int main()
{
    float pi = 3.14;
    float r = 0;
    float area = 0;

    printf("Please enter the radius: ");
    scanf("%f", &r); 

    printf("Area: %f\n", pi * r * r);

    return 0;
}