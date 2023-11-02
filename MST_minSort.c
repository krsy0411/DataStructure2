#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define MAX_VERTICES 100
#define INF 1000

int parent[MAX_VERTICES];

// 초기화
void set_init(int n)
{
    for (int i = 0; i < n; i++)
        parent[i] = -1;
}
// curr가 속하는 집합을 반환한다.
int set_find(int curr)
{
    if (parent[curr] == -1)
        return curr; // 루트
    while (parent[curr] != -1)
        curr = parent[curr];
    return curr;
}
// 두개의 원소가 속한 집합을 합친다.
void set_union(int a, int b)
{
    int root1 = set_find(a); // 노드 a의 루트를 찾는다.
    int root2 = set_find(b); // 노드 b의 루트를 찾는다.
    if (root1 != root2) // 합한다.
        parent[root1] = root2;
}

// 간선을 나타내는 구조체
struct Edge {
    int start, end, weight;
};

typedef struct GraphType {
    int n; // 간선의 개수
    struct Edge edges[2 * MAX_VERTICES];
} GraphType;

// 초기화
void graph_init(GraphType *g)
{
    g->n = 0;
    for (int i = 0; i < 2 * MAX_VERTICES; i++) {
        g->edges[i].start = 0;
        g->edges[i].end = 0;
        g->edges[i].weight = INF;
    }
}
// 간선 삽입 연산
void insert_edge(GraphType *g, int start, int end, int w)
{
    g->edges[g->n].start = start;
    g->edges[g->n].end = end;
    g->edges[g->n].weight = w;
    g->n++;
}

// 구조체로 표현된 간선을 나타내는 최소힙을 정의
struct MinHeap {
    struct Edge *arr;
    int capacity;
    int size;
};

// 최소힙의 초기화
struct MinHeap *createMinHeap(int capacity)
{
    struct MinHeap *minHeap = (struct MinHeap *)malloc(sizeof(struct MinHeap));
    minHeap->capacity = capacity;
    minHeap->size = 0;
    minHeap->arr = (struct Edge *)malloc(capacity * sizeof(struct Edge));
    return minHeap;
}

// 최소힙에 간선 추가
void insertEdgeToMinHeap(struct MinHeap *minHeap, struct Edge edge)
{
    if (minHeap->size == minHeap->capacity) {
        printf("MinHeap is full!\n");
        return;
    }

    minHeap->size++;
    int i = minHeap->size - 1;
    minHeap->arr[i] = edge;

    while (i != 0 && minHeap->arr[(i - 1) / 2].weight > minHeap->arr[i].weight) {
        // Swap the current element with its parent
        struct Edge temp = minHeap->arr[i];
        minHeap->arr[i] = minHeap->arr[(i - 1) / 2];
        minHeap->arr[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

// 최소힙 재조정
void minHeapify(struct MinHeap *minHeap, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < minHeap->size && minHeap->arr[left].weight < minHeap->arr[smallest].weight)
        smallest = left;

    if (right < minHeap->size && minHeap->arr[right].weight < minHeap->arr[smallest].weight)
        smallest = right;

    if (smallest != i) {
        // Swap the current element with the smallest child
        struct Edge temp = minHeap->arr[i];
        minHeap->arr[i] = minHeap->arr[smallest];
        minHeap->arr[smallest] = temp;
        minHeapify(minHeap, smallest);
    }
}

struct Edge extractMin(struct MinHeap *minHeap)
{
    if (minHeap->size <= 0) {
        struct Edge invalidEdge;
        invalidEdge.start = -1;
        invalidEdge.end = -1;
        invalidEdge.weight = INF;
        return invalidEdge;
    }
    if (minHeap->size == 1) {
        minHeap->size--;
        return minHeap->arr[0];
    }

    struct Edge minEdge = minHeap->arr[0];
    minHeap->arr[0] = minHeap->arr[minHeap->size - 1];
    minHeap->size--;
    minHeapify(minHeap, 0);

    return minEdge;
}

// kruskal의 최소 비용 신장 트리 프로그램
void kruskal(GraphType *g)
{
    int edge_accepted = 0; // 현재까지 선택된 간선의 수
    int uset, vset; // 정점 u와 정점 v의 집합 번호
    struct Edge e;

    set_init(g->n); // 집합 초기화

    // Create a minimum heap and insert all edges into it
    struct MinHeap *minHeap = createMinHeap(g->n);
    for (int i = 0; i < g->n; i++) {
        insertEdgeToMinHeap(minHeap, g->edges[i]);
    }

    printf("Kruskal MST Algorithm\n");
    while (edge_accepted < (g->n - 1)) // 간선의 수 < (n-1)
    {
        e = extractMin(minHeap);
        if (e.start == -1) {
            // No valid edge found
            break;
        }
        uset = set_find(e.start); // 정점 u의 집합 번호
        vset = set_find(e.end); // 정점 v의 집합 번호
        if (uset != vset) { // 서로 속한 집합이 다르면
            printf("Edge (%d,%d) Select %d\n", e.start, e.end, e.weight);
            edge_accepted++;
            set_union(uset, vset); // 두 개의 집합을 합친다.
        }
    }
    free(minHeap->arr);
    free(minHeap);
}

int main(void)
{
    GraphType *g;
    g = (GraphType *)malloc(sizeof(GraphType));
    graph_init(g);

    insert_edge(g, 1, 6, 11);
    insert_edge(g, 1, 2, 3);
    insert_edge(g, 1, 7, 12);
    insert_edge(g, 2, 6, 7);
    insert_edge(g, 6, 5, 9);
    insert_edge(g, 2, 5, 1);
    insert_edge(g, 2, 7, 8);
    insert_edge(g, 2, 3, 5);
    insert_edge(g, 3, 7, 6);
    insert_edge(g, 3, 8, 5);
    insert_edge(g, 7, 8, 13);
    insert_edge(g, 2, 4, 4);
    insert_edge(g, 3, 4, 2);
    insert_edge(g, 4, 8, 14);
    insert_edge(g, 4, 5, 13);
    insert_edge(g, 1, 7, 12);
    insert_edge(g, 4, 10, 16);
    insert_edge(g, 8, 10, 15);
    insert_edge(g, 5, 10, 17);
    insert_edge(g, 5, 9, 18);
    insert_edge(g, 9, 10, 10);

    kruskal(g);
    free(g);
    return 0;
}