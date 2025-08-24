// #include <stdio.h>

// #define     N   6

// int queue[N];
// int front = 0, rear = 0, count = 0;

// void enqueue(int new)
// {
//     if(count == N)
//     {
//         printf("Kuyrukta yer yoktur!\n");
//     }
//     else
//     {
//         queue[rear] = new;
//         rear++;
//         if(rear == N)
//         {
//             rear = 0;
//         }
//         count++;
//         printf("%d kuyruga eklendi.\n", new);
//     }
// }

// void dequeue() 
// {
//     if(count == 0)
//     {
//         printf("Kuyrukta eleman yoktur.\n");
//     }
//     else
//     {
//         int removed = queue[front];
//         front++;
//         if(front == N)
//         {
//             front = 0;
//         }
//         count--;
//         printf("%d kuyruktan cikarildi\n", removed);
//     }
// }

// void printQueue(int queue[])
// {
//     printf("Queue: ");
//     int idx = front;

//     for (int i = 0; i < count; i++)
//     {
//         printf("%d ", queue[idx]);
//         idx = (idx + 1) % N;
//     }
//     printf("\n");
// }

// int main(void)
// {
//     printQueue(queue);
//     printf("\n---------------\n");

//     enqueue(10);
//     enqueue(20);
//     enqueue(30);
//     enqueue(40);
//     enqueue(50);
//     enqueue(60);

//     printQueue(queue);
//     printf("\n---------------\n");

//     dequeue();
//     printf("\n---------------\n");
//     printQueue(queue);

//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>

// struct Node
// {
//     int data;
//     struct Node* next;
// };

// struct Node* front = NULL;
// struct Node* rear = NULL;

// void enqueue(int new)
// {
//     struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));

//     newNode->data = new;
//     newNode->next = NULL;

//     if(front == NULL && rear == NULL)
//     {
//         front = rear = newNode;
//     }
//     else
//     {
//         rear->next = newNode;
//         rear = newNode;
//     }

//     printf("%d Kuyruga eklendi\n", new);
// }

// void dequeue()
// {
//     if(front == NULL)
//     {
//         printf("Kuyrukta eleman yoktur!\n");
//     }
//     else
//     {
//         struct Node* oldNode = front;
        
//         if(front == rear)
//         {
//             front = rear = NULL;
//         }
//         else
//         {
//             front = front->next;
//         }
//         printf("%d kuyruktan cikarildi\n", oldNode->data);
//         free(oldNode);
//     }
// }

#include <stdio.h>
#define N   5

int queue[N];
int front = 0, rear = 0, count = 0;

void enqueue(int newNum)
{
    if(count == N)
    {
        printf("Kuyruk Dolu! Yeni musteri alinamaz!\n");
    }
    else
    {
        queue[rear] = newNum;
        rear = (rear + 1) % N;
        count++;
        printf("Musteri #%d kuyruga eklendi.\n", newNum);
    }
}

void dequeue()
{
    if(count == 0)
    {
        printf("Kuyruk BOŞ! Cagiralacak musteri yok!\n");
    }
    else
    {
        int num = queue[front];
        front = (front + 1) % N;
        count--;
        printf("Musteri #%d cagrildi ve kuyruktan cikarildi.\n", num);
    }
}

void printQueue()
{
    printf("Mevcut Kuyruk: ");
    int idx = front;

    for (int i = 0; i < count; i++)
    {
        printf("%d ", queue[idx]);
        idx = (idx + 1) % N;
    }
    printf("\n");
}

int main(void)
{
    int choice, ticket = 100; // müşteri sırası için başlangıç numarası

    while (1)
    {
        printf("\n--- BANKA SIRA KUYRUGU ---\n");
        printf("1. Sira Al (enqueue)\n");
        printf("2. Siradakini Cagir (dequeue)\n");
        printf("3. Kuyrugu Goster\n");
        printf("4. Cikis\n");
        
        printf("Seciminiz: ");
        scanf("%d", &choice);

        if(choice == 1)
        {
            enqueue(ticket++);
        }
        else if(choice == 2)
        {
            dequeue();
        }
        else if(choice == 3)
        {
            printQueue();
        }
        else if(choice == 4)
        {
            printf("Programdan cikiliyor...\n");
            break;
        }
        else
        {
            printf("Gecersiz Secim!\n");
        }
    }
    return 0;
}