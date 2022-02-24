#include <stdio.h>
#include <stdlib.h>

typedef struct _dbllistnode
{
    int item;
    struct _dbllistnode *next;
    struct _dbllistnode *pre;
} CDblListNode;

typedef struct _dbllinkedlist
{
    int size;
    CDblListNode *head;
} CDblLinkedList;

void insertNode_AtFront(CDblLinkedList *ptrCDLL, int value);
void deleteList(CDblLinkedList *ptrCDLL);
void printList(CDblLinkedList CDLL);

int numMountainPairs(CDblLinkedList CDLL);

int main()
{
    CDblLinkedList himalayas;
    himalayas.head = NULL;
    himalayas.size = 0;

    int item;
    int i, cases;
    int numP;
    scanf("%d", &cases);
    for (i = 0; i < cases; i++)
    {
        while (scanf("%d", &item))
            insertNode_AtFront(&himalayas, item);
        scanf("%*s");

        numP = numMountainPairs(himalayas);
        printList(himalayas);
        printf("%d Pairs.\n", numP);

        deleteList(&himalayas);
    }
    return 0;
}

void insertNode_AtFront(CDblLinkedList *ptrCDLL, int value)
{
    // create a new node
    CDblListNode *newNode;
    newNode = (CDblListNode *)malloc(sizeof(CDblListNode));
    newNode->item = value;

    if (ptrCDLL->size == 0) // first node
    {
        newNode->next = newNode;
        newNode->pre = newNode;
        ptrCDLL->head = newNode;
    }
    else
    {
        newNode->next = ptrCDLL->head;
        newNode->pre = ptrCDLL->head->pre;

        newNode->pre->next = newNode; // update last node next link;
        ptrCDLL->head->pre = newNode;

        ptrCDLL->head = newNode;
    }
    ptrCDLL->size++;
}

void printList(CDblLinkedList CDLL)
{

    if (CDLL.head == NULL)
        return;

    CDblListNode *temp = CDLL.head;
    printf("Current List: ");

    while (temp->next != CDLL.head)
    {
        printf("%d ", temp->item);
        temp = temp->next;
    }
    printf("%d\n", temp->item);
}

void deleteList(CDblLinkedList *ptrCDLL)
{
    if (ptrCDLL->head == NULL)
        return;
    CDblListNode *cur = ptrCDLL->head;
    CDblListNode *temp;

    while (cur->next != ptrCDLL->head)
    {
        temp = cur->next;
        free(cur);
        cur = temp;
    }

    free(cur);
    ptrCDLL->head = NULL;
    ptrCDLL->size = 0;
}

int isPair(CDblListNode *node1, CDblListNode *node2)
{
    CDblListNode *next = node1->next;
    int goingClockwise = 1;
    int result = 1;

    int minHeight = node1->item > node2->item ? node2->item : node1->item;

    // Comparing clockwise within node 1 and 2
    while (next != node2)
    {
        // If its larger than the min Height; Continue
        if (next->item > minHeight  )
        {
            // No pair found
            //printf("Not a Pair, Rotating\n");
            result = 0;
            break;
        }
        next = next->next ;
    }

    if(result == 1)return 1;

    next = node1->pre;
    while (next != node2)
    {
        // If its larger than the min Height; Continue
        if (next->item  > minHeight)
        {
            // No pair found
            //printf("Not a Pair, Rotating\n");
            return 0;
        }
        next = next->pre ;
    }
    return 1;
    printf("N1: %d, N2: %d, curNode: %d, mH: %d\n", node1->item, node2->item, next->item, minHeight);
    printf("Is a Pair\n\n");
}
/*
3
1 2 3 4 5 a
5 2 2 4 3 a
5 4 4 4 3 2 1 5 1 a
*/

int numMountainPairs(CDblLinkedList CDLL)
{
    // Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
    int totalPairs = 0;
    CDblListNode *node1 = CDLL.head;
    CDblListNode *node2 = node1->next;
    int start = 0;

    // Write your code here
    // Exp: 5 2 2 4 3
    // 1. Count Adjacent = length
    // 4 Pairs

    // Comparing clockwise within node 1 and 2
    while (node1 != CDLL.head ||  !start)
    {
        start = 1;
        while (node2 != CDLL.head)
        {
            printf("Dbug:N1: %d, N2: %d\n", node1->item, node2->item);
            totalPairs += isPair(node1, node2);
            node2 = node2->next;
        }
        
        node1 = node1->next;
        node2 = node1->next;
    }

    return totalPairs;
}

/*
int numMountainPairs(CDblLinkedList CDLL)
{
    // Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
    int totalPairs = 0;
    CDblListNode *node1 = CDLL.head->pre;

    // Write your code here
    // Exp: 5 2 2 4 3
    // 1. Count Adjacent = length
    // 4 Pairs

    totalPairs += CDLL.size;

    // Comparing clockwise within node 1 and 2
    CDblListNode *node2 = node1->pre->pre;
    while (1)
    {
        totalPairs += isPair(node1, node2);

        // Ttaversing Nxt
        node2 = node2->pre;
        if (node1->next == node2 )
        {
            node1 = node1->pre;
            node2 = node1->pre->pre;
        }

        if (node1 == CDLL.head)
        {
            totalPairs += isPair(node1, node2);
            break;
        }
        
    }

    return totalPairs;
}
*/