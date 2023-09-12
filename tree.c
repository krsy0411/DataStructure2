#include <stdio.h>
#include <stdlib.h> 
// 링크 표현법
typedef struct node_struct{
	int data;
	struct node_struct *left;
	struct node_struct *right;
}node;
// 자기 참조 구조체 

node* insert_node(node* root, int value) // 트리에 값 삽입하기
{
	if(root==NULL)
	{
		root=(node *)malloc(sizeof(node)); // 메모리 할당하기
		root->left = root->right = NULL;
		root->data = value;
	}
	else 
	{
		if(root->data > value) root->left = insert_node(root->left, value); 
        // root->data(부모노드)보다 value가 작으면 왼쪽으로 삽입한다.
		else root->right = insert_node(root->right, value);
        // root->data(부모노드)보다 value가 크면 오른쪽으로 삽입한다.
	}
	return root;
} 

void pre(node* root) // 트리 출력하기 : 전위 순회  
{
	if(root)
	{
		printf("%d ", root->data);
		pre(root->left);
		pre(root->right);
	}
}

void ino(node* root) // 트리 출력하기 : 중위 순회
{
	if(root)
	{
		ino(root->left);
		printf("%d ", root->data);
		ino(root->right);
	}
}

void pos(node* root) // 트리 출력하기 : 후위 순회
{
	if(root)
	{
		pos(root->left);
		pos(root->right);
		printf("%d ", root->data);
	}
}

// 배열 표현법
#define MAX_SIZE = 11
typedef struct Tree_Node
{
  int data;
} Tree_Node;
struct Tree
{
  Tree_Node TreeArray[MAX_SIZE];
  int cur = 1;
}


// 실행 함수
int main()
{
	node *root = NULL;
  // 값 삽입
  int i;
  for(i=0; i<11; i++) {
    root = insert_node(root, i);
  }
	
	printf("  이진트리 전위 순회 : ");
	pre(root);
	printf("\n\n");
	
	printf("  이진트리 중위 순회 : "); 
	ino(root);
	printf("\n\n");
	
	printf("  이진트리 후위 순회 : ");
	pos(root);
	
	free(root); // 메모리 초기화

	return 0;
}