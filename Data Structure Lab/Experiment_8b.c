#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue()
{
    int value;
    struct node *newnode;

    printf("Enter value: ");
    scanf("%d", &value);

    newnode = (struct node *)malloc(sizeof(struct node));

    if (newnode == NULL)
    {
        printf("Queue Overflow\n");
        return;
    }

    newnode->data = value;
    newnode->link = NULL;

    if (rear == NULL)
    {
        front = rear = newnode;
    }
    else
    {
        rear->link = newnode;
        rear = newnode;
    }

    printf("%d inserted into queue.\n", value);
}

void dequeue()
{
    struct node *temp;

    if (front == NULL)
    {
        printf("Queue Underflow!\n");
        return;
    }

    temp = front;

    printf("%d deleted from queue.\n", front->data);

    front = front->link;

    if (front == NULL)
        rear = NULL;

    free(temp);
}

void display()
{
    struct node *temp;

    if (front == NULL)
    {
        printf("Queue is empty.\n");
        return;
    }

    temp = front;

    printf("Queue: ");

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->link;
    }

    printf("\n");
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n--- Queue using Linked List ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}