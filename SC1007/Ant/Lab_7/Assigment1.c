#include <stdio.h>
#include <stdlib.h>

typedef struct _btnode
{
    int item;
    struct _btnode *left;
    struct _btnode *right;
} BTNode;

typedef struct _queueNode
{
    BTNode *data;
    struct _queueNode *next;
} QueueNode;

typedef struct _queue
{
    int size;
    QueueNode *head;
    QueueNode *tail;
} Queue;

// Prototypes of Interface functions for Queue structure
void enqueue(Queue *qPtr, BTNode *data);
int dequeue(Queue *qPtr);
BTNode *getFront(Queue q);
int isEmptyQueue(Queue q);

BTNode *createNode(int item);
void printBTNode(BTNode *root, int space, int left);
void deleteTree(BTNode **root);

BTNode *findLargestBST(BTNode *root);

int main()
{
    BTNode *root = NULL;
    BTNode *temp = NULL;
    Queue q;
    q.head = NULL;
    q.tail = NULL;
    q.size = 0;

    int item;
    int flag = 1;
    printf("Enter a list of numbers for a Binary Tree, terminated by any non-digit character: \n");
    while (scanf("%d", &item))
    {
        if (root == NULL)
        {
            if (item != -1)
            {
                root = createNode(item);
                enqueue(&q, root);
            }
        }
        else
        {
            while (!isEmptyQueue(q))
            {
                temp = getFront(q);
                if (flag)
                {
                    if (item != -1)
                    {
                        temp->left = createNode(item);
                        enqueue(&q, temp->left);
                    }
                    flag = 0;
                    break;
                }
                else if (temp->right == NULL)
                {
                    if (item != -1)
                    {
                        temp->right = createNode(item);
                        enqueue(&q, temp->right);
                    }
                    dequeue(&q);
                    flag = 1;
                    break;
                }
                else
                    dequeue(&q);
            }
        }
    }
    scanf("%*s");
    printf("The input binary tree:\n");
    printBTNode(root, 0, 0);
    printf("\n");
    BTNode *BSTnode = findLargestBST(root);
    printf("The largest binary search subtree:\n");
    if (BSTnode)
        printBTNode(BSTnode, 0, 0);
    else
        printf("No BST\n");
    deleteTree(&root);

    return 0;
}

BTNode *createNode(int item)
{
    BTNode *node = (BTNode *)malloc(sizeof(BTNode));
    node->item = item;
    node->left = node->right = NULL;
    return node;
}

void printBTNode(BTNode *root, int space, int left)
{
    if (root != NULL)
    {

        int i;
        for (i = 0; i < space - 1; i++)
            printf("|\t");

        if (i < space)
        {
            if (left == 1)
                printf("|---");
            else
                printf("|___");
        }

        printf("%d\n", root->item);

        space++;
        printBTNode(root->left, space, 1);
        printBTNode(root->right, space, 0);
    }
}

void deleteTree(BTNode **root)
{
    if (*root != NULL)
    {
        deleteTree(&((*root)->left));
        deleteTree(&((*root)->right));
        free(*root);
        *root = NULL;
    }
}
void enqueue(Queue *qPtr, BTNode *data)
{
    QueueNode *newNode;
    newNode = malloc(sizeof(QueueNode));
    newNode->data = data;
    newNode->next = NULL;

    if (isEmptyQueue(*qPtr))
        qPtr->head = newNode;
    else
        qPtr->tail->next = newNode;

    qPtr->tail = newNode;
    qPtr->size++;
}

int dequeue(Queue *qPtr)
{
    if (qPtr == NULL || qPtr->head == NULL)
    { // Queue is empty or NULL pointer
        return 0;
    }
    else
    {
        QueueNode *temp = qPtr->head;
        qPtr->head = qPtr->head->next;
        if (qPtr->head == NULL) // Queue is emptied
            qPtr->tail = NULL;

        free(temp);
        qPtr->size--;
        return 1;
    }
}

BTNode *getFront(Queue q)
{
    return q.head->data;
}

int isEmptyQueue(Queue q)
{
    if (q.size == 0)
        return 1;
    else
        return 0;
}

BTNode *findLargest(BTNode *root, int skip, int *largestNum, int *largetNode);

BTNode *findLargest(BTNode *root, int skip, int *largestNum, int *largetNode)
{
    // Write your code here
    if (root == NULL)
        return NULL;
    BTNode *temp1 = NULL, *temp2 = NULL;

    temp1 = findLargest(root->left, skip, largestNum, largetNode);
    temp2 = findLargest(root->right, skip, largestNum, largetNode);

    int res = 0;
    res += 1;

    if (root->item == skip)
    {
        
        if (*largestNum == 1)
        {

            *largestNum = res;
            *largetNode = root->item;
            return root;
        }

        if (temp1 != NULL)
        {
            if (temp1->item == *largetNode)
                return temp1;
        }
        if (temp2 != NULL)
        {
            if (temp2->item == *largetNode)
                return temp2;
        }

        if (temp1 == NULL && temp2 == NULL)
        {

            *largestNum = res;
            *largetNode = root->item;
            return root;
        }

        return NULL;
    }

    if (root->left != NULL)
    {
        res += 1;
    }

    if (root->right != NULL)
    {
        res += 1;
    }

    if (res > *largestNum)
    {
        if (res == 3)
        {
            if (root->left->item < root->item && root->right->item > root->left->item )
            {
                *largestNum = res;
                *largetNode = root->item;
                printf("debug Updated root %d res %d,max %d\n", root->item, res, *largestNum);
                return root;
            }
        }

        if (res == 2 && temp1 != NULL)
        {
            printf("debug hit temp1 %d res %d\n", temp1->item, res);
            if (root->left->item > root->item)
            {
                *largestNum = 1;
                res = 1;
                *largetNode = temp1->item;
                printf("debug 2 root %d res %d,max %d\n", temp1->item, res, *largestNum);
                return temp1;
            }
        }

        *largestNum = res;
        *largetNode = root->item;
        printf("debug Updated root %d res %d,max %d\n", root->item, res, *largestNum);
        return root;
    }

    if (temp1 != NULL)
    {
        if (temp1->item == *largetNode)
        {
            return temp1;
        }
    }
    if (temp2 != NULL)
    {
        if (temp2->item == *largetNode)
        {
            return temp2;
        }
    }

    return NULL;
}

BTNode *findLargestBST(BTNode *root)
{
    // Write your code here
    int maxNum = 0;
    int maxNumNode = 0;
    BTNode *temp = findLargest(root, root->item, &maxNum, &maxNumNode);
    // printf("debug %d\n", temp->item);
    return temp;
}