#include <stdio.h>

// Display Function
void display(int arr[], int n)
{
    int i;
    printf("Array: ");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Insert at Beginning
int insertBeg(int arr[], int n)
{
    int i, value;
    printf("Enter value: ");
    scanf("%d", &value);

    for(i = n; i > 0; i--)
        arr[i] = arr[i - 1];

    arr[0] = value;
    return n + 1;
}

// Insert at End
int insertEnd(int arr[], int n)
{
    int value;
    printf("Enter value: ");
    scanf("%d", &value);

    arr[n] = value;
    return n + 1;
}

// Insert at Position
int insertPos(int arr[], int n)
{
    int i, value, pos;

    printf("Enter position: ");
    scanf("%d", &pos);

    if(pos < 1 || pos > n + 1)
    {
        printf("Invalid Position!\n");
        return n;
    }

    printf("Enter value: ");
    scanf("%d", &value);

    for(i = n; i >= pos; i--)
        arr[i] = arr[i - 1];

    arr[pos - 1] = value;

    return n + 1;
}

// Delete from Beginning
int deleteBeg(int arr[], int n)
{
    int i;

    if(n == 0)
    {
        printf("Array is Empty!\n");
        return n;
    }

    for(i = 0; i < n - 1; i++)
        arr[i] = arr[i + 1];

    return n - 1;
}

// Delete from End
int deleteEnd(int arr[], int n)
{
    if(n == 0)
    {
        printf("Array is Empty!\n");
        return n;
    }

    return n - 1;
}

// Delete from Position
int deletePos(int arr[], int n)
{
    int i, pos;

    if(n == 0)
    {
        printf("Array is Empty!\n");
        return n;
    }

    printf("Enter position: ");
    scanf("%d", &pos);

    if(pos < 1 || pos > n)
    {
        printf("Invalid Position!\n");
        return n;
    }

    for(i = pos - 1; i < n - 1; i++)
        arr[i] = arr[i + 1];

    return n - 1;
}

// Main Function
int main()
{
    int arr[100], n, i, choice;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    do
    {
        printf("\n1.Insert Beginning");
        printf("\n2.Insert End");
        printf("\n3.Insert Position");
        printf("\n4.Delete Beginning");
        printf("\n5.Delete End");
        printf("\n6.Delete Position");
        printf("\n7.Display");
        printf("\n8.Exit");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: n = insertBeg(arr, n); break;
            case 2: n = insertEnd(arr, n); break;
            case 3: n = insertPos(arr, n); break;
            case 4: n = deleteBeg(arr, n); break;
            case 5: n = deleteEnd(arr, n); break;
            case 6: n = deletePos(arr, n); break;
            case 7: display(arr, n); break;
            case 8: printf("Thank You!\n"); break;
            default: printf("Invalid Choice!\n");
        }

    } while(choice != 8);

    printf("Alok Pandey 2501920100076");
    return 0;
}