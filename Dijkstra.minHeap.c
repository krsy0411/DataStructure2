#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 1000000

int distance[MAX_VERTICES];
int found[MAX_VERTICES];

typedef struct GraphNode {
	int node; 
	int weight; 
    // 다음 노드를 가리키는 변수
	struct GraphNode* link; 
} GraphNode;

typedef struct GraphType {
	int n; // 정점의 개수
	GraphNode* adj_list[MAX_VERTICES]; // 인접 리스트
} GraphType;

int choose(int distance[], int n, int found[])
{
	int i, min, minpos;
	min = INT_MAX;
	minpos = -1;
	for (i = 0; i < n; i++)
		if (distance[i] < min && !found[i]) {
			min = distance[i];
			minpos = i;
		}
	return minpos;
}

void print_status(GraphType* g)
{
	printf("distance: ");
	for (int i = 0; i < g->n; i++) {
		if (distance[i] == INF)
			printf(" * ");
		else
			printf("%2d ", distance[i]);
	}
	printf("\n");
	printf("found:    ");
	for (int i = 0; i < g->n; i++)
		printf("%2d ", found[i]);
	printf("\n");
}

void add_edge(GraphType* g, int start, int end, int weight)
{
	GraphNode* new_node = (GraphNode*)malloc(sizeof(GraphNode));
	new_node->node = end;
	new_node->weight = weight;
	new_node->link = g->adj_list[start];
	g->adj_list[start] = new_node;
}

void shortest_path(GraphType* g, int start)
{
	int i, u, w;
	GraphNode* p;
    int arr[10] ={1,};
	for (i = 0; i < g->n; i++) /* 초기화 */
	{
		distance[i] = INF;
		found[i] = FALSE;
	}
	distance[start] = 0;
	for (i = 0; i < g->n - 1; i++) {
		u = choose(distance, g->n, found);
		found[u] = TRUE;
        arr[i+1] = u+1;
		for (p = g->adj_list[u]; p != NULL; p = p->link) {
			w = p->node;
			if (!found[w])
				if (distance[u] + p->weight < distance[w])
					distance[w] = distance[u] + p->weight;
		}
        print_status(g);
	}
        for(int i = 0 ; i <10;i++){
        printf(" %d ", arr[i]);
    }
}

int main(void)
{
	GraphType g;
	g.n = 10;

	for (int i = 0; i < g.n; i++)
		g.adj_list[i] = NULL;

    printf("2. 연결리스트를 이용하여 구현하기\n");
	add_edge(&g, 0, 1, 3);
	add_edge(&g, 0, 5, 11);
	add_edge(&g, 0, 6, 12);

	add_edge(&g, 1, 0, 3);
	add_edge(&g, 1, 2, 5);
	add_edge(&g, 1, 3, 4);
	add_edge(&g, 1, 4, 1);
	add_edge(&g, 1, 5, 7);
	add_edge(&g, 1, 6, 8);

	add_edge(&g, 2, 1, 5);
	add_edge(&g, 2, 3, 2);
	add_edge(&g, 2, 6, 6);
	add_edge(&g, 2, 7, 5);

	add_edge(&g, 3, 1, 4);
	add_edge(&g, 3, 2, 2);
	add_edge(&g, 3, 4, 13);
	add_edge(&g, 3, 7, 14);
	add_edge(&g, 3, 9, 16);

	add_edge(&g, 4, 1, 1);
	add_edge(&g, 4, 3, 13);
	add_edge(&g, 4, 5, 9);
	add_edge(&g, 4, 8, 18);
	add_edge(&g, 4, 9, 17);

	add_edge(&g, 5, 0, 11);
	add_edge(&g, 5, 1, 7);
	add_edge(&g, 5, 4, 9);

	add_edge(&g, 6, 0, 12);
	add_edge(&g, 6, 1, 8);
	add_edge(&g, 6, 2, 6);
	add_edge(&g, 6, 7, 13);

	add_edge(&g, 7, 2, 5);
	add_edge(&g, 7, 3, 14);
	add_edge(&g, 7, 6, 13);
	add_edge(&g, 7, 8, 15);

	add_edge(&g, 8, 4, 18);
	add_edge(&g, 8, 7, 13);
	add_edge(&g, 8, 9, 15);

	add_edge(&g, 9, 4, 16);
	add_edge(&g, 9, 8, 10);

	shortest_path(&g, 0);

	return 0;
}