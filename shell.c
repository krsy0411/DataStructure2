#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_SIZE 20

// gap만큼 떨어진 요소들을 삽입 정렬
// 정렬의 범위는 first에서 last까지
void inc_insertion_sort(int list[], int first, int last, int gap,int* MoveCount, int* CompareCount){
  int i, j, key;

  for(i=first+gap; i<=last; i=i+gap){
    key = list[i]; // 현재 삽입될 숫자인 i번째 정수를 key 변수로 복사
    (*CompareCount)++;
    // 현재 정렬된 배열은 i-gap까지이므로 i-gap번째부터 역순으로 조사한다.
    // j 값은 first 이상이어야 하고
    // key 값보다 정렬된 배열에 있는 값이 크면 j번째를 j+gap번째로 이동
    for(j=i-gap; j>=first && list[j]>key; j=j-gap){
      list[j+gap] = list[j]; // 레코드를 gap만큼 오른쪽으로 이동
      (*MoveCount)++;
    }
    (*MoveCount)++;
    list[j+gap] = key;
  }
}

// 셸 정렬
void shell_sort(int list[], int n ,int* MoveCount, int* CompareCount){
  int i, gap;

  for(gap=n/2; gap>0; gap=gap/2){
    if((gap%2) == 0){
      gap++; // gap을 홀수로 만든다.
    }

    // 부분 리스트의 개수는 gap과 같다.
    for(i=0; i<gap; i++){
      // 부분 리스트에 대한 삽입 정렬 수행
      inc_insertion_sort(list, i, n-1, gap,MoveCount,CompareCount);
    }
    for (int k = 0; k < n; k++) {
        printf("%d ", list[k]);
        }
        printf("\n");

  };
}

void main(){
  int i;
  int n = MAX_SIZE;
  int MoveCount = 0 ;
  int CompareCount =0;
int list[MAX_SIZE];
	srand(time(NULL));
    printf("Original List \n");
	for (i = 0; i<MAX_SIZE; i++)      	// 난수 생성 및 출력 
		list[i] = rand() % 100; // 난수 발생 범위 0~99

  // 정렬 전 출력
  for(i=0; i<n; i++){
    printf("%d ", list[i]);
  }
    printf("\n\n");
  // 셸 정렬 수행
printf("Shell Sort  \n");
  shell_sort(list, n ,&MoveCount, &CompareCount);
  printf("\nAverage Move Count :  %d ", MoveCount);
  printf("\nAverage Compare Count :  %d ", CompareCount);
}