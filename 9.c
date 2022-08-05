#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode//定义一个AVL的结构体
{
    int data;
    int height;
    struct TreeNode *lchild;
    struct TreeNode *rchild;
} TreeNode;

int getHeight(TreeNode *node)//得到一颗树的高度
{
    return node ? node->height : 0;
}

int Max(int a, int b)//取最大值
{
    return a > b ? a : b;
}

void rrRotation(TreeNode *node, TreeNode **root)//LL树的情况
{
    TreeNode *temp = node->rchild;
    node->rchild = temp->lchild;
    temp->lchild = node;
    node->height = Max(getHeight(node->lchild), getHeight(node->rchild)) + 1;
    temp->height = Max(getHeight(temp->lchild), getHeight(temp->rchild)) + 1;
    *root = temp;
}

void llRotation(TreeNode *node, TreeNode **root)//RR树的情况
{
    TreeNode *temp = node->lchild;
    node->lchild = temp->rchild;
    temp->rchild = node;
    node->height = Max(getHeight(node->lchild), getHeight(node->rchild)) + 1;
    temp->height = Max(getHeight(temp->lchild), getHeight(temp->rchild)) + 1;
    *root = temp;
}

void avlInsert(TreeNode **T, int data)//进行插入
{
    if (*T == NULL)
    {
        *T = (TreeNode *)malloc(sizeof(TreeNode));
        (*T)->data = data;
        (*T)->height = 0;
        (*T)->lchild = NULL;
        (*T)->rchild = NULL;
    }
    else if (data < (*T)->data)
    {
        avlInsert(&(*T)->lchild, data);
        // 拿到当前节点左右子树的高度
        int lHeight = getHeight((*T)->lchild);
        int rHeight = getHeight((*T)->rchild);
        // 判断高度差
        if (lHeight - rHeight == 2)
        {
            if (data < (*T)->lchild->data)
            {
                // LL 调整
                llRotation(*T, T);
            }
            else
            {
                // LR 调整
                rrRotation((*T)->lchild, &(*T)->lchild);
                llRotation(*T, T);
            }
        }
    }
    else if (data > (*T)->data)
    {
        avlInsert(&(*T)->rchild, data);
        // 拿到当前节点左右子树的高度
        int lHeight = getHeight((*T)->lchild);
        int rHeight = getHeight((*T)->rchild);
        // 判断高度差
        if (rHeight - lHeight == 2)
        {
            if (data > (*T)->rchild->data)
            {
                // RR 调整
                rrRotation(*T, T);
            }
            else
            {
                // RL 调整
                llRotation((*T)->rchild, &(*T)->rchild);
                rrRotation(*T, T);
            }
        }
    }
    (*T)->height = Max(getHeight((*T)->lchild), getHeight((*T)->rchild)) + 1;
}

void preOrder(TreeNode *T)
{
    if (T)
    {
        printf("%d ", T->data);
        preOrder(T->lchild);
        preOrder(T->rchild);
    }
}

int main()
{
    TreeNode *T = NULL;
    int nums[5] = {1, 8, 9, 7, 10};
    for (int i = 0; i < 5; i++)
    {
        avlInsert(&T, nums[i]);
    }
    preOrder(T);
    printf("\n");
}