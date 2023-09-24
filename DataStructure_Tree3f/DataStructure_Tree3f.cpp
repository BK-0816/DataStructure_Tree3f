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
    int count = 0; //node�� ���� null�� �ƴϸ� +1�� ī��Ʈ
    if (node != NULL)
        count = 1 + get_node_count(node->left) +
        get_node_count(node->right);
    return count;
}

// ���� ��� �Լ�, root �� null�� �ƴϸ� root�� �����͸� �˻���
//�ڽ��� ���� ����� ��� ����� �����͸� �ٷ� ����, �׷��� �ʴٸ� ���� ����Ʈ���� ������ ����Ʈ���� ��������� �˻�
double evaluate(TreeNode* root) {
    if (root == NULL) return 0.0;
    if (root->left == NULL && root->right == NULL)
        return root->data;
    else {
        double op1 = evaluate(root->left);
        double op2 = evaluate(root->right);
        double result;
        printf("%.2f %c %.2f =", op1, root->data, op2);

        if (root->data == '+') //if������ ���갪 ����
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
    printf("������ ���� %.2f�Դϴ�. \n", evaluate(exp));
    printf("�� ����� ������ %d�Դϴ�.\n", get_node_count(exp));
    return 0;
}