
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void display(struct Node *head) {

    struct Node *temp = head;

    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

struct Node* insertEnd(struct Node *head, int data) {

    struct Node *newNode = malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
        return newNode;

    struct Node *temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    return head;
}

struct Node* deleteBeginning(struct Node *head) {

    if (head == NULL)
        return NULL;

    struct Node *temp = head;

    head = head->next;
    free(temp);

    return head;
}

struct Node* deleteEnd(struct Node *head) {

    if (head == NULL)
        return NULL;

    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    struct Node *temp = head;

    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;

    return head;
}

struct Node* deletePosition(struct Node *head, int pos) {

    if (head == NULL)
        return NULL;

    if (pos == 1) {
        struct Node *temp = head;

        head = head->next;
        free(temp);

        return head;
    }
    
    struct Node *temp = head;
     
    for (int i = 1; i < pos - 1; i++) {
        temp = temp->next;
    }
    
    struct Node *nodeToDelete = temp->next;
    
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
    
    return head;
}

int main() {

    struct Node *head = NULL;

    head = insertEnd(head, 10);
    head = insertEnd(head, 20);
    head = insertEnd(head, 30);
    head = insertEnd(head, 40);

    printf("Original List: ");
    display(head);

    head = deleteBeginning(head);
    printf("\nAfter deleting beginning: ");
    display(head);

    head = deleteEnd(head);
    printf("\nAfter deleting end: ");
    display(head);

    head = deletePosition(head, 2);
    printf("\nAfter deleting position 2: ");
    display(head);
 
    return 0;
}
