#include <stdio.h>
#include <stdlib.h>

struct _listNode
{
	int item;
	struct _listNode *next;
};
typedef struct _listNode ListNode;

typedef struct _linkedList
{
	ListNode *head;
	int size;
} LinkedList;

void printList(LinkedList ll);
void deleteList(LinkedList *llptr);

LinkedList rearrange(LinkedList ll);

int main()
{
	LinkedList ll;

	ll.head = NULL;
	ll.size = 0;
	ListNode *temp;

	int i = 0;

	while (scanf("%d", &i))
	{
		if (ll.head == NULL)
		{
			ll.head = (ListNode *)malloc(sizeof(ListNode));
			temp = ll.head;
		}
		else
		{
			temp->next = (ListNode *)malloc(sizeof(ListNode));
			temp = temp->next;
		}
		temp->item = i;
		ll.size++;
	}
	temp->next = NULL;

	ll = rearrange(ll);

	printList(ll);
	deleteList(&ll);
	return 0;
}

void printList(LinkedList ll)
{
	ListNode *temp = ll.head;

	while (temp != NULL)
	{
		printf("%d ", temp->item);
		temp = temp->next;
	}
	printf("\n");
}
void deleteList(LinkedList *llptr)
{
	ListNode *cur = llptr->head;
	ListNode *temp;
	while (cur != NULL)
	{
		temp = cur->next;
		free(cur);
		cur = temp;
	}
	llptr->head = NULL;
	llptr->size = 0;
}

// 1 2 3 4 5 6 7 8 9 10 a
// 1 2 3 4 5 6 7 8 9 10
// 6 3 1 9 7 4 2 10 8 5
LinkedList rearrange(LinkedList ll)
{
	// Write your code here
	ListNode *listOne, *listTwo, *cur, *temp, *listOneTemp, *listTwoTemp;
	int count = 0;

	int size = ll.size / 2;
	cur = ll.head;

	while (cur != NULL)
	{
		temp = cur->next;
		if (count == 0)
		{
			listOne = cur;
		}

		if (count == size - 1)
		{
			cur->next = NULL;
		}

		if (count == size)
		{
			listTwo = cur;
		}

		count++;
		cur = temp;
	}

	for (int i = 0; i < size; i++)
	{
		listOneTemp = listOne->next;
		listTwoTemp = listTwo->next;

		if (i == 0)
		{
			ll.head = listTwo;
			listTwo->next = listOne;
			listOne->next = listTwoTemp;
		}
		else if (i == size - 1)
		{
			if (ll.size % 2 != 0)
			{
				listTwo->next = listOne;
				listOne->next = listTwoTemp;
				listTwoTemp->next = NULL;
			}
			else
			{
				listTwo->next = listOne;
				listOne->next = NULL;
			}
		}
		else
		{
			listTwo->next = listOne;
			listOne->next = listTwoTemp;
		}

		listOne = listOneTemp;
		listTwo = listTwoTemp;
	}

	cur = ll.head;
	count = 0;
	while (cur != NULL)
	{
		temp = cur->next;
		if (count == 0)
		{
			listOne = cur;
		}

		if (count == size - 1)
		{
			cur->next = NULL;
		}

		if (count == size)
		{
			listTwo = cur;
		}

		count++;
		cur = temp;
	}

	for (int i = 0; i < size; i++)
	{
		listOneTemp = listOne->next;
		listTwoTemp = listTwo->next;

		if (i == 0)
		{
			ll.head = listOne;
			listOne->next = listTwo;
			listTwo->next = listOneTemp;
		}
		else if (i == size - 1)
		{
			if (ll.size % 2 != 0)
			{
				listOne->next = listTwo;
				listTwo->next = listTwoTemp;
				listTwoTemp->next = NULL;
			}
			else
			{
				listOne->next = listTwo;
				listTwo->next = NULL;
			}
		}
		else
		{
			listOne->next = listTwo;
			listTwo->next = listOneTemp;
		}

		listOne = listOneTemp;
		listTwo = listTwoTemp;
	}

	return ll;
}
