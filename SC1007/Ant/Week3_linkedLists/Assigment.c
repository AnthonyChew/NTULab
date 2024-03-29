#include <stdio.h>
#include <stdlib.h>

struct _listNode{
    float item;
    struct _listNode* next;
};
typedef struct _listNode ListNode;

void printList(ListNode *head);
void deleteList(ListNode **ptrHead);

ListNode *reverseSegment(ListNode* head, int start, int end);

int main()
{
    ListNode *head = NULL, *temp;
	float f = 0.0;
	int S, E;

	scanf("%d %d",&S, &E);

	while (scanf("%f", &f)){
		if (head == NULL){
			head = (ListNode*) malloc(sizeof(ListNode));
			temp = head;
		}
		else{
			temp->next = (ListNode*) malloc(sizeof(ListNode));
			temp = temp->next;
		}
		temp->item = f;
	}
	temp->next = NULL;

	head = reverseSegment(head,S,E);
	printList(head);
	deleteList(&head);
	return 0;

}

void printList(ListNode *head){
    while(head !=NULL){
        printf("%.2f ",head->item);
        head = head->next;
    }
    printf("\n");
}

void deleteList(ListNode **ptrHead){
    ListNode *cur = *ptrHead;
    ListNode *temp;
    while (cur!= NULL) {
		temp=cur->next;
		free(cur);
		cur=temp;
	}
	*ptrHead=NULL;
}

ListNode *reverseSegment(ListNode* head, int start, int end)
{
    ListNode *cur = head , *befStartPtr, *startPtr , *endPtr , *pre, *temp;
    int count = 0;
    befStartPtr = NULL;

    while (cur->next != NULL)
    {
        if(count == start - 1 && start > 0)  befStartPtr = cur;
        if(count == start)  startPtr = cur;
        if(count == end) endPtr = cur;
        cur = cur->next;
        count++;
    }

    if(start < 0 ||  end > count ) return head;

    count = 0;
    cur = startPtr;
    pre = startPtr;
    while(count <= end - start)
    {
        temp = cur->next;
        if(count == 0)
        {
            if(endPtr->next == NULL)
            {
                cur->next= NULL;
            }
            else
            {
                cur->next = endPtr->next;
            }
        }
        else
        if (count == (end - start))
        {
            if(befStartPtr == NULL)
            {
                head = cur;
                cur->next = pre;
            }
            else
            {
                befStartPtr->next = cur;
                cur->next = pre;
            }
        }
        else
        {
            cur->next = pre;
        }
        
        pre = cur;
        cur = temp;

        count ++;
    }
    
	return head;

}