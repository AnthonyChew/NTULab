#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1000

enum ExpType
{
    OPT,
    OPERAND
};

typedef struct _queueNode
{
    int item;
    enum ExpType type;
    struct _queueNode *next;
} QueueNode;

typedef struct _queue
{
    int size;
    QueueNode *head;
    QueueNode *tail;
} Queue;

void enqueue(Queue *qptr, int item, enum ExpType type);
int dequeue(Queue *qPtr);
QueueNode *getFront(Queue q);
int isEmptyQueue(Queue q);

void expressionQ(char *infix, Queue *qPtr);
void printExpQ(Queue *qPtr);

int main()
{
    char infix[SIZE];
    scanf("%[^\n]%*c", infix);

    Queue inExpQ;
    inExpQ.head = NULL;
    inExpQ.tail = NULL;
    inExpQ.size = 0;

    expressionQ(infix, &inExpQ);
    printf("Output:\n");
    printExpQ(&inExpQ);

    return 0;
}

void enqueue(Queue *qPtr, int item, enum ExpType type)
{
    QueueNode *newNode;
    newNode = (QueueNode *)malloc(sizeof(QueueNode));
    newNode->item = item;
    newNode->type = type;
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
        return 0;
    else
    {
        QueueNode *temp = qPtr->head;
        qPtr->head = qPtr->head->next;

        if (qPtr->head == NULL)
            qPtr->tail = NULL;

        free(temp);
        qPtr->size--;
        return 1;
    }
}

QueueNode *getFront(Queue q)
{
    return q.head;
}

int isEmptyQueue(Queue q)
{
    if (q.size == 0)
        return 1;
    else
        return 0;
}

void printExpQ(Queue *qPtr)
{
    if (qPtr == NULL)
        return;

    QueueNode *temp = NULL;
    temp = getFront(*qPtr);

    while (temp != NULL)
    {
        if (temp->type == OPERAND)
            printf(" %d ", temp->item);
        else
            printf(" %c ", (char)(temp->item));
        dequeue(qPtr);
        temp = getFront(*qPtr);
    }
    printf("\n");
}

// 1+15*121/(1311-84)
void expressionQ(char *infix, Queue *qPtr)
{
    // Write your code here
    char *p = infix;
    int flag = 0;
    int tempNum = 0;

    while (*p)
    {
        if ((*p >= 48 && *p <= 57) && flag == 0)
        {

            tempNum = atoi(p);
            printf("%d  \n" , atoi(p) );
            flag = 1;
        }
        else if (*p < 48 || *p > 57)
        {
            if (tempNum != 0)
                enqueue(qPtr, tempNum, OPERAND);

            enqueue(qPtr, *p, OPT);

            tempNum = 0;
            flag = 0;
        }
        p++;
    }

    if (tempNum != 0)
        enqueue(qPtr, tempNum, OPERAND);
}
