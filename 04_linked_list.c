#include <stdio.h>
#include <stdlib.h>

int choice;

struct singly_node {
  int data;
  struct singly_node *next;
};

struct doubly_node {
  int data;
  struct doubly_node *next, *prev;
};

void menu(void) {
  printf("\n1. Singly Linked List \n2. Doubly Linked List \n3. Circular Linked "
         "List \n4. Exit");
  printf("\nChoose an option: ");
  scanf("%d", &choice);
}

void singly_linked_list() {
  printf("\n*** Singly Linked List ***");
  int choice = 1;
  struct singly_node *head = NULL, *new_node, *temp;
  while (choice == 1) {
    new_node = (struct singly_node *)malloc(sizeof(struct singly_node));
    printf("\nEnter node data: ");
    scanf("%d", &new_node->data);
    new_node->next = NULL;
    if (head == NULL)
      head = temp = new_node;
    else {
      temp->next = new_node;
      temp = new_node;
    }
    printf("\nTo insert a new node press 1 else any other integer: ");
    scanf("%d", &choice);
  }

  printf("\nThe elements in the Singly Linked list are...");
  temp = head;
  while (temp != NULL) {
    printf("\n%d", temp->data);
    temp = temp->next;
  }
}

void doubly_linked_list() {
  printf("\n*** Doubly Linked List ***");
  int choice = 1;
  struct doubly_node *head = NULL, *new_node, *temp;
  while (choice == 1) {
    new_node = (struct doubly_node *)malloc(sizeof(struct doubly_node));
    printf("\nEnter node data: ");
    scanf("%d", &new_node->data);
    new_node->next = NULL;
    new_node->prev = NULL;
    if (head == NULL) {
      head = temp = new_node;
    } else {
      temp->next = new_node;
      new_node->prev = temp;
      temp = new_node;
    }
    printf("\nTo insert a new node press 1 else any other integer: ");
    scanf("%d", &choice);
  }

  printf("\nThe elements in the Doubly Linked list are...");
  temp = head;
  while (temp != NULL) {
    printf("\n%d", temp->data);
    temp = temp->next;
  }
}

void circular_linked_list() {
  printf("\n*** Circular Linked List ***");
  int choice = 1;
  struct singly_node *head = NULL, *new_node, *temp;
  while (choice == 1) {
    new_node = (struct singly_node *)malloc(sizeof(struct singly_node));
    printf("\nEnter node data: ");
    scanf("%d", &new_node->data);
    new_node->next = NULL;
    if (head == NULL) {
      head = temp = new_node;
      new_node->next = head;
    } else {
      temp->next = new_node;
      new_node->next = head;
      temp = new_node;
    }
    printf("\nTo insert a new node press 1 else any other integer: ");
    scanf("%d", &choice);
  }

  printf("\nThe elements in the Circular Linked list are...");
  temp = head;
  do {
    printf("\n%d", temp->data);
    temp = temp->next;
  } while (temp != head);
}

int main() {
  while (1) {
    menu();
    switch (choice) {
    case 1:
      singly_linked_list();
      break;
    case 2:
      doubly_linked_list();
      break;
    case 3:
      circular_linked_list();
      break;
    case 4:
      return 0;
    default:
      printf("\nInvalid Option");
    }
  }
}

/*

Observations:

Menu-Driven Interface: The code presents a menu-driven interface that allows the user to choose between singly linked lists, doubly linked lists, circular linked lists, or exit the program.

Singly Linked List Implementation:

The singly linked list implementation allows the user to create a list of nodes dynamically by inserting nodes one by one.
Each node contains an integer data field and a pointer to the next node.
The program displays the elements in the singly linked list after the user finishes inserting nodes.
Doubly Linked List Implementation:

Similar to the singly linked list, the doubly linked list implementation allows dynamic creation of nodes with integer data fields.
Each node in the doubly linked list has pointers to the next and previous nodes, enabling traversal in both directions.
The program displays the elements in the doubly linked list after node insertion.
Circular Linked List Implementation:

The circular linked list implementation also allows dynamic creation of nodes with integer data fields.
Each node in the circular linked list points to the next node, and the last node points back to the head node, creating a circular structure.
The program displays the elements in the circular linked list by traversing the circular structure.
Dynamic Memory Allocation:

The code correctly uses malloc to allocate memory for new nodes in all three types of linked lists, ensuring efficient memory usage.
User Interaction:

The program prompts the user to enter node data and provides options to continue inserting nodes or exit after each linked list operation.
Error Handling:

The code lacks explicit error handling for memory allocation failures or invalid user inputs, which could be added for robustness.
 */
