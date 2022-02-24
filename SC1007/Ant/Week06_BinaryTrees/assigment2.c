#include <stdio.h>
#include <stdlib.h>

typedef struct _btnode
{
    int nodeV;
    struct _btnode *left;
    struct _btnode *right;
} BTNode;

typedef struct _queuenode
{
    BTNode *node;
    struct _queuenode *next;
} QueueNode;

typedef struct _queue
{
    int size;
    QueueNode *head;
    QueueNode *tail;
} Queue;

void printBTNode(BTNode *root, int space, int left);
// Prototypes of Interface functions for Queue structure
void enqueue(Queue *qPtr, BTNode *node);
int dequeue(Queue *qPtr);
BTNode *getFront(Queue q);
int isEmptyQueue(Queue q);

int twoNodesCost(BTNode *node, int nodeV1, int nodeV2);

int main()
{
    BTNode *root = (BTNode *)malloc(sizeof(BTNode));

    Queue q;
    q.head = NULL;
    q.tail = NULL;
    q.size = 0;

    BTNode *node;
    enqueue(&q, root);

    int nodeV;
    char opL, opR;

    while (!isEmptyQueue(q))
    {
        scanf("%d %c %c", &nodeV, &opL, &opR);
        node = getFront(q);
        dequeue(&q);
        node->nodeV = nodeV;

        if (opL != '@')
        {
            node->left = (BTNode *)malloc(sizeof(BTNode));
            enqueue(&q, node->left);
        }
        else
            node->left = NULL;
        if (opR != '@')
        {
            node->right = (BTNode *)malloc(sizeof(BTNode));
            enqueue(&q, node->right);
        }
        else
            node->right = NULL;
    }

    int v1, v2;
    scanf("%d %d", &v1, &v2);
    int cost = twoNodesCost(root, v1, v2);

    printBTNode(root, 0, 0);

    printf("Distance is %d\n", cost);
    return 0;
}

void enqueue(Queue *qPtr, BTNode *node)
{
    QueueNode *newNode;
    newNode = malloc(sizeof(QueueNode));
    newNode->node = node;
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
    return q.head->node;
}

int isEmptyQueue(Queue q)
{
    if (q.size == 0)
        return 1;
    else
        return 0;
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

        printf("%d\n", root->nodeV);

        space++;
        printBTNode(root->left, space, 1);
        printBTNode(root->right, space, 0);
    }
}

BTNode *LCA(BTNode *node, int nodeV1, int nodeV2);
int getDistance(BTNode *node, int k, Queue *myQueue);
int findDistance(BTNode *root, int a, int b, Queue *myQueue);

BTNode *LCA(BTNode *node, int nodeV1, int nodeV2)
{
    if (node == NULL)   return node;

    if (node->nodeV == nodeV1 || node->nodeV == nodeV2) return node;

    BTNode *left = LCA(node->left, nodeV1, nodeV2);

    BTNode *right = LCA(node->right, nodeV1, nodeV2);

    if (left != NULL && right != NULL)  return node;

    if (left != NULL)   return LCA(node->left, nodeV1, nodeV2);

    return LCA(node->right, nodeV1, nodeV2);
}

int getDistance(BTNode *node, int k, Queue *myQueue)
{
    if (node == NULL)   return -1;

    if (node->nodeV == k)
    {
        enqueue(myQueue, node);

        printf("enqueue %d\n", node->nodeV);
        return 1;
    }

    int left = getDistance(node->left, k, myQueue);

    if (left == 1)
    {
        printf("enqueue %d\n", node->nodeV);
        enqueue(myQueue, node);
    }

    if (left == -1)
    {
        left = getDistance(node->right, k, myQueue);
        if (left == 1)
        {
            printf("enqueue %d\n", node->nodeV);
            enqueue(myQueue, node);
        }

        return left;
    }

    return left;
}

int findDistance(BTNode *node, int a, int b, Queue *myQueue)
{
    BTNode *lca = LCA(node, a, b);
    getDistance(lca, a, myQueue);

    if (lca->nodeV != b)
    {
        getDistance(lca, b, myQueue);
    }

    return lca->nodeV;
}

int twoNodesCost(BTNode *node, int nodeV1, int nodeV2)
{

    // Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail

    // Write your code here    
    Queue myQueue;
    myQueue.head = NULL;
    myQueue.size = 0;
    myQueue.tail = NULL;

    int res = 0, temp;
    temp = findDistance(node, nodeV1, nodeV2, &myQueue);

    while (!isEmptyQueue(myQueue))
    {
        BTNode *tempNode = getFront(myQueue);

        if (tempNode->nodeV != temp)
        {
            res += tempNode->nodeV;
        }
        
        dequeue(&myQueue);
    }

    res += temp;

    return res;
}
