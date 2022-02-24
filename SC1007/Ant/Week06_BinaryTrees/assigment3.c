#include <stdio.h>
#include <stdlib.h>

#define MAX_N 120

typedef struct _btnode
{
    char id;
    struct _btnode *left;
    struct _btnode *right;
} BTNode;

void buildTree(BTNode **node, char *preO, char *postO);
void inOrder(BTNode *cur);
void preOrder(BTNode *cur);
void postOrder(BTNode *cur);

int main()
{
    char preO[MAX_N];
    char postO[MAX_N];
    scanf("%s", preO);
    scanf("%s", postO);

    BTNode *root = NULL;
    buildTree(&root, preO, postO);
    if (root == NULL)
        printf("error\n");
    preOrder(root);
    printf("\n");
    postOrder(root);
    printf("\n");

    inOrder(root);
    printf("\n");

    return 0;
}
void inOrder(BTNode *cur)
{
    if (cur == NULL)
        return;

    inOrder(cur->left);
    printf("%c", cur->id);
    inOrder(cur->right);
}
void preOrder(BTNode *cur)
{
    if (cur == NULL)
        return;

    printf("%c", cur->id);
    preOrder(cur->left);
    preOrder(cur->right);
}
void postOrder(BTNode *cur)
{
    if (cur == NULL)
        return;

    postOrder(cur->left);
    postOrder(cur->right);
    printf("%c", cur->id);
}

#include <string.h>
BTNode *buildBT(char *previous, char *next, int *count, int lP, int hP, int arraySize);

BTNode *buildBT(char *previous, char *next, int *count, int lP, int hP, int arraySize)
{
    if (lP > hP|| *count >= arraySize )
        return NULL;

    BTNode *cur = (BTNode *)malloc(sizeof(BTNode));

    cur->id = previous[*count];
    cur->left = NULL;
    cur->right = NULL;

    *count = *count + 1;

    if (lP == hP)
    {
        return cur;
    }

    int k = lP;

    while (k < hP)
    {
        if (previous[*count] == next[k])
            break;
        k = k + 1;
    }

    if (k <= hP)
    {

        printf("debug lp %d, k %d \n", lP, k);
        cur->left = buildBT(previous, next, count, lP, k, arraySize);

        printf("debug k %d , lp %d\n", k, hP);
        cur->right = buildBT(previous, next, count, k + 1, hP - 1, arraySize);
    }

    return cur;
}

void buildTree(BTNode **node, char *preO, char *postO)
{
    // Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail

    // Write your code here
    int charSize ;
    charSize = strlen(preO);
    int index;
    index = 0;
    *node = buildBT(preO, postO, &index, 0, charSize - 1, charSize);
    // Write your code here
}