/* Pointer to struct type variable

------------------------------------
#include <stdio.h>

struct STD {
    char name[16];
    float gpa;
};

int main()
{
    struct STD std1 = {"Demir", 2.9};
    struct STD *p = &std1;
    printf("Name: %s\n", (*p).name);
    printf("GPA:  %f\n", (*p).gpa);
    printf("Sizeof(p): %d", sizeof(p));

    return 0;
}

------------------------------------

#include <stdio.h>

struct STD {
    char name[16];
    float gpa;
};

typedef struct STD STDT;

int main()
{
    STDT std1 = {"Demir", 2.9};
    struct STD *p = &std1;
    printf("Name: %s\n", p->name);
    printf("GPA:  %f\n", p->gpa);

    return 0;
}

"P->" is equivelant to "(*p)"

------------------------------------

#include <stdio.h>

struct STD {
    char name[16];
    float gpa;
};

int main()
{
    struct STD std1 = {"Demir", 2.9};
    struct STD *p = &std1;
    
    int *q;
    char *r;
    
    printf("size of STD: %d\n", sizeof(struct STD)); // 20
    printf("size of p:   %d\n", sizeof(p)); // 4
    printf("size of q:   %d\n", sizeof(q)); // 4
    printf("size of r:   %d\n", sizeof(r)); // 4 
    
    
    return 0;
}

------------------------------------

Dynamic Memory Allocation

------------------------------------

#include <stdio.h>
#include <stdlib.h>


int main()
{
    int i = 0;
    int *a1 = (int *)malloc(5*sizeof(int));
    
    for(i = 0; i < 5; i++)
    {
        a1[i] = i+1; // a[0] = 1, a[1] = 2 ...
    }
    
    free(a1); // release the memory pointing by a1
    
    return 0;
}

------------------------------------


#include <stdio.h>
#include <stdlib.h>


int main()
{
    int i = 0;
    int *a1 = (int *)malloc(5*sizeof(int));
    
    for(i = 0; i < 5; i++)
    {
        a1[i] = i+1; // a[0] = 1, a[1] = 2 ...
    }
    
    free(a1); // release the memory pointing by a1
    a1[2] = 3; // illegal memory access
    
    return 0;
}

------------------------------------

#include <stdio.h>
#include <stdlib.h>


int main()
{
    int i = 0;
    int *a1 = (int *)malloc(5*sizeof(int));
    
    for(i = 0; i < 5; i++)
    {
        a1[i] = i+1; // a[0] = 1, a[1] = 2 ...
    }
    
    a1 = (int *)malloc(15*sizeof(int));
    free(a1); // release the memory pointing by a1
    
    return 0;
}

------------------------------------

Pointer to Function

------------------------------------

*/