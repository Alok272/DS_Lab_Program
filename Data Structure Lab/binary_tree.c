#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->info = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void traverse(struct node* root){
    if(root != NULL){
        printf("%d ", root->info);
        traverse(root->left);
        traverse(root->right);
    }
}
int main()
{
    struct node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("Preorder Traversal: ");
    traverse(root);
    printf("\n");

    return 0;
}
