/*
AIM :Implement Binary search tree(BST) with following Menu operations.

1.	Search an element in BST(Display NULL if not found, If found Display Found)
2.	Insert an element in BST
3.	Delete leaf element in BST
4.	Exit
*/
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};
struct node* createNode(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}
struct node* insert(struct node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

void search(struct node* root, int key) {
    if (root == NULL) {
        printf("NULL\n");
        return;
    }
    if (root->data == key) {
        printf("Found\n");
        return;
    }
    else if (key < root->data)
        search(root->left, key);
    else
        search(root->right, key);
}
struct node* deleteLeaf(struct node* root, int key) {
    if (root == NULL)
        return NULL;

    if (root->data == key) {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        } else {
            printf("Cannot delete: %d is not a leaf node.\n", key);
            return root;
        }
    }
    root->left = deleteLeaf(root->left, key);
    root->right = deleteLeaf(root->right, key);
    return root;
}
void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
int main() {
    struct node* root = NULL;
    int choice, value;
    while (1) {
        printf("\nBinary Search Tree\n");
        printf("1. Search an element in BST\n");
        printf("2. Insert an element in BST\n");
        printf("3. Delete leaf element in BST\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to search: ");
                scanf("%d", &value);
                search(root, value);
                break;
            case 2:
                printf("Enter element to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("Inserted successfully.\n");
                printf("Current BST (Inorder): ");
                inorder(root);
                printf("\n");
                break;
            case 3:
                printf("Enter leaf element to delete: ");
                scanf("%d", &value);
                root = deleteLeaf(root, value);
                printf("Updated BST (Inorder): ");
                inorder(root);
                printf("\n");
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
