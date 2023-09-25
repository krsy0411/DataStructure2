#include <stdio.h>
#include <stdlib.h>

typedef struct struct node {
    int data;
    struct struct node *left, *right;
} struct node;

// 배열 표현법
struct node n1 = {2.0, NULL, NULL};
struct node n2 = {3.0, NULL, NULL};
struct node n3 = {'+', &n1, &n2};
struct node n4 = {4.0, NULL, NULL};
struct node n5 = {5.0, NULL, NULL};
struct node n6 = {'*', &n4, &n5};
struct node n7 = {'+', &n3, &n6};
struct node n8 = {6.0, NULL, NULL};
struct node n9 = {7.0, NULL, NULL};
struct node n10 = {'/', &n8, &n9};
struct node n11 = {'-', &n7, &n10};
struct node n12 = {9.0, NULL, NULL};
struct node n13 = {'+', &n11, &n12};
struct node *root = &n13;

//수식 계산 함수
float evaluation(struct node *root) {
    // 만약 루트가 null이면 0 출력
    if(root == NULL)
        return 0;
    // 왼쪽과 오른쪽 모두 null인 경우 : 루트는 데이터를 가리킴
    if(root -> left == NULL && root->right == NULL)
        return root->data;
    else {
        float op1 = evaluation(root->left);
        float op2 = evaluation(root->right);
        

        switch(root->data) {
            case '+':
                printf("%.2f %c %.2f = %.2f\n", op1, root->data, op2 , op1+op2);
                return op1 + op2;
            case '-':
                printf("%.2f %c %.2f = %.2f\n", op1, root->data, op2 , op1-op2);
                return op1 - op2;
            case '*':
                printf("%.2f %c %.2f = %.2f\n", op1, root->data, op2 , op1*op2);
                return op1 * op2;
            case '/':
                printf("%.2f %c %.2f = %.2f\n", op1, root->data, op2 , op1/op2); 
                return op1 / op2;
        }
    }
    return 0;
}

int node_cnt(struct node *root) {
    int cnt = 0;
    // 만약 노드가 null이 아니라면 left와 카운트와 right의 카운트를 더해줍니다.
    if(root != NULL) {
        cnt = 1 + node_cnt(root->left) + node_cnt(root->right);
    }
    return cnt;
}

// 메인함수
int main() {
    printf("수식의 값은 %.2f입니다. \n", evaluation(root));
    printf("총 노드의 개수는 %d개 입니다. \n", node_cnt(root));
    return 0;
}