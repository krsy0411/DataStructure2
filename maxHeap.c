#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200

// 키값을 지는 원소 구조체
typedef struct {
    int key;
} element;

// 크기가 200이고, 히프의 원소 개수를 나타내는 heap_size 선언
typedef struct {
    element heap[MAX_ELEMENT];
    int heap_size;
} HeapType;

// 히프를 생성하고 공백으로 초기화하는 함수
HeapType* createHeap()
{
    HeapType* heap = (HeapType*)malloc(sizeof(HeapType));
    heap->heap_size = 0;
    return heap;
}

// 삽입 함수
void insert_max_heap(HeapType* heap, element item)
{
    // 말단 노드로 넣을 것의 인덱스값
    int i = ++(heap->heap_size);
    // 이동횟수 변수
    int cnt  = 0;

    // 말단노드에서부터 부모 노드와 비교해보기
    while((i != 1) && (item.key > heap->heap[i/2].key))
    {
        // 부모노드보다 값이 더 큰 경우 : 부모 노드 위치로 가리키기
        heap->heap[i] = heap->heap[i/2];
        i /= 2;
        cnt++;
        
    }
    // 다 비교하고 나서 : 새 노드를 실제로 삽입
    heap->heap[i] = item;
}

element delete_max_heap(HeapType* heap, element item)
{
    // 제거할 원소와 인덱스들 변수 선언
    element temp = heap->heap[(heap->heap_size)--];
    int delete_item_index, child_index;

    // 우선 제거할 원소의 인덱스를 찾기
    for(int i=1; i<=heap->heap_size; i++)
    {
        if(heap->heap[i].key == item.key)
        {
            // 만약 제거할 원소 찾으면 인덱스 저장
            delete_item_index = i;
            child_index = i*2;
        }
    }
    // 값 설정
    while(child_index <= heap->heap_size)
    {
        if((child_index < heap->heap_size) && (heap->heap[child_index].key < heap->heap[child_index+1].key))
        {
            child_index++;
        }
        if(temp.key >= heap->heap[child_index].key)
        {
            break;
        }
        heap->heap[delete_item_index] = heap->heap[child_index];
        delete_item_index = child_index;
        child_index *= 2;
    }
    heap->heap[delete_item_index] = temp;
    return item;
}

void print_max_heap(HeapType* heap)
{
    // 레벨별로 출력
    for(int i=1; i<=heap->heap_size; i++)
    {
        printf("%d ", heap->heap[i].key);
        if(i==1 || i==3 || i==7)
        {
            printf("\n");
        }
    }
    printf("\n");
}

int main(void)
{
    // 원소들 값 할당
    element e1={90}, e2={89}, e3={70}, e4={36}, e5={75}, e6={63}, e7={65}, e8={21}, e9={18}, e10={15};
    // 초기화
    HeapType* heap = createHeap();
    // 초기값 설정
    insert_max_heap(heap, e1);
    insert_max_heap(heap, e2);
    insert_max_heap(heap, e3);
    insert_max_heap(heap, e4);
    insert_max_heap(heap, e5);
    insert_max_heap(heap, e6);
    insert_max_heap(heap, e7);
    insert_max_heap(heap, e8);
    insert_max_heap(heap, e9);
    insert_max_heap(heap, e10);

    
    // 메뉴창 출력
    printf("--------------------\n");
    printf("| i: 노드 추가    |\n");
    printf("| d: 노드 삭제    |\n");
    printf("| p: 레벨별 출력  |\n");
    printf("| c: 종료        |\n");
    printf("--------------------\n");

    while(1) {
        // 입력받은 메뉴 저장해놓을 변수 선언
        char menu;
        // 입력받은 추가하거나 삭제할 값 저장해놓을 변수 선언
        int value;
        element E;  
        
        // 메뉴 알파벳 입력받기
        printf("메뉴 입력: ");
        scanf(" %c", &menu);
        printf("\n");

        switch(menu){
            case 'i':
                printf("추가할 값 입력: ");
                scanf("%d", &value);
                E.key = value;
                printf("\n");
                // 삽입 함수 실행
                insert_max_heap(heap, E);
                // 삽입된 후의 히프 내부 원소들 전체 출력
                for(int k=1;k<=heap->heap_size; k++)
                {
                    printf("%d ",heap->heap[k].key);
                }
                printf("\n");
                break;
            case 'd':
                printf("삭제할 값 입력: ");
                scanf("%d", &value);
                E.key = value;
                printf("\n");
                // 삭제 함수 실행
                delete_max_heap(heap, E);
                // 삭제된 후의 히프 내부 원소들 전체 출력
                for(int k=1;k<=heap->heap_size; k++)
                {
                    printf("%d ",heap->heap[k].key);
                }
                printf("\n");
                break;
            case 'p':
                printf("트리 레벨별 출력");
                printf("\n");
                print_max_heap(heap);
                break;
            default:
                break;
        }
        // 입력받은 알파벳이 c인 경우엔 while문도 탈출해서 완전 종료시키기
        if(menu == 'c') {
            break;
        }
    }
    // 동적할당된 메모리 사용 해제
    free(heap);
    return 0;
}