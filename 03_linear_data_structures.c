#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

typedef struct Node {
    int data;
    struct Node* next;
} Node;

int array_data[SIZE];
int top_of_stack, front, rear;

Node* stack_top = NULL;
Node* queue_front = NULL;
Node* queue_rear = NULL;

void push(int data) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = stack_top;
    stack_top = temp;
}

int pop() {
    Node* temp = stack_top;
    if (temp == NULL) {
        printf("\nStack underflow");
        return -1;
    }
    stack_top = stack_top->next;
    int popped = temp->data;
    free(temp);
    return popped;
}

void enqueue(int data) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    if (queue_front == NULL && queue_rear == NULL) {
        queue_front = queue_rear = temp;
        return;
    }
    queue_rear->next = temp;
    queue_rear = temp;
}

int dequeue() {
    Node* temp = queue_front;
    if (temp == NULL) {
        printf("\nQueue Empty");
        return -1;
    }
    if (queue_front == queue_rear) {
        queue_front = queue_rear = NULL;
    } else {
        queue_front = queue_front->next;
    }
    int dequeued = temp->data;
    free(temp);
    return dequeued;
}

void menu(void) {
    printf("\n1. Stack using Array");
    printf("\n2. Queue using Array");
    printf("\n3. Stack using Linked List");
    printf("\n4. Queue using Linked List");
    printf("\n5. Exit from the program");
    printf("\n\n Provide an option: ");
}

void push_array(void) {
    if (top_of_stack == SIZE) 
        printf("\nStack Overflow");
    else {
        printf("\nEnter the element to be pushed to the stack: ");
        scanf("%d", &array_data[top_of_stack++]);
    }
}

void pop_array(void) {
    if (top_of_stack == 0) 
        printf("\nStack underflow");
    else {
        printf("\nPopped element is: %d", array_data[--top_of_stack]);
    }
}

void display_stack_array(void) {
    if (top_of_stack == 0) 
        printf("\nNo elements in the stack\n");
    else 
        for (int i=0; i<top_of_stack; i++) 
            printf("%d \t", array_data[i] );
}

void enqueue_array(void) {
    if (rear == SIZE) 
        printf("\nQueue Full");
    else {
        printf("\nEnter the element to be inserted to the queue: ");
        scanf("%d", &array_data[rear++]);
    }
}

void dequeue_array(void) {
    if (front == rear) 
        printf("\nQueue Empty");
    else {
        printf("\nDeleted element is: %d", array_data[front++]);
    }
}

void display_queue_array(void) {
    if (front == rear) 
        printf("\nQueue Empty\n");
    else 
        for (int i=front; i<rear; i++) 
            printf("%d \t", array_data[i] );
}

void array_stack() {
    top_of_stack = 0;
    int choice;
    printf("\n***Creation of Stack using Array***");
    while(1) {
        printf("\n 1. Push \t 2. Pop \t 3. Display \t 4. Return to previous menu \n Choose an option: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: push_array();
                    break;
            case 2: pop_array();
                    break;
            case 3: display_stack_array();
                    break;
            case 4: return;
            default: printf("\nInvalid choice");
        }
    }  
}

void array_queue() {
    printf("\n***Creation of Queue using Array***");
    front =0;
    rear = 0;
    int choice;
    while(1) {
        printf("\n 1. Enqueue \t 2. Dequeue \t 3. Display \t 4. Return to previous menu \n Choose an option: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: enqueue_array();
                    break;
            case 2: dequeue_array();
                    break;
            case 3: display_queue_array();
                    break;
            case 4: return;
            default: printf("\nInvalid choice");
        }
    }
}

void linked_list_stack() {
    printf("\n***Creation of Stack using Linked List***");
    int choice;
    while(1) {
        printf("\n 1. Push \t 2. Pop \t 3. Return to previous menu \n Choose an option: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: 
                printf("\nEnter the element to be pushed to the stack: ");
                int data;
                scanf("%d", &data);
                push(data);
                break;
            case 2: 
                int popped = pop();
                if (popped != -1) {
                    printf("\nPopped element is: %d", popped);
                }
                break;
            case 3: return;
            default: printf("\nInvalid choice");
        }
    }  
}

void linked_list_queue() {
    printf("\n***Creation of Queue using Linked List***");
    int choice;
    while(1) {
        printf("\n 1. Enqueue \t 2. Dequeue \t 3. Return to previous menu \n Choose an option: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: 
                printf("\nEnter the element to be inserted to the queue: ");
                int data;
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2: 
                int dequeued = dequeue();
                if (dequeued != -1) {
                    printf("\nDeleted element is: %d", dequeued);
                }
                break;
            case 3: return;
            default: printf("\nInvalid choice");
        }
    }
}

int main(void) {
    int choice;
    while (1){
        menu();
        scanf("%d", &choice);
        switch (choice){
            case 1: array_stack();
                    break;
            case 2: array_queue();
                    break;
            case 3: linked_list_stack();
                    break;
            case 4: linked_list_queue();
                    break;
            case 5: return 0;
            default: printf("Invalid Option.  Try again.");
        }
    }
}



/* 

Data Structures Implementation: The code demonstrates the implementation of stack and queue data structures using both arrays and linked lists.

Memory Management: The code utilizes dynamic memory allocation (malloc) to create nodes for linked lists, ensuring efficient memory usage.

Error Handling: Error conditions such as stack overflow, stack underflow, and queue full/empty are appropriately handled with error messages.

Menu-Driven Interface: The program presents a menu-driven interface for users to interact with different data structures and perform operations like push, pop, enqueue, dequeue, and display.

Code Organization: The code is well-organized into functions for each operation, improving readability and maintainability.

Input Validation: The code includes input validation to handle invalid user inputs and prompts the user to re-enter a valid choice.
*/
