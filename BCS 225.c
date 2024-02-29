//Stack Implementation:
//.	Using Arrays:
#include <stdio.h>
#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

void push(int item) {
    if (top >= MAX_SIZE - 1) {
        printf("Stack overflow!\n");
        return;
    }
    stack[++top] = item;
}

int pop() {
    if (top < 0) {
        printf("Stack underflow!\n");
        return -1; // Assuming -1 as an error value
    }
    return stack[top--];
}

int peek() {
    if (top < 0) {
        printf("Stack is empty!\n");
        return -1; // Assuming -1 as an error value
    }
    return stack[top];
}

int is_empty() {
    return top < 0;
}

int main() {
    push(10);
    push(20);
    printf("Popped item: %d\n", pop()); // Output: 20
    printf("Top item: %d\n", peek());   // Output: 10
    return 0;
}
2.	Using Linked List:
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int item) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = item;
    new_node->next = top;
    top = new_node;
}

int pop() {
    if (top == NULL) {
        printf("Stack underflow!\n");
        return -1; // Assuming -1 as an error value
    }
    struct Node* temp = top;
    int popped_item = temp->data;
    top = top->next;
    free(temp);
    return popped_item;
}

int peek() {
    if (top == NULL) {
        printf("Stack is empty!\n");
        return -1; // Assuming -1 as an error value
    }
    return top->data;
}

int is_empty() {
    return top == NULL;
}

int main() {
    push(10);
    push(20);
    printf("Popped item: %d\n", pop()); // Output: 20
    printf("Top item: %d\n", peek());   // Output: 10
    return 0;
}
//Queue Implementation:
//1.	Using Arrays:
#include <stdio.h>
#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

void enqueue(int item) {
    if (rear >= MAX_SIZE - 1) {
        printf("Queue overflow!\n");
        return;
    }
    if (front == -1)
        front = 0;
    queue[++rear] = item;
}

int dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue underflow!\n");
        return -1; // Assuming -1 as an error value
    }
    return queue[front++];
}

int front_item() {
    if (front == -1 || front > rear) {
        printf("Queue is empty!\n");
        return -1; // Assuming -1 as an error value
    }
    return queue[front];
}

int is_empty() {
    return front == -1 || front > rear;
}

int main() {
    enqueue(10);
    enqueue(20);
    printf("Dequeued item: %d\n", dequeue()); // Output: 10
    printf("Front item: %d\n", front_item()); // Output: 20
    return 0;
}
//2.	Using Linked List:
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void enqueue(int item) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = item;
    new_node->next = NULL;
    if (rear == NULL) {
        front = rear = new_node;
        return;
    }
    rear->next = new_node;
    rear = new_node;
}

int dequeue() {
    if (front == NULL) {
        printf("Queue underflow!\n");
        return -1; // Assuming -1 as an error value
    }
    struct Node* temp = front;
    int dequeued_item = temp->data;
    front = front->next;
    if (front == NULL)
        rear = NULL;
    free(temp);
    return dequeued_item;
}

int front_item() {
    if (front == NULL

