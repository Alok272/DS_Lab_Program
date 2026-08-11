#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coeff;
    int exp;
    struct node *link;
};

struct node *create()
{
    struct node *start = NULL, *newnode, *ptr;
    int n, i;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));

        printf("Enter coefficient and power: ");
        scanf("%d%d", &newnode->coeff, &newnode->exp);

        newnode->link = NULL;

        if(start == NULL)
        {
            start = newnode;
        }
        else
        {
            ptr = start;

            while(ptr->link != NULL)
                ptr = ptr->link;

            ptr->link = newnode;
        }
    }

    return start;
}

void display(struct node *start)
{
    struct node *ptr = start;

    while(ptr != NULL)
    {
        printf("%dx^%d", ptr->coeff, ptr->exp);

        if(ptr->link != NULL)
            printf(" + ");

        ptr = ptr->link;
    }

    printf("\n");
}

struct node *add(struct node *p1, struct node *p2)
{
    struct node *result = NULL, *newnode, *ptr;
    int sum;

    while(p1 != NULL && p2 != NULL)
    {
        if(p1->exp == p2->exp)
        {
            sum = p1->coeff + p2->coeff;

            if(sum != 0)
            {
                newnode = (struct node *)malloc(sizeof(struct node));

                newnode->coeff = sum;
                newnode->exp = p1->exp;
                newnode->link = NULL;

                if(result == NULL)
                    result = newnode;
                else
                {
                    ptr = result;

                    while(ptr->link != NULL)
                        ptr = ptr->link;

                    ptr->link = newnode;
                }
            }

            p1 = p1->link;
            p2 = p2->link;
        }
        else if(p1->exp > p2->exp)
        {
            newnode = (struct node *)malloc(sizeof(struct node));

            newnode->coeff = p1->coeff;
            newnode->exp = p1->exp;
            newnode->link = NULL;

            if(result == NULL)
                result = newnode;
            else
            {
                ptr = result;

                while(ptr->link != NULL)
                    ptr = ptr->link;

                ptr->link = newnode;
            }

            p1 = p1->link;
        }
        else
        {
            newnode = (struct node *)malloc(sizeof(struct node));

            newnode->coeff = p2->coeff;
            newnode->exp = p2->exp;
            newnode->link = NULL;

            if(result == NULL)
                result = newnode;
            else
            {
                ptr = result;

                while(ptr->link != NULL)
                    ptr = ptr->link;

                ptr->link = newnode;
            }

            p2 = p2->link;
        }
    }

    while(p1 != NULL)
    {
        newnode = (struct node *)malloc(sizeof(struct node));

        newnode->coeff = p1->coeff;
        newnode->exp = p1->exp;
        newnode->link = NULL;

        if(result == NULL)
            result = newnode;
        else
        {
            ptr = result;

            while(ptr->link != NULL)
                ptr = ptr->link;

            ptr->link = newnode;
        }

        p1 = p1->link;
    }

    while(p2 != NULL)
    {
        newnode = (struct node *)malloc(sizeof(struct node));

        newnode->coeff = p2->coeff;
        newnode->exp = p2->exp;
        newnode->link = NULL;

        if(result == NULL)
            result = newnode;
        else
        {
            ptr = result;

            while(ptr->link != NULL)
                ptr = ptr->link;

            ptr->link = newnode;
        }

        p2 = p2->link;
    }

    return result;
}

int main()
{
    struct node *p1, *p2, *sum;

    printf("Enter First Polynomial\n");
    p1 = create();

    printf("\nEnter Second Polynomial\n");
    p2 = create();

    printf("\nFirst Polynomial: ");
    display(p1);

    printf("Second Polynomial: ");
    display(p2);

    sum = add(p1, p2);

    printf("Addition: ");
    display(sum);

    printf("Alok Pandey 2501920100076");
    return 0;
}