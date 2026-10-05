//WAP for implementation of stack using array
#include <stdio.h>
#include <stdlib.h>

#define MAX 5 

struct Stack {
    int items[MAX];
    int top;
};

void initStack(struct Stack *s) {
    s->top = -1;
}

int isFull(struct Stack *s) {
    return s->top == MAX - 1;
}

int isEmpty(struct Stack *s) {
    return s->top == -1;
}

void push(struct Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow! Cannot push %d\n", value);
    } else {
        s->top++;
        s->items[s->top] = value;
        printf("Pushed %d onto the stack.\n", value);
    }
}


int pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow! No elements to pop.\n");
        return -1;
    } else {
        int poppedValue = s->items[s->top];
        s->top--;
        return poppedValue;
    }
}


int peek(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
        return -1;
    } else {
        return s->items[s->top];
    }
}


void display(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements (top to bottom): ");
        for (int i = s->top; i >= 0; i--) {
            printf("%d ", s->items[i]);
        }
        printf("\n");
    }
}

int main() {
    struct Stack s;
    initStack(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    display(&s);

    printf("Top element is %d\n", peek(&s));
    printf("Popped element: %d\n", pop(&s));
    printf("Popped element: %d\n", pop(&s));

    display(&s);
 
    return 0;
}