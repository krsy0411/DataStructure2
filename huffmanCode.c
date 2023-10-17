#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200;

// 구조체 선언 : 노드, 원소, 힙타입
typedef struct {
    int weight;
    char ch;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

typedef struct {
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
    element temp = h->heap[(h->heap_size_)--];
    int parent = 1;
    int child = 2;

    while(child <= h->heap_size) {
        // 현재 노드의 자식노드 중 더 작은 자식노드를 서칭
        // 
        if((child <= h->heap_size) && (h->heap[child].key) > (h->heap[child+1].key))
            child++;
        if((temp.key < h->heap[child].key))
            break;
        
        // 한 단계 아래로 이동
        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }
}

int main() {
    return 0;
}