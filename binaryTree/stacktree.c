#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
}treenode;

#define SIZE 100
int top = -1;
treenode* stack[SIZE];

// push
void push(treenode* p) {
	if (top < SIZE - 1 && p != NULL)
		stack[++top] = p;
}
// pop
treenode* pop() {
	treenode* p = NULL;
	if (top >= 0)
		p = stack[top--];
	return p;
}

// 전위순회
void preorder_iter(treenode* root) {
	push(root);
	while (1) {
		root = pop();
		if (!root) break;
		printf("%d ", root->data);
		push(root->right);
		push(root->left);
	}
}
//중위 순회
void inorder_iter(treenode* root) {
	while (1) {
		for (; root; root = root->left)
			push(root);
		root = pop();
		if (!root) break;
		printf("%d ", root->data);
		root = root->right;
	}
}
// 후위 순회
void postorder_iter(treenode* root) {
	while (1) {
		do {
			if (root->data != NULL && root != NULL) {
				push(root);
				root = root->left;
			}
			else {
				break;
			}
		} while (root != NULL);
		root = pop();

		if (!root) break;
		if (root->right != NULL) {
			if (root->right->data == NULL)
			{
				printf("%d ", root->data);
				root->data = NULL;
			}
			else {
				push(root);
				root = root->right;
			}
		}
		else {
			printf("%d ", root->data);
			root->data = NULL;
		}
	}
}


// 메인 함수
int main(void) {
	treenode* n1, * n2, * n3, * n4, * n5, * n6, * n7, * n8, * n9, * n10, * n11;
	n1 = (treenode*)malloc(sizeof(treenode));
	n2 = (treenode*)malloc(sizeof(treenode));
	n3 = (treenode*)malloc(sizeof(treenode));
	n4 = (treenode*)malloc(sizeof(treenode));
	n5 = (treenode*)malloc(sizeof(treenode));
	n6 = (treenode*)malloc(sizeof(treenode));
	n7 = (treenode*)malloc(sizeof(treenode));
	n8 = (treenode*)malloc(sizeof(treenode));
	n9 = (treenode*)malloc(sizeof(treenode));
	n10 = (treenode*)malloc(sizeof(treenode));
	n11 = (treenode*)malloc(sizeof(treenode));

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

	treenode* root = n1;
	printf("<Traversal with Stack> \n");
	printf("1. 전위 순회 \n");
	preorder_iter(root);
	printf("\n");
	printf("2. 중위 순회 \n");
	inorder_iter(root);
	printf("\n");
	printf("3. 후위 순회 \n");
	postorder_iter(root);
	
	return 0;
}