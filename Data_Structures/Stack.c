// #include <stdio.h>

// #define N   10  

// int stack[N];
// int top = -1;

// void push(int newVal)
// {
//     if(top == N-1)
//     {
//         printf("Stack DOLU! Eleman eklenemez. \n");
//     }
//     else
//     {
//         stack[++top] = newVal;
//         printf("%d stack'e eklendi.\n", newVal);
//     }
// }

// void pop()
// {
//     if(top == -1)
//     {
//         printf("Stack BOS! Eleman Cikarilamaz!\n");
//     }
//     else
//     {
//         int val = stack[top--];
//         printf("%d stack'ten cikarildi.\n", val);
//     }
    
// }

// void peek()
// {
//     if(top == -1)
//     {
//         printf("Stack BOS! Tepe eleman yok.\n");
//     }
//     else
//     {
//         printf("Stack'in tepe elemani: %d\n", stack[top]);
//     }
    
// }

// void printStack()
// {
//     printf("Stack Icerigi (tepe -> taban): ");

//     for (int i = top; i >= 0; i--)
//     {
//         printf("%d ", stack[i]);
//     }
//     printf("\n");
// }

// int main()
// {
//     int choice, newValue;
    
//     while (1)
//     {
//         printf("\n--- STACK MENUSU ---\n");
//         printf("1. Push (Ekle)\n");
//         printf("2. Pop  (Cikar)\n");
//         printf("3. Peek (Tepeyi Gor)\n");
//         printf("4. Stack Yazdir\n");
//         printf("5. Cikis\n");

//         printf("Seciminiz: ");
//         scanf("%d", &choice);

//         if(choice == 1)
//         {
//             printf("Eklemek istediginiz degeri girin: ");
//             scanf("%d", &newValue);
//             push(newValue);
//         }
//         else if (choice == 2)
//         {
//             pop();
//         }
//         else if(choice == 3)
//         {
//             peek();
//         }
//         else if(choice == 4)
//         {
//             printStack();
//         }
//         else if(choice == 5)
//         {
//             printf("Programdan cikiliyor...\n");
//             break;
//         }
//         else
//         {
//             printf("Gecersiz secim!\n");
//         }
//     }
    

//     return 0;
// }

// ------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* top = NULL; // Stack'in tepe (top) düğümü

void push(int newVal)
{
    Node* newNode = (Node *)malloc(sizeof(Node));

    if (!newNode)
    {
        printf("Bellek Yetersiz! Eleman eklenemedi.\n");
        return;
    }

    newNode->data = newVal;
    newNode->next = top;
    top = newNode;
    
    printf("%d stack'e eklendi.\n", newVal);
}

void pop()
{
    if (top == NULL)
    {
        printf("Stack BOS! Eleman cikarilamaz.\n");
    }
    else
    {
        Node* temp = top;
        printf("%d stack'ten cikarildi.\n", temp->data);
        top = top->next;
        free(temp);
    }
}

void peek()
{
    if (top == NULL)
    {
        printf("Stack BOS! Tepe eleman yok.\n");
    }
    else
    {
        printf("Stack'in tepe elemani: %d\n", top->data);
    }
}

void printStack()
{
    printf("Stack icerigi (tepe -> taban): ");
    Node* curr = top;

    while (curr)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

void freeStack()
{
    while (top != NULL)
    {
        pop();
    }
}

int main()
{
    int choice, newValue;
    
    while (1)
    {
        printf("\n--- STACK MENUSU ---\n");
        printf("1. Push (Ekle)\n");
        printf("2. Pop  (Cikar)\n");
        printf("3. Peek (Tepeyi Gor)\n");
        printf("4. Stack Yazdir\n");
        printf("5. Cikis\n");

        printf("Seciminiz: ");
        scanf("%d", &choice);

        if(choice == 1)
        {
            printf("Eklemek istediginiz degeri girin: ");
            scanf("%d", &newValue);
            push(newValue);
        }
        else if (choice == 2)
        {
            pop();
        }
        else if(choice == 3)
        {
            peek();
        }
        else if(choice == 4)
        {
            printStack();
        }
        else if(choice == 5)
        {
            printf("Programdan cikiliyor...\n");
            freeStack();
            break;
        }
        else
        {
            printf("Gecersiz secim!\n");
        }
    }
    

    return 0;
}