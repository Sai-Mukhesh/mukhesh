// Searching a key on a B-tree in C
#include <stdio.h>
#include <stdlib.h>

#define MAX 3
#define MIN 2

struct BTreeNode {
  int val[MAX + 1], count;
  struct BTreeNode *link[MAX + 1];
};

struct BTreeNode *root;

// Create a node
struct BTreeNode *createNode(int val, struct BTreeNode *child) {
  struct BTreeNode *newNode;
  newNode = (struct BTreeNode *)malloc(sizeof(struct BTreeNode));
  if(newNode == NULL) {
    printf("Memory allocation failed.\n");
    exit(EXIT_FAILURE);
  }
  newNode->val[1] = val;
  newNode->count = 1;
  newNode->link[0] = root;
  newNode->link[1] = child;
  return newNode;
}

// Insert node
void insertNode(int val, int pos, struct BTreeNode *node,
        struct BTreeNode *child) {
  int j = node->count;
  while (j > pos) {
    node->val[j + 1] = node->val[j];
    node->link[j + 1] = node->link[j];
    j--;
  }
  node->val[j + 1] = val;
  node->link[j + 1] = child;
  node->count++;
}

// Split node
void splitNode(int val, int *pval, int pos, struct BTreeNode *node,
         struct BTreeNode *child, struct BTreeNode **newNode) {
  int median, j;

  if (pos > MIN)
    median = MIN + 1;
  else
    median = MIN;

  *newNode = (struct BTreeNode *)malloc(sizeof(struct BTreeNode));
  if(*newNode == NULL) {
    printf("Memory allocation failed.\n");
    exit(EXIT_FAILURE);
  }
  j = median + 1;
  while (j <= MAX) {
    (*newNode)->val[j - median] = node->val[j];
    (*newNode)->link[j - median] = node->link[j];
    j++;
  }
  node->count = median;
  (*newNode)->count = MAX - median;

  if (pos <= MIN) {
    insertNode(val, pos, node, child);
  } else {
    insertNode(val, pos - median, *newNode, child);
  }
  *pval = node->val[node->count];
  (*newNode)->link[0] = node->link[node->count];
  node->count--;
}

// Set the value
int setValue(int val, int *pval,
           struct BTreeNode *node, struct BTreeNode **child) {
  int pos;
  if (!node) {
    *pval = val;
    *child = NULL;
    return 1;
  }

  if (val < node->val[1]) {
    pos = 0;
  } else {
    for (pos = node->count;
       (val < node->val[pos] && pos > 1); pos--)
      ;
    if (val == node->val[pos]) {
      printf("Duplicates are not permitted\n");
      return 0;
    }
  }
  if (setValue(val, pval, node->link[pos], child)) {
    if (node->count < MAX) {
      insertNode(*pval, pos, node, *child);
    } else {
      splitNode(*pval, pval, pos, node, *child, child);
      return 1;
    }
  }
  return 0;
}

// Insert the value
void insert(int val) {
  int flag, i;
  struct BTreeNode *child;

  flag = setValue(val, &i, root, &child);
  if (flag)
    root = createNode(i, child);
}

// Search node
void search(int val, int *pos, struct BTreeNode *myNode) {
  if (!myNode) {
    return;
  }

  if (val < myNode->val[1]) {
    *pos = 0;
  } else {
    for (*pos = myNode->count;
       (val < myNode->val[*pos] && *pos > 1); (*pos)--)
      ;
    if (val == myNode->val[*pos]) {
      printf("%d is found", val);
      return;
    }
  }
  search(val, pos, myNode->link[*pos]);

  return;
}

// Traverse then nodes
void traversal(struct BTreeNode *myNode) {
  int i;
  if (myNode) {
    for (i = 0; i < myNode->count; i++) {
      traversal(myNode->link[i]);
      printf("%d ", myNode->val[i + 1]);
    }
    traversal(myNode->link[i]);
  }
}

// Free nodes
void freeNode(struct BTreeNode *myNode) {
  int i;
  if (myNode) {
    for (i = 0; i <= myNode->count; i++) {
      freeNode(myNode->link[i]);
    }
    free(myNode);
  }
}

int main() {
  int val, ch;

  insert(8);
  insert(9);
  insert(10);
  insert(11);
  insert(15);
  insert(16);
  insert(17);
  insert(18);
  insert(20);
  insert(23);

  traversal(root);

  printf("\n");
  search(11, &ch, root);

  freeNode(root);
  return 0;
}
/*

Observations:

B-tree Implementation: The code implements a B-tree data structure, a type of self-balancing tree data structure that maintains sorted data and allows for efficient insertion, deletion, and searching.

Node Structure: The struct BTreeNode defines the structure of a B-tree node. It includes an array val to store keys, an array link to store pointers to child nodes, and a count variable to keep track of the number of keys present in the node.

Create Node Function: The createNode function creates a new B-tree node with the given value and child node. It initializes the node's arrays and count appropriately.

Insertion Operation: The insert function inserts a new value into the B-tree. It starts by setting the value recursively, then either inserts the value directly if there is space in the node, or splits the node if it's full.

Split Node Function: The splitNode function splits a full node into two nodes when inserting a new value. It redistributes the values and pointers between the original node and the newly created node.

Search Operation: The search function searches for a value in the B-tree recursively. It starts at the root and traverses down the tree based on the value until it finds the value or reaches a leaf node.

Traversal Function: The traversal function performs an in-order traversal of the B-tree, printing out the values in sorted order.

Freeing Memory: The freeNode function recursively frees the memory allocated for the nodes in the B-tree.

Main Function: In the main function, several values are inserted into the B-tree, and then traversal and search operations are performed. After that, memory allocated for the B-tree nodes is freed.

Error Handling: The code checks for memory allocation failures during node creation and terminates the program if allocation fails. However, there's no error handling for duplicate values during insertion.

Constants: The code defines constants MAX and MIN, representing the maximum and minimum number of keys in a B-tree node, respectively.

Code Organization: The code is well-organized into functions, making it modular and easier to understand.
*/
