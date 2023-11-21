#include<stdio.h>
#include<stdlib.h>
#include<time.h>
// 인자값 스왑 정의
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )
#define MAX_SIZE 20


void selection_sort(int list[], int n, int* count, int* CompareCount) {
    int i, j, least, temp;

    for (i = 0; i < n - 1; i++) {
        least = i;
        // 최소값 찾아내기
        for (j = i + 1; j < n; j++) {
            if (list[j] < list[least]) {
                least = j, (*count)++;
            }
            (*CompareCount)++;
        }
        SWAP(list[i], list[least], temp);
        
        // 한 바퀴 돌때마다 배열의 현재 상태 출력
        for (int k = 0; k < n; k++) {
            printf("%d ", list[k]);
        }
        printf("\n");
    }
}

void main() {
	int i;
    int count= 0;
    int CompareCount= 0;
    int list[MAX_SIZE];

	srand(time(NULL));

    printf("Original List \n");
	for (i = 0; i<MAX_SIZE; i++) // 난수 생성 및 출력 
		list[i] = rand() % 100; // 난수 발생 범위 0~99

    //Original Code 
	for (i = 0; i<MAX_SIZE; i++)
		printf("%d ", list[i]);

    printf("\n\n Selection Sort \n");
	selection_sort(list,MAX_SIZE, &count, &CompareCount); // 선택정렬 호출 
	printf("\n");
    printf("Move Count : %d" , count);
    printf("\nCompare Count : %d" , CompareCount);

    printf("\n");
    for (i = 0; i<MAX_SIZE; i++)
		printf("%d ", list[i]);
}