/*

#include <stdio.h>
#include <stdlib.h>

struct node {
  int item;
  struct node* left;
  struct node* right;
};

// Inorder traversal
void inorderTraversal(struct node* root) {
  if (root == NULL) 
    return;
  inorderTraversal(root->left);
  printf("%d ->", root->item);
  inorderTraversal(root->right);
}

// Preorder traversal
void preorderTraversal(struct node* root) {
  if (root == NULL) 
    return;
  printf("%d ->", root->item);
  preorderTraversal(root->left);
  preorderTraversal(root->right);
}

// Postorder traversal
void postorderTraversal(struct node* root) {
  if (root == NULL) 
    return;
  postorderTraversal(root->left);
  postorderTraversal(root->right);
  printf("%d ->", root->item);
}

// Create a new Node
struct node* createNode(int value) {
  struct node* newNode = malloc(sizeof(struct node));
  newNode->item = value;
  newNode->left = NULL;
  newNode->right = NULL;

  return newNode;
}

// Insert on the left of the node
struct node* insertLeft(struct node* root, int value) {
  root->left = createNode(value);
  return root->left;
}

// Insert on the right of the node
struct node* insertRight(struct node* root, int value) {
  root->right = createNode(value);
  return root->right;
}

int main() {
  struct node* root = createNode(1);
  insertLeft(root, 2);
  insertRight(root, 3);
  insertLeft(root->left, 4);

  printf("Inorder traversal \n");
  inorderTraversal(root);

  printf("\nPreorder traversal \n");
  preorderTraversal(root);

  printf("\nPostorder traversal \n");
  postorderTraversal(root);
}


Output

Inorder traversal 
4 ->2 ->1 ->3 ->
Preorder traversal 
1 ->2 ->4 ->3 ->
Postorder traversal 
4 ->2 ->3 ->1 ->

*/  



#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int item;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->item = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insertLeft(Node* root, int value) {
    root->left = createNode(value);
    return root->left;
}

Node* insertRight(Node* root, int value) {
    root->right = createNode(value);
    return root->right;
}

void inorderTraversal(Node* root) {
    if (root == NULL) 
        return;
    inorderTraversal(root->left);
    printf("%d -> ", root->item);
    inorderTraversal(root->right);
}

void preorderTraversal(Node* root) {
    if (root == NULL) 
        return;
    printf("%d -> ", root->item);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(Node* root) {
    if (root == NULL) 
        return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d -> ", root->item);
}

int main() {
    Node* root = createNode(1);
    insertLeft(root, 2);
    insertRight(root, 3);
    insertLeft(root->left, 4);

    printf("Inorder traversal \n");
    inorderTraversal(root);
    printf("\n");

    printf("Preorder traversal \n");
    preorderTraversal(root);
    printf("\n");

    printf("Postorder traversal \n");
    postorderTraversal(root);
    printf("\n");

    return 0;
}

/* Struct Definition: The code defines a struct node which represents a node in a binary tree. Each node has an integer item, and pointers to its left and right children.

Traversal Functions: Three traversal functions are implemented: inorderTraversal, preorderTraversal, and postorderTraversal. Each function recursively traverses the binary tree in a specific order and prints the values of the nodes accordingly.

Node Creation and Insertion: The createNode function dynamically allocates memory for a new node and initializes its values. The insertLeft and insertRight functions insert new nodes as the left and right children of a given node, respectively.

Main Function: In the main function, a binary tree is constructed with the root node having a value of 1. Subsequent nodes with values 2, 3, and 4 are inserted into the tree. Then, the three traversal functions are called to print the tree elements in different orders.

Memory Allocation: The code dynamically allocates memory for each node using malloc. It's essential to free this memory using free to avoid memory leaks, but it's not done in this code.

Output: The output demonstrates the results of inorder, preorder, and postorder traversals of the binary tree constructed in the main function. Each traversal result is printed on a separate line.

Data Types: In the second part of the code, the struct Node is given a typedef, making it more convenient to declare variables of this type.

Consistency and Clarity: The code in the second part maintains consistency in function naming conventions and clarity in the structure of the code, making it easy to understand and maintain.

Error Handling: The code lacks error handling mechanisms, such as checking for malloc failures or ensuring that nodes are inserted into valid positions.

Readability: The code is well-formatted and organized, enhancing readability. However, adding comments to explain the logic and purpose of each function could further improve clarity.

*/
  
