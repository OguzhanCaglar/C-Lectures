// Conditional Controls

// #include <stdio.h>

// int main()
// {
//     int x = 8;

//     if(x % 2 == 0) // if it is true then it will execute the block of code
//     {
//         printf("Even\n");
//     }
//     else // if it is false then it will execute the block of code
//     {
//         printf("Odd\n");
//     }

//     return 0;
// }

// --------------------------------------------------------------------------------

// #include <stdio.h>

// int main()
// {
//     int a = -1; // 0xFFFFFFFF
//     unsigned int b = 600; // 0x00000258

//     if (a > b)
//     {
//         printf("%d is greater than %d\n", a, b);
//     }
//     else 
//     {
//         printf("%d is not greater than %d\n", a, b);
//     }

//     return 0;
// }

// --------------------------------------------------------------------------------

// #include <stdio.h>

// int main()
// {
//     int a = 5 > 3 && 2 || 8 < 4 - !0; // 1 && 2 || 8 < 3 // 1 && 2 || 0; // 1 && 2 || 0; // 1 && 0; // 0

//     printf("%d\n", a);

//     return 0;
// }

// --------------------------------------------------------------------------------

// Example: Judge the Type of an Input Character

// #include <stdio.h>

// int main()
// {
//     char ch = ' ';

//     printf("Please enter a character: ");
//     // scanf("%c", &ch);
//     ch = getchar();
//     printf("You entered: %c\n", ch);

//     if(ch >= '0' && ch <= '9')
//     {
//         printf("It is a digit!\n");
//     }
//     else if(ch >= 'A' && ch <= 'Z')
//     {
//         printf("It is an uppercase letter!\n");
//     }
//     else if(ch >= 'a' && ch <= 'z')
//     {
//         printf("It is a lowercase letter!\n");
//     }
//     else if(ch == ' ')
//     {
//         printf("It is a space!\n");
//     }
//     else
//     {
//         printf("It is an another special character!\n");
//     } 
    
//     return 0;
// }

// --------------------------------------------------------------------------------

// Example: Judge whether it is a Leap Year

// #include <stdio.h>

// int main()
// {
//     int year = 0, leap = 0;

//     printf("Please enter a year: ");
//     scanf("%d", &year);

//     if(year % 400 == 0)
//     {
//         leap = 1;
//     } 
//     else if (year % 4 == 0)
//     {
//         if(year % 100 == 0)
//         {
//             leap = 0;
//         }
//         else
//         {
//             leap = 1;
//         }
//     }
//     else 
//     {
//         leap = 0;
//     }

//     if(leap == 1)
//     {
//         printf("%d is a leap year!\n", year);
//     }
//     else
//     {
//         printf("%d is not a leap year!\n", year);
//     }

//     return 0;
// }

// --------------------------------------------------------------------------------

// #include <stdio.h>

// int main()
// {
//     int a = 3, b = 5, c = 7;

//     if(a != 3)
//     if(b > 9)
//         printf("b = %d", b);
//     else
//         printf("c = %d", c);
    
//     return 0;
// }

// --------------------------------------------------------------------------------

// Page number: 52

// Homeworks
// --------------------------------------------------------------------------------

// 1) Write a C program to compute the sum of the two input values. If the two values are the same, then return the triple of their sum.
// 2) Write a C program to check a given integer and return true if it is within 10 of 100 or 200.
// 3) Write a C program that will take a number as input and find the absoulte difference between the input number and 51. 
// If the input number is greater than 51 it will return triple the absolute difference.