// Cprogram to convert a Binary Tree to	Threaded Tree 
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

// Structure of a node in threaded binary tree
struct node
{
	int key;
	struct node *left, *right;
	// Used to indicate whether the right pointer
	// is a normal right pointer or a pointer
	// to inorder successor.
	bool isThreaded;
};

// Converts tree with given root to threaded binary tree.
// This function returns rightmost child of root.
struct node *createThreaded(struct node *root) {
	// Base cases : Tree is empty or has single node
	if (root == NULL)
		return NULL;
	if (root->left == NULL && root->right == NULL)
		return root;

	// Find predecessor if it exists
	if (root->left != NULL)  {
		// Find predecessor of root (Rightmost child in left subtree)
		struct node* l = createThreaded(root->left);

		// Link a thread from predecessor to root.
		l->right = root;
		l->isThreaded = true;
	}

	// If current node is rightmost child
	if (root->right == NULL)
		return root;

	// Recur for right subtree.
	return createThreaded(root->right);
}

// A utility function to find leftmost node in a binary tree rooted with 'root'.
// This function is used in inOrder()
struct node *leftMost(struct node *root) {
	while (root != NULL && root->left != NULL)
		root = root->left;
	return root;
}

// Function to do inorder traversal of a threadded binary tree
void inOrder(struct node *root) {
	if (root == NULL) return;
	// Find the leftmost node in Binary Tree
	struct node *cur = leftMost(root);
	while (cur != NULL)	{
		printf("%d ", cur->key);

		// If this Node is a thread Node, then go to inorder successor
		if (cur->isThreaded)
			cur = cur->right;
		else // Else go to the leftmost child in right subtree
			cur = leftMost(cur->right);
	}
}

// A utility function to create a new node
struct node *newNode(int key) {
	struct node *temp = (struct node *) malloc (sizeof (struct node));
	temp->left = temp->right = NULL;
	temp->key = key;
	return temp;
}

int main()
{
	/*	 1
			/ \
		 2   3
		/ \ / \
	  4 5 6 7 */
	struct node *root = (struct node * ) malloc(sizeof (struct node));
  root->key = 1;
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);

	createThreaded(root);

	printf("Inorder traversal of created threaded tree is\n");
	inOrder(root);
	return 0;
}
/*

observations :

Threaded Binary Tree: The code implements the conversion of a binary tree into a threaded binary tree. In a threaded binary tree, the right child pointer of a leaf node is used to store a pointer to its in-order successor, which allows for efficient in-order traversal.

Node Structure: The struct node defines a node in the binary tree. It includes an integer key, pointers to the left and right children, and a boolean flag isThreaded, which indicates whether the right pointer is a normal right pointer or a pointer to the in-order successor.

Threaded Conversion Function: The createThreaded function recursively traverses the binary tree and establishes threads between nodes where necessary. It finds the predecessor of each node (the rightmost child in its left subtree) and links it to the node if it exists. Then, it recursively processes the right subtree.

In-order Traversal: The inOrder function performs an in-order traversal of the threaded binary tree. It starts from the leftmost node and prints each node's key value. If a node is threaded (indicating it does not have a right child), it moves to its in-order successor using the thread.

Utility Functions: The code includes utility functions such as leftMost to find the leftmost node in a subtree and newNode to create a new node with a given key value.

Main Function: In the main function, a binary tree is constructed with a specific structure. Then, it is converted into a threaded binary tree using the createThreaded function. Finally, the in-order traversal of the threaded tree is printed.

Dynamic Memory Allocation: Memory allocation is done using malloc to create new nodes, but there's no deallocation of memory using free in this code. It's essential to free allocated memory to avoid memory leaks.

Output: The code prints the in-order traversal of the threaded binary tree constructed from the provided binary tree structure.

Error Handling: The code lacks error handling for cases such as memory allocation failures or invalid inputs.

*/
