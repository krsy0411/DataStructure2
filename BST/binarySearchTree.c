#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// initialize TreeNodes data
TreeNode* initNode(int data, TreeNode* leftChild, TreeNode* rightChild)
{
    TreeNode* node = (TreeNode*) malloc(sizeof(TreeNode));
    node->data = data;
    node->left = leftChild;
    node->right = rightChild;
    return NULL;
}

// menu : s
// 자기 자신보다 크면 오른쪽 자식, 작으면 왼쪽 자식
TreeNode* searchNode(TreeNode* root, int searchValue)
{
    // 마지막에 방문노드들 출력하기 위한 배열
    int visitNode[20];
    // 방문한 노드의 수
    int cnt = 0;
    // 검색 성공 결과
    int searchData = 0;
    TreeNode* p = root;
    for(int i=0; i<sizeof(visitNode); i++)
    {
        if(p->data == searchValue)
        {
            searchData = p->data;
            cnt++;
            visitNode[i] = p->data;
        }
        else if(p->data < searchValue)
        {
            p = p->right;
            cnt++;
            visitNode[i] = p->data;
        }
        else
        {
            p = p->left;
            cnt++;
            visitNode[i] = p->data;
        }
    }
    printf("검색 성공: %d", searchData);
    printf("방문한 노드의 수: %d", cnt);
    for(int j=0; j<sizeof(visitNode); j++)
    {
        printf("%d ", visitNode[j]);
    }
    printf("\n");
    return NULL;
}

// menu : i
// 재귀함수 형태
TreeNode* insertNode(TreeNode* root, int insertData)
{
    // 마지막에 방문노드들 출력하기 위한 배열
    int visitNode[20];
    // 방문한 노드의 수
    int cnt = 0;
    for(int i=0; i<sizeof(visitNode); i++)
    {
        if (insertData > root->data)
        {
            root->right = insertNode(root->right, insertData);
            cnt++;
            visitNode[i] = root->data;
        }
        else if (insertData < root->data)
        {
            root->left = insertNode(root->left, insertData);
            cnt++;
            visitNode[i] = root->data;
        }
    }
    printf("방문한 노드의 수: %d", cnt);
    printf("\n");
    for(int i=0; i<sizeof(visitNode); i++)
    {
        printf("%d ", visitNode[i]);
    }
    printf("\n");
    return NULL;
}

// menu : d 
// 재귀함수
TreeNode* FindMinNode(TreeNode* node, TreeNode* minNode)
{
    if(node->left == NULL)
    {
        minNode = node;
        node = node->right;
        return node;
    }
    else
    {
        node->left = FindMinNode(node->left, minNode);
        return node;
    }
}

TreeNode* deleteNode(TreeNode* node, int data)
{
    // 만약 지울 노드가 없는 경우
    if(node == NULL) return NULL;
    // 입력받은 값이 노드의 데이터값과 일치하는 경우
    if(node->data == data)
    {
        TreeNode* deleteNode = node;
        if(node->left == NULL && node->right == NULL)
        {
            node = NULL;
        }
        else if(node->left != NULL && node->right == NULL)
        {
            node = node->left;
        }
        else if(node->left == NULL && node->right != NULL)
        {
            node = node->right;
        }
        else
        {
            TreeNode* minNode = NULL;
            node->right = FindMinNode(node->right, minNode);
            minNode->left = deleteNode->left;
            minNode->right = deleteNode->right;
            node = minNode;
        }
        
        free(deleteNode);
        return node;
    }
    // 일치하지 않는 경우
    else
    {
        if(node->data > data)
        {
            node->left = deleteNode(node->left, data);
        }
        else
        {
            node->right = deleteNode(node->right, data);
        }
        
        return node;
    }
}

int main() {
    bool conditionLoop = true;
    // initialize
    TreeNode* n14 = initNode(64, NULL, NULL);
    TreeNode* n13 = initNode(62, NULL, NULL);
    TreeNode* n12 = initNode(42, NULL, NULL);
    TreeNode* n11 = initNode(70, NULL, NULL);
    TreeNode* n10 = initNode(63, n13, n14);
    TreeNode* n9 = initNode(55, NULL, NULL);
    TreeNode* n8 = initNode(46, n12, NULL);
    TreeNode* n7 = initNode(25, NULL, NULL);
    TreeNode* n6 = initNode(65, n10, n11);
    TreeNode* n5 = initNode(53, n8, n9);
    TreeNode* n4 = initNode(16, NULL, n7);
    TreeNode* n3 = initNode(74, n6, NULL);
    TreeNode* n2 = initNode(41, n4, n5);
    TreeNode* n1 = initNode(60, n2, n1);

    printf("-----------------------------");
    printf("| s : 검색                    |");
    printf("| i : 노드 추가                |");
    printf("| d : 노드 삭제                |");
    printf("| t : 중위 순회                |");
    printf("| I : 노드 추가(반복)           |");
    printf("| D : 노드 삭제(반복)           |");
    printf("| c : 종료                    |");
    printf("-----------------------------");

    while(conditionLoop) {
        // 반복문 한 번에 입력받을 메뉴와 검색할 값 변수 새로 생성
        char menu_input;
        int searchValue = 0;

        printf("메뉴 입력: ");
        scanf("%c", &menu_input);
        printf("\n");
        switch(menu_input)
        {
            case 'c':
                // exit while loop
                conditionLoop = false;
                break;
            case 's':
                printf("검색할 값 입력: ");
                scanf("%d", &searchValue);
                printf("\n");
                searchNode(n1, searchValue);
                break;
            case 'i':
                printf("검색할 값 입력: ");
                scanf("%d", &searchValue);
                printf("\n");
                insertNode(n1, searchValue);
                break;
            case 'd':
                printf("삭제할 값 입력:");
                scanf("%d", &searchValue);
                printf("\n");
                deleteNode(n1, searchValue);
                break;
            case 't':
                break;
            case 'I':
                break;
            case 'D':
                break;

        }
    }
}