#include <stdio.h>
#include <stdlib.h>

struct _listNode{
    int item;
    struct _listNode* next;
};
typedef struct _listNode ListNode;

void printList(ListNode *head);
void deleteList(ListNode **ptrHead);

void triPartition(ListNode** head, int pivot);

int main()
{
    ListNode *head = NULL, *temp;
	int i = 0;
	int pivot = 0;

	scanf("%d",&pivot);

	while (scanf("%d", &i)){
		if (head == NULL){
			head = (ListNode*) malloc(sizeof(ListNode));
			temp = head;
		}
		else{
			temp->next = (ListNode*) malloc(sizeof(ListNode));
			temp = temp->next;
		}
		temp->item = i;
	}
	temp->next = NULL;


	triPartition(&head, pivot);
	printList(head);
	deleteList(&head);

	return 0;
}

void printList(ListNode *head){
    while(head !=NULL){
        printf("%d ",head->item);
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

void triPartition(ListNode** head, int pivot){

// Write your code here
	ListNode *pivotPtr , *firstPartPtr , *thridPartPtr , *cur , *temp , *tempPivotPtr , *tempThridPtr ;
	cur = *head;
	pivotPtr = NULL;
	firstPartPtr = NULL;
	thridPartPtr = NULL;

	//search for pivot ptr
	while(cur != NULL)
	{
		if(cur->item == pivot)
		{
			pivotPtr = cur;
			break;
		}

		cur	 = cur->next;
	}

	//Set curr to head
	cur = *head;
	tempPivotPtr = pivotPtr; // temp pivot ptr for traverse
	
	//main loop
	while (cur != NULL)
	{
		temp = cur->next; //temp to next in case current copy change

		//if smaller than pivot
		if(cur->item < pivot)		
		{
			//if first node empty set head, head.next to pivot and copy of first node 
			if(firstPartPtr == NULL)
			{
				firstPartPtr = cur;
				firstPartPtr->next = pivotPtr;
				*head = firstPartPtr;
			}
			//set curhead.next == cur, traverse, set next to pivot
			else
			{
				firstPartPtr->next = cur;
				firstPartPtr = firstPartPtr->next;
				firstPartPtr->next = pivotPtr;
			}
		}
		//if bigger
		else
		if(pivot < cur->item)
		{
			if(thridPartPtr == NULL)
			{
				thridPartPtr = cur;
				thridPartPtr->next = NULL;
				tempThridPtr = thridPartPtr;
			}
			else
			{
				tempThridPtr->next = cur;
				tempThridPtr = tempThridPtr->next;
				tempThridPtr->next = NULL;
			}
		}
		//if same as pivot
		else
		{
			if(cur != tempPivotPtr)
			{
				tempPivotPtr->next = cur;
				tempPivotPtr = tempPivotPtr->next;
			}
			tempPivotPtr->next = thridPartPtr;
		}
		
		cur	 = temp;
	}

	//make sure last pivot node point to start of third partition

	//if no smaller num than pivot set head to pivot head
	if(firstPartPtr == NULL)
	{
		*head = pivotPtr;
	}
	//if nothing bigger than pivot head set last pivot to tail
	if(thridPartPtr == NULL)
	{
		tempPivotPtr->next = NULL;
	}
	if(pivotPtr == NULL)
	{
		firstPartPtr->next = thridPartPtr;
	}
	else
	{
		tempPivotPtr->next = thridPartPtr;
	}
}

