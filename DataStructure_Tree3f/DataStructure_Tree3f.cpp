#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    char data;
    struct TreeNode* left, * right;
} TreeNode;

TreeNode n1 = { 4.0, NULL, NULL };
TreeNode n2 = { 5.0, NULL, NULL };
TreeNode n3 = { '*', &n1, &n2 };
TreeNode n4 = { 3.0, NULL, NULL };
TreeNode n5 = { '+', &n3, &n4 };
TreeNode n6 = { 2.0, NULL, NULL };
TreeNode n7 = { '+', &n5, &n6 };
TreeNode n8 = { 6.0, NULL, NULL };
TreeNode n9 = { 7.0, NULL, NULL };
TreeNode n10 = { '/', &n8, &n9 };
TreeNode n11 = { '-', &n7, &n10 };
TreeNode n12 = { 9.0, NULL, NULL };
TreeNode n13 = { '+', &n11, &n12 };


TreeNode* exp = &n13;
int get_node_count(TreeNode* node)
{
    int count = 0; //node의 값이 null이 아니면 +1씩 카운트
    if (node != NULL)
        count = 1 + get_node_count(node->left) +
        get_node_count(node->right);
    return count;
}

// 수식 계산 함수, root 가 null이 아니면 root의 데이터를 검사함
//자식이 없는 노드일 경우 노드의 데이터를 바로 리턴, 그렇지 않다면 왼쪽 서브트리와 오른쪽 서브트리를 재귀적으로 검사
double evaluate(TreeNode* root) {
    if (root == NULL) return 0.0;
    if (root->left == NULL && root->right == NULL)
        return root->data;
    else {
        double op1 = evaluate(root->left);
        double op2 = evaluate(root->right);
        double result;
        printf("%.2f %c %.2f =", op1, root->data, op2);

        if (root->data == '+') //if문으로 연산값 리턴
            result = op1 + op2;
        else if (root->data == '-')
            result = op1 - op2;
        else if (root->data == '*')
            result = op1 * op2;
        else if (root->data == '/')
            result = op1 / op2;
        else
            result = 0.0;
        printf(" %.2f\n", result);
        return result;
    }
}

int main(void) {
    printf("수식의 값은 %.2f입니다. \n", evaluate(exp));
    printf("총 노드의 갯수는 %d입니다.\n", get_node_count(exp));
    return 0;
}