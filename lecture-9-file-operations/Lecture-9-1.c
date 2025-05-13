// File Operations

// #include <stdio.h>

// int main()
// {
//     const char *fn = "number.txt";
//     int a = 0, b = 0;

//     FILE *fp = fopen(fn, "r"); // open file in read mode

//     if (fp == NULL)
//     {
//         printf("File open error\n");
//         return 1;
//     }

//     fscanf(fp, "%d %d", &a, &b);
//     fclose(fp);

//     printf("a: %d, b: %d\n", a, b);


//     return 0;

// }

//-------------------------------------

/*
#include <stdio.h>

int main()
{
    const char *fn = "strings.txt";
    char line[1024];

    FILE *fp = fopen(fn, "r"); // open file in read mode

    if (fp == NULL)
    {
        printf("File open error\n");
        return 1;
    }

    fscanf(fp, "%s", line);
    fclose(fp);

    printf("line: %s\n", line);

    return 0;

}
*/

