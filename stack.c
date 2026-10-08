// Stack program
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Define stack structure
typedef struct
{
int *arr; // array to store elements
int capacity; // maximum size of stack
int top; // index of top element
} Stack;

// Function to create a stack
Stack *createStack(int capacity)
{
Stack *stack = (Stack *)malloc(sizeof(Stack));
stack->capacity = capacity;
stack->arr = (int *)malloc(capacity * sizeof(int));
stack->top = -1;
return stack;
}

// Push operation
void push(Stack *stack, int x)
{
if (stack->top == stack->capacity - 1)
{
printf("Stack Overflow\n");
return;
}
stack->arr[++stack->top] = x;

}

// Pop operation
int pop(Stack *stack)
{
if (stack->top == -1)
{
printf("Stack Underflow\n");
return -1;
}
return stack->arr[stack->top--];
}

// Peek operation
int peek(Stack *stack)
{
if (stack->top == -1)
{
printf("Stack is Empty\n");
return -1;
}
return stack->arr[stack->top];
}

// Check if stack is empty
bool isEmpty(Stack *stack)
{
return stack->top == -1;
}

// Check if stack is full
bool isFull(Stack *stack)

{
return stack->top == stack->capacity - 1;
}

// Free stack memory
void freeStack(Stack *stack)
{
free(stack->arr);
free(stack);
}

int main()
{
Stack *st = createStack(4);

// Push elements
push(st, 1);
push(st, 2);
push(st, 3);
push(st, 4);

// Pop one element
printf("Popped: %d\n", pop(st));

// Peek top element
printf("Top element: %d\n", peek(st));

// Check if stack is empty
printf("Is stack empty: %s\n", isEmpty(st) ? "Yes" : "No");

// Check if stack is full
printf("Is stack full: %s\n", isFull(st) ? "Yes" : "No");

freeStack(st); // free memory
return 0;
}