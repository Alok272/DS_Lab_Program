#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};

struct node *top = NULL;

void push()
{
    int value;
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));

    if (newnode == NULL)
    {
    printf("Stack Overflow\n");
    return;
    }

    printf("Enter value: ");
    scanf("%d", &value);
    newnode->info = value;
    newnode->link = top;
    top = newnode;

    printf("%d pushed into stack.\n", value);
}

void pop()
{
    struct node *temp;

    if (top == NULL)
    {
        printf("Stack Underflow\n");
        return;
    }

    temp = top;
    printf("%d popped from stack.\n", top->info);
    top = top->link;
    free(temp);
}

void display()
{
    struct node *temp;

    if (top == NULL)
    {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements are:\n");
    temp = top;

    while (temp != NULL)
    {
        printf("%d\n", temp->info);
        temp = temp->link;
    }
}
void peek()
{
    printf("%d", top->info);
}
int main()
{
    int choice;

    do
    {
        printf("\n--- STACK USING LINKED LIST ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4.Peek\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;
            case 4:
                display();
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 5);

    return 0;
}