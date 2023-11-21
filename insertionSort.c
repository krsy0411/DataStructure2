#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//각 정렬의 비교와 이동 횟수를 넣은 리스트와 몇번 돌리는 지 확인하는 변수 선언
int count = 0;
// 선택 정렬
int s_compar[20];
int s_move[20];

// 랜덤으로 난수 20개를 만드는 함수
int RandomArray(int arr[]) {
	srand(time(NULL));
	for (int i = 0; i < 20; i++) {
		arr[i] = rand() % 100; //0부터 99까지의 난수를 생성한 후 리스트에 저장
	}

	return arr;
}

// 배열 출력 함수
void printArray(int arr[]) {
	for (int i = 0; i < 20; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

// 선택 정렬 함수
void selectionSort(int arr[], int count) {
    int comparisons = 0; //비교 횟수 변수
    int movements = 0; //이동 횟수 변수

    printf("Selection Sort\n");
    for (int i = 0; i < 19; i++) {
        int min_idx = i;
        //최솟값 비교
        for (int j = i + 1; j < 20; j++) {
            comparisons++; //비교 횟수 증가
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        // 값 교환
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
        movements++; //이동 횟수 증가

        for (int i = 0; i < 20; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
    s_compar[count] = comparisons;
    s_move[count] = movements;

    printf("\n");
    printf("Move Count : %d\n",movements);
    printf("Compare Count : %d\n",comparisons);
}


int main() {

    int s_list[20]; //선택 정렬 배열
    int i_list[20]; //삽입 정렬 배열
    int b_list[20]; //버블 정렬 배열
    int count = 0;
       
    RandomArray(s_list);
    printf("Original List\n");
    printArray(s_list);
    selectionSort(s_list,count);


	return 0;
}