#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

// Ağacın düğüm yapısı
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int value)
{
    Node* newNode = (Node *)malloc(sizeof(Node));

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

Node* insert(Node* root, int data)
{
    if(root == NULL)
        return createNode(data);
    
    if(data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if(data > root->data)
    {
        root->right = insert(root->right, data);
    }
    
    return root;
}

void inorder(Node* root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preOrder(Node* root)
{
    if(root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(Node* root)
{
    if(root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

void printTree(Node* root)
{
    if(root != NULL)
    {
        printf("%d ", root->data);
        printTree(root->left);
        printTree(root->right);
    }
}

int main()
{
    Node* root = NULL;

    // Create tree
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    printf("Inorder: ");
    inorder(root); // 20, 30, 40, 50, 60, 70, 80
    printf("\n");

    printf("Preorder: ");
    preOrder(root); // 50, 40, 30, 20, 60, 70, 80
    printf("\n");

    printf("Postorder: "),
    postOrder(root); // 20, 30, 40, 60, 70, 80, 50 
    printf("\n");

    return 0;
}