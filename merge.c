#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_NUM  20
int sorted[20];
int comparisons = 0; //비교 횟수 변수 선언
int movements = 0;  //이동 횟수 변수 선언
//리스트 초기화 함수
int merge_compare[MAX_NUM], merge_move[MAX_NUM];
void init_list(int arr[]) {
    for (int i = 0; i < 20; i++) {
        arr[i] = 0;
    }
}

// 랜덤으로 난수 20개 함수
void RandomArray(int arr[]) {
	for (int i = 0; i < 20; i++) {
		arr[i] = rand() % 100; //0부터 99까지의 난수를 생성한 후 리스트에 저장
	}
}
// 배열 출력 함수
void printArray(int arr[]) {
	for (int i = 0; i < 20; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void merge(int list[], int start, int k, int finish,int count  ){

    int start_num ,result;
    start_num = start; //분할된 리스트의 출발점
    result = start; //합체된 리스트의 출발점
    int middle = k +1 ; //중간 인덱스

    //작은 순서대로 배열에 삽입된다.
    while(start_num<=k && middle <=finish){ //start -> k 까지 , middle -> finish까지    
        if(list[start_num] <= list [middle]){
            comparisons++;
            sorted[result++] = list[start_num++];}
        else{
            comparisons++;
            sorted[result++] = list[middle++];
        }
    }

    // start_num 모든 인덱스를 넣었다면 k를 넣는다.
    if(start_num>k){
        movements++;
        for(int i=middle ; i<=finish; i++){
            sorted[result++] = list[result];
        }
    }
    //k 모든 값이  끝났다면start_num 인덱스를 넣어준다.
    else{
        movements++;
        for(int i=start_num ; i<=k; i++){
            sorted[result++] = list[i];
        }
    }
    //배열 sorted[]의 리스트를 배열 list[]로 재배열한다.
    for(int i =start; i<=finish; i++){
        movements++;
        list[i] = sorted[i];
    }
    for (int i = 0; i < 19 + 1; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");
    merge_compare[count] = comparisons;
    merge_move[count] = movements;
}

//
void merge_sort(int list[] , int start , int finish , int count){
    int k;
    
    if(start < finish){
        k = (start+finish)/2; //k : 중간 원소의 인덱스
        merge_sort(list,start,k,count); //앞부분 재귀 호출
        merge_sort(list,k+1,finish,count);  //뒷부분 재귀호출
        merge(list,start,k , finish,count);  //합체
    }   
}
// 비교 횟수와 이동 횟수 평균 구하는 함수
void result(int move[], int compar[]) {
    int avg_move = 0;
    int avg_compare = 0;

    for (int i = 0; i < 20; i++) {
        avg_move += move[i];
        avg_compare += compar[i];
    }

    printf("평균 이동 횟수 : %d\n", (avg_move / 20));
    printf("평균 비교 횟수 : %d\n", (avg_compare / 20));
}

void main() { 
    int Merge_list[MAX_NUM] ;
    int count;
    RandomArray(Merge_list);
    printf("Original List\n");
    printArray(Merge_list);
    printf("\n");

    merge_sort(Merge_list, 0 , MAX_NUM-1,count);
    count++;
    for (int i = 0; i < 20; i++) {
        //선택 정렬
        init_list(Merge_list);
        RandomArray(Merge_list); // 랜덤 리스트 생성
        merge_sort(Merge_list,0,MAX_NUM-1,count); // 선택 정렬 실행

    }
    result(merge_move, merge_compare);

}