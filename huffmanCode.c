#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200

// 구조체 선언 : 노드, 원소, 힙타입
typedef struct TreeNode { 
    int weight;
    char ch;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

typedef struct element {
    TreeNode *ptree;
    char ch;
    int key;
} element;

typedef struct {
    element heap[MAX_ELEMENT];
    int heap_size;
} HeapType;

// 힙 생성, 초기화, 이진트리 생성함수
HeapType* create() {
    return (HeapType*)malloc(sizeof(HeapType));
}

void init(HeapType* h) {
    h->heap_size = 0;
}

TreeNode* make_tree(TreeNode* left, TreeNode* right) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->left = left;
    node->right = right;

    return node;
}

// 연산 함수들 : 삽입, 삭제, 소멸
// 힙에 원소 추가
void insert_heap(HeapType* h, element item) {
    // i를 힙 최대값 +1 로 초기화
    int i = ++(h->heap_size);

    // 트리를 거슬러 올라가면서 부모 노드와 비교
    // 인덱스가 루트가 아니거나 삽입할 아이템의 값이 부모 노드의 값보다 작으면 계속해서 진행
    while((i != 1) && (item.key < h->heap[i/2].key))
    {
        // 트리 거슬러 올라가기
        h->heap[i] = h->heap[i/2];
        // 인덱스 갱신
        i /= 2;
    }
    // 다 거슬러 올라가고 나면 노드 삽입
    h->heap[i] = item;
}

element delete_heap(HeapType* h) {
    element item = h->heap[1];
    element temp = h->heap[(h->heap_size)--];
    int parent = 1;
    int child = 2;
    // 자식노드가 힙 사이즈보다 작을 동안에 반복
    while(child <= h->heap_size) {
        // 현재 노드의 자식노드 중 더 작은 자식노드를 서칭
        if((child <= h->heap_size) && (h->heap[child].key) > (h->heap[child+1].key))
            child++;
        if((temp.key < h->heap[child].key))
            break;
        
        // 한 단계 아래로 이동
        h->heap[parent] = h->heap[child];
        // 부모노드는 자식노드 위치로 가고
        parent = child;
        // 자식노드의 위치는 레벨 하나 아래로
        child *= 2;
    }
    h->heap[parent] = temp;
    return item;
}

void destroy_tree(TreeNode* root) {
    // 루트노드가 존재하지 않으면
    if(!root)
        return;
    // 왼쪽, 오른쪽 자식 노드들 트리 제거
    destroy_tree(root->left);
    destroy_tree(root->right);
}

int is_leaf(TreeNode* root) {
    // 왼/오 자식노드들이 존재하지 않으면 true
    return !(root->right) && !(root->right);
}

// print functions
void print_array(int codes[], int n) {
    for(int i=0; i<n; i++) {
        printf("%d", codes[i]);
    }
    printf("\n");
}

void print_codes(TreeNode* root, int codes[], int top) {
    if(root->left) {
        codes[top] = 1;
        print_codes(root->left, codes, top+1);
    }
    if(root->right) {
        codes[top] = 0;
        print_codes(root->right, codes, top+1);
    }
    if(is_leaf(root)) {
        printf("%c: ", root->ch);
        print_array(codes,top);
    }
}

// 허프만 코드 생성 함수
void huffman_tree(int freq[], char ch_list[], int n)
{
	int i;
	TreeNode *node, *x;
	HeapType* heap;
	element e, e1, e2;
	int codes[100];
	int top = 0;

	heap = create();
	init(heap);
	for (i = 0; i<n; i++) 
    {
		node = make_tree(NULL, NULL);
		e.ch = node->ch = ch_list[i];
		e.key = node->weight = freq[i];
		e.ptree = node;
		insert_heap(heap, e);
	}
	for (i = 1; i<n; i++) 
    {
		// 최소값을 가지는 두개의 노드를 삭제
		e1 = delete_heap(heap);
		e2 = delete_heap(heap);
		// 두개의 노드를 합침
		x = make_tree(e1.ptree, e2.ptree);
		e.key = x->weight = e1.key + e2.key;
		e.ptree = x;
		printf("%d+%d->%d \n", e1.key, e2.key, e.key);
		insert_heap(heap, e);
	}
	e = delete_heap(heap); // 최종 트리
	print_codes(e.ptree, codes, top);
	destroy_tree(e.ptree);
	free(heap);
}

int main() {
    char ch_list[] = {'i','s','e','u','t','o','a'};
    int freq[] = {12, 13, 15, 4, 1,3,10};
    huffman_tree(freq, ch_list, 7);

    return 0;
}