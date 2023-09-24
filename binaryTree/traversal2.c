#include <stdio.h>
#include <stdlib.h>


struct node {
	int data;
	struct node* left;
	struct node* right;
};

void printInorder(struct node* node)
{
	if (node == NULL) return;
	printInorder(node->left);
	printf("%d ", node->data);
	printInorder(node->right);
}
struct node* parent(struct node* root, int key)
{
	if (root == NULL || root->data == key)
		return root;
	if (root->data < key)
		return parent(root->right, key);
	return parent(root->left, key);
}

void main()
{
	struct node* n1, * n2, * n3, * n4, * n5, * n6, * n7, * n8, * n9, * n10, * n11;
	n1 = (struct node**)malloc(sizeof(struct node*));
	n2 = (struct node**)malloc(sizeof(struct node*));
	n3 = (struct node**)malloc(sizeof(struct node*));
	n4 = (struct node**)malloc(sizeof(struct node*));
	n5 = (struct node**)malloc(sizeof(struct node*));
	n6 = (struct node**)malloc(sizeof(struct node*));
	n7 = (struct node**)malloc(sizeof(struct node*));
	n8 = (struct node**)malloc(sizeof(struct node*));
	n9 = (struct node**)malloc(sizeof(struct node*));
	n10 = (struct node**)malloc(sizeof(struct node*));
	n11 = (struct node**)malloc(sizeof(struct node*));

	n1->data = 1;
	n1->left = n2;
	n1->right = n7;

	n2->data = 2;
	n2->left = n3;
	n2->right = n6;

	n3->data = 3;
	n3->left = n4;
	n3->right = n5;

	n4->data = 4;
	n4->left = NULL;
	n4->right = NULL;

	n5->data = 5;
	n5->left = NULL;
	n5->right = NULL;

	n6->data = 6;
	n6->left = NULL;
	n6->right = NULL;

	n7->data = 7;
	n7->left = n8;
	n7->right = n9;

	n9->data = 9;
	n9->left = n10;
	n9->right = n11;

	n10->data = 10;
	n10->left = NULL;
	n10->right = NULL;

	n11->data = 11;
	n11->left = NULL;
	n11->right = NULL;

	n8->data = 8;
	n8->left = NULL;
	n8->right = NULL;


	struct node* root = n1;

	printf("1. 중위 순회 결과\n");
	printInorder(root);
	printf("\n");
	printf("2. Node 4의 부모: %p\n", parent(root, 4));
	printf("3. Node 5의 부모: %p\n", parent(root, 5));
	printf("4. Node 6의 부모: %p\n", parent(root, 6));
}