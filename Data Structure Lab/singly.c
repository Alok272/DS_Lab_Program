#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
}*head=NULL, *temp, *newnode;

void insertatBeg(int num){
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = num;
    newnode->link = NULL;

    if(head == NULL){
        head = newnode;
    }
    else{
        newnode->link= head;
        head = newnode;
    }
}
void inseratLast(int num){
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = num;
    newnode->link = NULL;
    while(temp->link != NULL){
        temp = temp->link;
    }
    temp->link = newnode;
}

void delfromBeg(){
    if (head == NULL){
        printf("List Is Empty");
    }
    else{
        temp = head;
        head = head->link;
        printf("Element to be deleted %d", temp->data);
        free(temp);
    }
}

void traverse(){
    temp = head;
    while(temp!= NULL){
        printf("%d",temp->data);
        temp = temp->link;
    }

}


int main(){
    insertatBeg(10);
    insertatLast(20);
    traverse();
    return 0;
}