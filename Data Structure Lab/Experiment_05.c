#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *prev;
    struct node *link;
};

struct node *start = NULL, *newnode, *ptr, *temp;

// Create first node
void create()
{
    if(start != NULL)
    {
        printf("List already created!\n");
        return;
    }

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->info);

    newnode->prev = NULL;
    newnode->link = NULL;

    start = newnode;
}

// Display
void display()
{
    if(start == NULL)
    {
        printf("List is Empty\n");
        return;
    }

    ptr = start;

    printf("Doubly Linked List: ");

    while(ptr != NULL)
    {
        printf("%d <-> ", ptr->info);
        ptr = ptr->link;
    }

    printf("NULL\n");
}

// Insert at Beginning
void insertBeg()
{
    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->info);

    newnode->prev = NULL;
    newnode->link = start;

    if(start != NULL)
        start->prev = newnode;

    start = newnode;
}

// Insert at End
void insertEnd()
{
    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->info);

    newnode->link = NULL;

    if(start == NULL)
    {
        newnode->prev = NULL;
        start = newnode;
        return;
    }

    ptr = start;

    while(ptr->link != NULL)
        ptr = ptr->link;

    ptr->link = newnode;
    newnode->prev = ptr;
}

// Insert at Any Position
void insertPos()
{
    int pos, i;

    printf("Enter Position: ");
    scanf("%d", &pos);

    if(pos == 1)
    {
        insertBeg();
        return;
    }

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->info);

    ptr = start;

    for(i = 1; i < pos-1 && ptr != NULL; i++)
        ptr = ptr->link;

    if(ptr == NULL)
    {
        printf("Invalid Position\n");
        free(newnode);
        return;
    }

    newnode->link = ptr->link;
    newnode->prev = ptr;

    if(ptr->link != NULL)
        ptr->link->prev = newnode;

    ptr->link = newnode;
}

// Delete Beginning
void deleteBeg()
{
    if(start == NULL)
    {
        printf("List Empty\n");
        return;
    }

    temp = start;
    start = start->link;

    if(start != NULL)
        start->prev = NULL;

    free(temp);

    printf("First Node Deleted\n");
}

// Delete End
void deleteEnd()
{
    if(start == NULL)
    {
        printf("List Empty\n");
        return;
    }

    ptr = start;

    while(ptr->link != NULL)
        ptr = ptr->link;

    if(ptr->prev == NULL)
    {
        start = NULL;
    }
    else
    {
        ptr->prev->link = NULL;
    }

    free(ptr);

    printf("Last Node Deleted\n");
}

// Delete Any Position
void deletePos()
{
    int pos, i;

    printf("Enter Position: ");
    scanf("%d", &pos);

    if(pos == 1)
    {
        deleteBeg();
        return;
    }

    ptr = start;

    for(i = 1; i < pos && ptr != NULL; i++)
        ptr = ptr->link;

    if(ptr == NULL)
    {
        printf("Invalid Position\n");
        return;
    }

    if(ptr->prev != NULL)
        ptr->prev->link = ptr->link;

    if(ptr->link != NULL)
        ptr->link->prev = ptr->prev;

    free(ptr);

    printf("Node Deleted\n");
}

int main()
{
    int choice;

    do
    {
        printf("\n====== MENU ======\n");
        printf("1. Create\n");
        printf("2. Display\n");
        printf("3. Insert Beginning\n");
        printf("4. Insert End\n");
        printf("5. Insert Any Position\n");
        printf("6. Delete Beginning\n");
        printf("7. Delete End\n");
        printf("8. Delete Any Position\n");
        printf("9. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: create(); break;
            case 2: display(); break;
            case 3: insertBeg(); break;
            case 4: insertEnd(); break;
            case 5: insertPos(); break;
            case 6: deleteBeg(); break;
            case 7: deleteEnd(); break;
            case 8: deletePos(); break;
            case 9: printf("Program Ended\n"); break;
            default: printf("Invalid Choice\n");
        }

    } while(choice != 9);
    printf("Alok Pandey 2501920100076");
    return 0;
}

