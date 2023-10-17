#include <stdio.h>
#include <stdlib.h>

// 값으로 줄 주소을 저장할 포인터 변수 a,b 파라미터로 설정
void swap(int* a, int* b) {
    // 두 주소값을 스왑
    int temp = *a;
    *a = *b;
    *b = temp;
}

void getMaxNum(int arr[], int n, int i) {
    // 초기값으로 가장 큰 값을 넣어두기
    int largest = i;
    // 가장 큰 값의 왼쪽 오른쪽
    int left = 2*i + 1;
    int right = 2*i + 2;

    // 가장 큰 원소의 인덱스 값 갱신
    if(left<n && arr[left]>arr[largest])
        largest = left;
    if(right<n && arr[right]>arr[largest])
        largest = right;
    // 갱신 이후에 현재 최댓값이 인자로 넘어온 i 값이 아닌 경우에
    if(largest != i)
    {
        swap(&arr[i], &arr[largest]);
        getMaxNum(arr, n, largest);
    }   
}


void heapSort(int arr[], int n) {
    // 최대-힙 구성
    for(int i= n/2-1; i>=0; i--) {
        getMaxNum(arr, n, i);
    }

    // 최대 힙을 이용해 정렬 수행
    for (int i = n - 1; i > 0; i--) {
        // 루트(최댓값)을 현재 인덱스 i와 교환
        swap(&arr[0], &arr[i]);
        // 남은 배열을 최대 힙으로 유지
        getMaxNum(arr, i, 0);

        // 정렬 과정을 출력
        for (int j = 0; j < n; j++) {
            printf("%d ", arr[j]);
        }
        printf("\n");
    }
}

int main() {
    // 정렬하기 위해 다룰 데이터 선언
    int array[] = {34, 12, 76, 59, 32, 55, 88, 26, 16, 79, 34, 85, 29, 78, 41, 56, 86 };
    // 배열의 사이즈 구한 값
    int size = sizeof(array) / sizeof(array[0]);

    printf("<정렬>\n");
    heapSort(array, size);
    printf("\n");

    printf("최종 결과물 : ");
    for(int i=0; i<size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}