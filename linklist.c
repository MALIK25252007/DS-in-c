#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

void createList(struct Node **head){
    struct Node *newNode, *temp;
    int n, i, val;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    if (n <= 0){
        printf("Invalid number of elements.\n");
        return;
    }
    for (i = 1; i <= n; i++){

        printf("Enter value for node %d: ", i);
        scanf("%d", &val);

        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = val;
        newNode->next = NULL;

        if (*head == NULL){
            *head = newNode;
        }
        else{
            temp = *head;

            while (temp->next != NULL){
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    printf("Linked List created successfully!\n");
}

void display(struct Node *head){
    struct Node *temp = head;

    if (head == NULL){
        printf("List is empty.\n");
        return;
    }

    printf("Linked List: ");

    while (temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

void insertBeg(struct Node **head, int val){
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = val;
    newNode->next = *head;
    *head = newNode;
}
void insertEnd(struct Node **head, int val){
    struct Node *newNode, *temp;

    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;

    if (*head == NULL){
        *head = newNode;
        return;
    }
    temp = *head;

    while (temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}
void insertPosition(struct Node **head, int val, int pos){
    struct Node *newNode, *temp;
    int i;

    if (pos == 1){
        insertBeg(head, val);
        return;
    }

    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    temp = *head;

    for (i = 1; i < pos - 1 && temp != NULL; i++){
        temp = temp->next;
    }

    if (temp == NULL){
        printf("Invalid position.\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}
void deleteBeg(struct Node **head){
    struct Node *temp;

    if (*head == NULL){
        printf("List is empty.\n");
        return;
    }

    temp = *head;
    *head = (*head)->next;
    free(temp);
}
void deleteEnd(struct Node **head){
    struct Node *temp, *prev;
    if (*head == NULL){
        printf("List is empty.\n");
        return;
    }

    if ((*head)->next == NULL){
        free(*head);
        *head = NULL;
        return;
    }

    temp = *head;

    while (temp->next != NULL){
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);
}
void deletePosition(struct Node **head, int pos){
    struct Node *temp, *prev;
    int i;

    if (*head == NULL){
        printf("List is empty.\n");
        return;
    }

    if (pos == 1){
        deleteBeg(head);
        return;
    }

    temp = *head;
    for (i = 1; i < pos && temp != NULL; i++){
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL){
        printf("Invalid position.\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}

int main(){
    struct Node *head = NULL;
    int choice, val, pos;

    while (1){

        printf("\n=========SINGLY LINKED LIST=========\n");
        printf("1. Create Linked List\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at End\n");
        printf("4. Insert at Any Position\n");
        printf("5. Delete from Beginning\n");
        printf("6. Delete from End\n");
        printf("7. Delete from Any Position\n");
        printf("8. Display\n");
        printf("9. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice){
            case 1:
                createList(&head);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &val);
                insertBeg(&head, val);
                break;

            case 3:
                printf("Enter value: ");
                scanf("%d", &val);
                insertEnd(&head, val);
                break;

            case 4:
                printf("Enter value: ");
                scanf("%d", &val);
                printf("Enter position: ");
                scanf("%d", &pos);
                insertPosition(&head, val, pos);
                break;

            case 5:
                deleteBeg(&head);
                break;

            case 6:
                deleteEnd(&head);
                break;

            case 7:
                printf("Enter position: ");
                scanf("%d", &pos);

                deletePosition(&head, pos);
                break;

            case 8:
                display(head);
                break;

            case 9:
                printf("Program ended.\n");
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}