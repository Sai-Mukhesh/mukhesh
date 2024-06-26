#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node {
    int data; //node will store an integer
    struct node *right_child; // right child
    struct node *left_child; // left child
};

struct node* search(struct node *root, int x) {
    if(root==NULL || root->data==x) //if root->data is x then the element is found
        return root;
    else if(x>root->data) // x is greater, so we will search the right subtree
        return search(root->right_child, x);
    else //x is smaller than the data, so we will search the left subtree
        return search(root->left_child,x);
}

//function to find the minimum value in a node
struct node* find_minimum(struct node *root) {
    if(root == NULL)
        return NULL;
    else if(root->left_child != NULL) // node with minimum value will have no left child
        return find_minimum(root->left_child); // left most element will be minimum
    return root;
}

//function to create a node
struct node* new_node(int x) {
    struct node *p;
    p = malloc(sizeof(struct node));
    p->data = x;
    p->left_child = NULL;
    p->right_child = NULL;

    return p;
}

struct node* insert(struct node *root, int x) {
    //searching for the place to insert
    if(root==NULL)
        return new_node(x);
    else if(x>root->data) // x is greater. Should be inserted to right
        root->right_child = insert(root->right_child, x);
    else // x is smaller should be inserted to left
        root->left_child = insert(root->left_child,x);
    return root;
}
// funnction to delete a node
struct node* delete(struct node *root, int x) {
    //searching for the item to be deleted
    if(root==NULL)
        return NULL;
    if (x>root->data)
        root->right_child = delete(root->right_child, x);
    else if(x<root->data)
        root->left_child = delete(root->left_child, x);
    else
    {
        //No Children
        if(root->left_child==NULL && root->right_child==NULL)
        {
            free(root);
            return NULL;
        }

        //One Child
        else if(root->left_child==NULL || root->right_child==NULL)
        {
            struct node *temp;
            if(root->left_child==NULL)
                temp = root->right_child;
            else
                temp = root->left_child;
            free(root);
            return temp;
        }

        //Two Children
        else
        {
            struct node *temp = find_minimum(root->right_child);
            root->data = temp->data;
            root->right_child = delete(root->right_child, temp->data);
        }
    }
    return root;
}

void inorder(struct node *root) {
    if(root!=NULL) // checking if the root is not null
    {
        inorder(root->left_child); // visiting left child
        printf(" %d ", root->data); // printing data at root
        inorder(root->right_child);// visiting right child
    }
}

int main() {

  clock_t start_time, end_time;
  double cpu_time_used;

  start_time = clock();
  
    /*
                   20
                 /    \
                /      \
               5       30
             /   \     /\
            /     \   /  \
           1      15 25  40
                /          \
               /            \
              9             45
            /   \          /
           /     \        /
          7      12      42
    */
    struct node *root;
    root = new_node(20);
    insert(root,5);
    insert(root,1);
    insert(root,15);
    insert(root,9);
    insert(root,7);
    insert(root,12);
    insert(root,30);
    insert(root,25);
    insert(root,40);
    insert(root, 45);
    insert(root, 42);

    inorder(root);
    printf("\n");

    root = delete(root, 1);
    /*
                   20
                 /    \
                /      \
               5       30
                 \     /\
                  \   /  \
                  15 25   40
                /           \
               /             \
              9              45
            /   \           /
           /     \         /
          7      12       42
    */

    root = delete(root, 40);
    /*
                   20
                 /    \
                /      \
               5       30
                 \     /\
                  \   /  \
                  15 25  45
                 /       / 
                /       /   
               9       42    
             /   \          
            /     \        
           7      12      
    */

    root = delete(root, 45);
    /*
                   20
                 /    \
                /      \
               5       30
                 \     /\
                  \   /  \
                  15 25  42
                 /          
                /            
               9            
             /   \          
            /     \        
           7      12      
    */
    root = delete(root, 9);
    inorder(root);
    /*
                   20
                 /    \
                /      \
               5       30
                 \     /\
                  \   /  \
                  15 25  42
                 /          
                /            
               12            
             /             
            /             
           7            
    */
    printf("\n");


  end_time = clock();

  cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;


   printf("The execution time of the code is: %f seconds\n", cpu_time_used);


    return 0;
}

/*

observations about the provided code:
Binary Search Tree (BST) Implementation: The code implements a binary search tree (BST) data structure using a linked representation. Each node contains an integer data value, a pointer to the left child node, and a pointer to the right child node.

Search Operation: The search function recursively searches for a given key x in the BST. If the key is found, it returns the node containing the key; otherwise, it returns NULL.

Minimum Value Finding: The find_minimum function recursively finds and returns the node with the minimum data value in the BST.

Node Creation: The new_node function dynamically allocates memory for a new node with the specified data value and initializes its child pointers to NULL.

Insertion Operation: The insert function inserts a new node with the given data value into the BST while maintaining the BST property.

Deletion Operation: The delete function deletes a node with the specified data value from the BST while ensuring that the resulting tree remains a valid BST.

In-order Traversal: The inorder function performs an in-order traversal of the BST, printing the data values of the nodes in sorted order.

Main Function: In the main function, a BST is constructed with a specific structure. Nodes are inserted into the tree, and then some nodes are deleted. Finally, an in-order traversal of the modified tree is performed.

Execution Time Measurement: The code measures the execution time using the clock function from the time.h library. It calculates the CPU time used to execute the code.

Repetitive Code: The same code block for BST creation, insertion, deletion, and traversal is repeated twice in the code. This repetition could be avoided by moving the common functionality to separate functions.

Dynamic Memory Allocation: Memory allocation is done using malloc for creating new nodes. However, there's no deallocation of memory using free. It's important to free allocated memory to prevent memory leaks.


*/
