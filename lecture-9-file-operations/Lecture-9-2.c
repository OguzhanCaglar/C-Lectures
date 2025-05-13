// #include <stdio.h>

// int main()
// {
//     const char *fn = "hi.txt";
//     char buf[100];

//     FILE *fp = fopen(fn, "w");

//     if(fp == NULL) {
//         printf("Error opening file");
//         return 1;
//     }

//     fprintf(fp, "Hello World %d\n", 1);
//     fclose(fp); // call "fcloase" all the time when you finish writing

//     return 0;

// }

#include <stdio.h>

int main()
{
    const char *fn = "hi.txt";
    char buf[100];

    FILE *fp = fopen(fn, "a"); // a --> append mode

    if(fp == NULL) {
        printf("Error opening file");
        return 1;
    }

    fprintf(fp, "Hello World %d\n", 2);
    fclose(fp); // call "fcloase" all the time when you finish writing

    return 0;

}