#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node* left;
    struct node* right;
};
struct node* root = NULL;
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
struct node* find(int info){
    struct node* save = root;
    struct node* temp = root;
    if(root->info == info){
        return root;
    }
    while(temp != NULL){
        if(temp->info == info){
            return temp;
        }
        if(temp->info > info){
            save = temp;
            temp = temp->left;
        }
        else{
            save = temp;
            temp = temp->right;

        }

    }
    return save;

}
void insert(int info){
    struct node* n = createNode()

}
int main(){
    root = createNode(110);

    return 0;
}
