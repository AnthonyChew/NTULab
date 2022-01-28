#include <stdio.h>
#include <stdlib.h>

struct _listNode{
    int item;
    struct _listNode* next;
};
typedef struct _listNode ListNode;

void printList(ListNode *head);
void deleteList(ListNode **ptrHead);

void reverseKNodes(ListNode** head, int K);

int main()
{
    ListNode *head = NULL, *temp;
	int i = 0;
	int K = 0;

	scanf("%d",&K);

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


	reverseKNodes(&head, K);
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

void reverseKNodes(ListNode** head, int K){
//Write your code here

	ListNode *cur , *start , *end , *befStartPtr , *pre , *loopCurPtr , *loopPrePtr , *loopTempPtr , *nextTemp;

    int count  = 1; //counter
    cur = *head; //Point cur to head pointer
    pre = NULL; //set pre to NULL
    loopPrePtr = NULL;
    befStartPtr = NULL;
    nextTemp = NULL;

	if(K <= 1 ) return 0; //If K <= 1 return 
    
    //loopclear
    while (cur != NULL)
    {
        //Store next to temp for traverse later
        nextTemp = cur->next;

        //If count % k == 1 means this wil be first node
        if(count % K == 1)
        {
            start = cur; //Get start pointer to reverse
            loopCurPtr = start; //Use for loop to traverse
            //if(count != 1)   //if count != 1 get previous pointer before start pointer
        }
        else if(count % K == 0)
        {
            end = cur; //Get end pointer to reverse

            //Loop K amounts to time to reverse
            for (int i = 0; i < K; i++)
            {
                //Store next pointer to temp before change
                loopTempPtr = loopCurPtr->next;

                //If frist node point it to the end.next node
                if(i == 0)
                {
                    if(end->next == NULL) loopCurPtr->next = NULL;
                    else loopCurPtr->next = end->next;
                }
                //If its the last node point it to the pre node that is out of this K range
                else
                if(i == K - 1) 
                {
                    if(befStartPtr == NULL)
                    {
                        *head = loopCurPtr;
                        loopCurPtr->next = loopPrePtr;
                    }
                    else
                    {
                        befStartPtr->next = loopCurPtr;
                        loopCurPtr->next = loopPrePtr;
                    }
                    befStartPtr = start;
                }
                //The rest just point it to the node before it
                else
                {
                    loopCurPtr->next = loopPrePtr;
                }

                loopPrePtr = loopCurPtr;
                loopCurPtr = loopTempPtr;
            }
        }
        
        count++;
        pre = cur; //pre pointer
        cur = nextTemp; //go to next list
    }

}
