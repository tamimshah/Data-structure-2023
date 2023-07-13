// C program to demonstrate insert operation in binary search tree
#include<stdio.h>
#include<stdlib.h>

struct node
{
     char key;
	struct node *left, *right;
};

// A utility function to create a new BST node
struct node *newNode(char item)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

// A utility function to do inorder traversal of BST
void inorder(struct node *root)
{
	if (root != NULL)
	{
		inorder(root->left);
		printf("%c \n", root->key);
		inorder(root->right);
	}
}


void print_preorder(struct node * root)
{
    if (root)
    {
        printf("%c\n",root->key);
        print_preorder(root->left);
        print_preorder(root->right);
    }

}

void print_postorder(struct node * root)
{
    if (root)
    {
        print_postorder(root->left);
        print_postorder(root->right);
        printf("%c\n",root->key);
    }
}
/* A utility function to insert a new node with given key in BST */
struct node* insert(struct node* node, char key)
{
	/* If the tree is empty, return a new node */
	if (node == NULL) return newNode(key);

	/* Otherwise, recur down the tree */
	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);

	/* return the (unchanged) node pointer */
	return node;
}

// Driver Program to test above functions
int main()
{
	/* Let us create following BST
			50
		/	 \
		30	 70
		/ \ / \
      20 40 60 80 */
	struct node *root = NULL;
	root = insert(root, 'F');

	insert(root, 'B');
	insert(root, 'A');
	insert(root, 'd');
	insert(root, 'C');
	insert(root, 'E');
insert(root, 'G');
	insert(root, 'I');
	insert(root, 'H');

	// print inoder traversal of the BST

	printf("\n\n\nPre Order\n");
	print_preorder(root);
	printf("Inorder\n");
	inorder(root);
	printf("\n\n\n Post Order\n");
	print_postorder(root);



	return 0;
}
