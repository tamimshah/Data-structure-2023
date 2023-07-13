#include<stdio.h>
#include<stdlib.h> //ID. 222-35-1141
struct node {     //MD. TAHMID SHAH TAMIM
int data;
struct node *left;
struct node *right;
};
struct node *new_node(int data) {
struct node *node = (struct node *)malloc(sizeof(struct node));
node->data = data;
node->left = NULL;
node->right = NULL;
return node;
}
void insert(struct node **root, int data) {
if (*root == NULL) {
*root = new_node(data);
} else {
if (data < (*root)->data) {
insert(&(*root)->left, data);
} else { insert(&(*root)->right, data);
}
}
}
void delete_node(struct node **root, int data) {
if (*root == NULL) {
return;
}
if (data < (*root)->data) {
delete_node(&(*root)->left, data);
} else if (data > (*root)->data) {
delete_node(&(*root)->right, data);
} else {
if ((*root)->left == NULL && (*root)->right == NULL) {
free(*root);
*root = NULL;
} else if ((*root)->left == NULL) {
struct node *temp = *root;
*root = (*root)->right;
free(temp);
} else if ((*root)->right == NULL) {
struct node *temp = *root;
*root = (*root)->left;
free(temp);
} else {
struct node *min_node = (*root)->right;
while (min_node->left != NULL) {
min_node = min_node->left;
}
(*root)->data = min_node->data;
delete_node(&(*root)->right, min_node->data);
}
}
}
void inorder_traversal(struct node *root) {
if (root == NULL) {
return;
}
inorder_traversal(root->left);
printf("%d ", root->data);
inorder_traversal(root->right);
}
int main() {
struct node *root = NULL;
insert(&root, 10);
insert(&root, 5);
insert(&root, 15); insert(&root, 2);
insert(&root, 7);
insert(&root, 12);
printf("Inorder traversal: ");
inorder_traversal(root);
printf("\n");
delete_node(&root, 10);
printf("Inorder traversal after deleting 10: ");
inorder_traversal(root);
printf("\n");
return 0; }
