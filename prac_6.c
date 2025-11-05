#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};
struct node *head = NULL;

struct node* createnode(int value) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;
    return newnode;
}
void insertatend(int value) {
    struct node *newnode = createnode(value);

    if (head == NULL) {
        head = newnode;
    } else {
        struct node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}
void display() {
    struct node *temp = head;
    int count = 0;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("\nLinked List: ");
    while (temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
        count++;
    }
    printf("NULL\n");
    printf("Total number of nodes: %d\n", count);
}

int main() {
    int value;

    printf("Enter elements for the linked list (Enter 0 to stop):\n");
    while (1) {
        printf("Enter value: ");
        scanf("%d", &value);

        if (value == 0) {
            break;
        }
        insertatend(value);
    }
    display();

    return 0;
}
