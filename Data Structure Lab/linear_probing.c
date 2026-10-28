#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *left, *right;
};

struct node *root = NULL;

struct node* insert(struct node *root, int item) {
    if (root == NULL) {
        struct node *newnode;
        newnode = (struct node*)malloc(sizeof(struct node));

        newnode->info = item;
        newnode->left = NULL;
        newnode->right = NULL;

        return newnode;
    }

    if (item < root->info)
        root->left = insert(root->left, item);
    else if (item > root->info)
        root->right = insert(root->right, item);

    return root;
}

struct node* search(struct node *root, int item) {
    if (root == NULL || root->info == item)
        return root;

    if (item < root->info)
        return search(root->left, item);

    return search(root->right, item);
}

void inorder(struct node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->info);
        inorder(root->right);
    }
}

void preorder(struct node *root) {
    if (root != NULL) {
        printf("%d ", root->info);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->info);
    }
}

struct node* minimum(struct node *root) {
    while (root->left != NULL)
        root = root->left;

    return root;
}

struct node* deleteNode(struct node *root, int item) {
    struct node *temp;

    if (root == NULL)
        return NULL;

    if (item < root->info)
        root->left = deleteNode(root->left, item);

    else if (item > root->info)
        root->right = deleteNode(root->right, item);

    else {
        if (root->left == NULL) {
            temp = root->right;
            free(root);
            return temp;
        }

        if (root->right == NULL) {
            temp = root->left;
            free(root);
            return temp;
        }

        temp = minimum(root->right);
        root->info = temp->info;
        root->right = deleteNode(root->right, temp->info);
    }

    return root;
}

int main() {
    int choice, item;

    while (1) {
        printf("\n\n1. Insertion");
        printf("\n2. Searching");
        printf("\n3. Deletion");
        printf("\n4. Inorder Traversal");
        printf("\n5. Preorder Traversal");
        printf("\n6. Postorder Traversal");
        printf("\n7. Exit");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter item: ");
            scanf("%d", &item);
            root = insert(root, item);
        }

        else if (choice == 2) {
            printf("Enter item: ");
            scanf("%d", &item);

            if (search(root, item) != NULL)
                printf("Item found");
            else
                printf("Item not found");
        }

        else if (choice == 3) {
            printf("Enter item: ");
            scanf("%d", &item);

            if (search(root, item) != NULL) {
                root = deleteNode(root, item);
                printf("Item deleted");
            } else {
                printf("Item not found");
            }
        }

        else if (choice == 4) {
            inorder(root);
        }

        else if (choice == 5) {
            preorder(root);
        }

        else if (choice == 6) {
            postorder(root);
        }

        else if (choice == 7) {
            break;
        }

        else {
            printf("Invalid choice");
        }
    }

    return 0;
}