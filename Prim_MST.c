#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define MAX_VERTICES 100
#define INF 1000

typedef struct GraphType {
    // 정점(노드)개수
    int n;
    // 인접행렬(가중치)
    int weight[MAX_VERTICES][MAX_VERTICES];
} GraphType;

// 선택된 노드들을 표시하는 배열
int selected[MAX_VERTICES];
// 거리를 표현하는 배열
int distance[MAX_VERTICES];

// 최소 거리값을 갖는 정점(노드) 반환하는 함수
// 정점(노드) 개수를 인자로 받음
int get_min_vertex(int n) {
    // 반환하는 변수: 정점 v
    // 반복문을 위한 인덱스 변수 : i
    int v,i;

    for(i=0; i<n; i++) {
        // 선택되지 않은 노드라면 배열에서 몇 번째 정점인지 값 넣어줌
        if(!selected[i]) {
            v = i;
            break;
        }
    }
    for(i=0; i<n; i++) {
        // 선택되지 않았고, i번째 노드의 거리보다 정점의 거리가 더 멀면
        if(!selected[i] && (distance[i] < distance[v])) {
            v = i;
        }
    }
    // 정점 반환
    return (v);
}

void prim(GraphType* g, int s) {
    int i, u, v;
    // 정점(노드) 개수만큼 반복
    for(u=0; u < g->n; u++) {
        // 우선 엄청 큰 값으로 초기화
        distance[u] = INF;
    }

    distance[s] = 0;
    // 정점(노드)개수 만큼 반복하며 가장 최소값을 가지는 정점을 찾아 변수에 대입
    for(i=0; i < g->n; i++) {
        u = get_min_vertex(g->n);
            selected[u] = TRUE;

        // 만약 최소값의 정점의 거리가 iNF면 그냥 끝
        if(distance[u] == INF) {
            return;
        }

        // INF 값이 아니라면 출력
        printf("정점 %d 추가\n", u+1);

        for(v=0; v < g->n; v++) {
            // 만약 가중치가 무한이 아니라면
            if(g->weight[u][v] != INF) {
                // 만약 선택되지 않은 정점이고, 가중치갑보다 거리값이 크면
                if(!selected[v] && g->weight[u][v] < distance[v]) {
                    distance[v] = g->weight[u][v];
                }
            }
        }
    }
}

int main(void) {
	GraphType g = { 10,
    // 1  2  3    4    5   6   7  8  9  10  
	{{ 0, 3, INF, INF, INF, 11, 12,INF,INF,INF },//1
	{ 3,  0, 5, 4, 1, 7, 8,INF,INF,INF },//2
	{ INF, 5, 0, 2, INF, INF, 6,5,INF,INF,},//3
	{ INF, 4, 2, 0, 13, INF, INF,14,INF,16},//4
	{ INF, 1, INF, 13, 0, 9, INF,INF,18,17 },//5
	{ 11,7, INF, INF, 9, 0,INF,INF,INF, INF },//6
	{ 12,8,6,INF,INF,INF,0,13,INF,INF }, //7
    {INF,INF,5,14,INF,INF,13,0,INF,15} , //8
    {INF,INF,INF,INF,18,INF,INF,INF,0,10}, //9
    {INF,INF,INF,16,17,INF,INF,15,10,0}
    }
	};
    printf("Prim MST Algorithm \n");
	prim(&g, 0);
	return 0;
}