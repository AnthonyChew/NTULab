#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1000 //The size of the array

enum ExpType {OPT,OPERAND};

typedef struct _stackNode{
    char item;
    struct _stackNode *next;
}StackNode;

typedef struct _stack{
   int size;
   StackNode *head;
}Stack;

void push(Stack *sPtr, char item);
int pop(Stack *sPtr);
char peek(Stack s);
int isEmptyStack(Stack s);

typedef struct _listnode
{
    int  item;
    enum ExpType type;
	struct _listnode *next;
} ListNode;

typedef struct _linkedlist{
   int size;
   ListNode *head;
} LinkedList;

void insertNode(LinkedList *llPtr, int item,enum ExpType type);
int deleteNode(LinkedList *llPtr);
void removeAllNodes(LinkedList *llPtr);
int isEmptyLinkedList (LinkedList ll);


void in2PreLL(char* infix, LinkedList *inExpLL);

void printExpLL(LinkedList inExp);

int main()
{
    char infix[SIZE];

    //printf("Enter an infix expression:\n");
    scanf("%[^\n]%*c",infix);

    LinkedList inExpLL;
    inExpLL.head = NULL;
    inExpLL.size = 0;

    in2PreLL(infix, &inExpLL);

    printExpLL(inExpLL);

    removeAllNodes(&inExpLL);
    return 0;
}

void printExpLL(LinkedList inExpLL)
{
    ListNode* temp = NULL;
    temp = inExpLL.head;
    while(temp!= NULL){
        if(temp->type == OPERAND)
            printf(" %d ",temp->item);
        else
            printf(" %c ",(char)(temp->item));
        temp = temp->next;
    }
    printf("\n");
}

void insertNode(LinkedList *LLPtr, int item, enum ExpType type) {
    ListNode *newNode;
    newNode = malloc(sizeof(ListNode));
    if(newNode==NULL) exit(0);

    newNode->item = item;
    newNode->type = type;
    newNode->next = LLPtr->head;
    LLPtr->head=newNode;
    LLPtr->size++;
}

int deleteNode(LinkedList *LLPtr) {
    if(LLPtr==NULL || LLPtr->size==0){
        return 0;
    }
    else{
       ListNode *temp = LLPtr->head;
       LLPtr->head = LLPtr->head->next;

       free(temp);
       LLPtr->size--;
       return 1;
    }
}

int isEmptyLinkedList (LinkedList ll) {
    if(ll.size==0) return 1;
    else return 0;
}

void removeAllNodes(LinkedList *LLPtr)
{
	while(deleteNode(LLPtr));
}

void push(Stack *sPtr, char item){
    StackNode *newNode;
    newNode = malloc(sizeof(StackNode));
    newNode->item = item;
    newNode->next = sPtr->head;
    sPtr->head = newNode;
    sPtr->size++;
}

int pop(Stack *sPtr){
    if(sPtr == NULL || sPtr->head == NULL){
        return 0;
    }
    else{
       StackNode *temp = sPtr->head;
       sPtr->head = sPtr->head->next;
       free(temp);
       sPtr->size--;
       return 1;
    }
}

char peek(Stack s){
    return s.head->item;
}

int isEmptyStack(Stack s){
     if(s.size == 0) return 1;
     else return 0;
}

int precedence(char ch) 
{ 
    switch (ch) 
    { 
    case '+': 
        return 1; 
    case '-': 
        return 1; 

    case '*': 
        return 2; 
    case '/': 
        return 2;   
    case '%': 
        return 2; 

    case '^': 
        return 3; 
    } 
    return -1; 
} 

// 99+(88-77)*(66/(55-44)+33)
//  +  99  *  -  88  77  +  /  66  -  55  44  33
void in2PreLL(char *infix, LinkedList *inExpLL)
{
    // Write your code here
    Stack stack;

    stack.head = NULL;
    stack.size = 0;

    int count = 0;
    
    int size;
    int j, i=0 , h;

    size = strlen(infix);
    j = size;
    j--;

    char temp[size];

    while(infix[i]!='\0')
    {
        temp[j] = infix[i];
        j--;
        i++;
    }
    temp[i]='\0';

    strcpy(infix,temp);

    i = 0;
    while(infix[i]!='\0')
    {
        if(infix[i]=='(')
            infix[i]=')';
        else if(infix[i]==')')
            infix[i]='(';
        i++;
    }

    temp[SIZE];
    
    strcpy(temp,"");

    //(33+(44-55)/66)*(77-88)+99
    for (i = 0, j = -1,h = -1;  infix[i]; ++i) 
    { 
        if ((48 <= infix[i] && infix[i] <= 57) || (65 <= infix[i] && infix[i] <= 90)|| (97 <= infix[i] && infix[i] <= 112)) 
        {
            j++;
            infix[j] = infix[i]; 
            h++;
            temp[h] = infix[i]; 
            //printf("%c , %c\n" ,  infix[j] , infix[i]);
        }
        else if(infix[i] == ' ') continue;
        else if (infix[i] == '(') 
        {
            push(&stack, infix[i]); 
            //printf("%c\n" , peek(stack));
        }
        else if (infix[i] == ')') 
        { 
            while (!isEmptyStack(stack) && peek(stack) != '(') 
            {
                j++;
                infix[j] = peek(stack);
                h++;
                temp[h] = peek(stack); 
                pop(&stack);
            } 
            if (!isEmptyStack(stack) && peek(stack) != '(') 
            {
                return ; // invalid infixression
            }              
            else
            {
                pop(&stack);
            } 
        } 
        else // if an opertor
        {                 
            h++;
            temp[h] = ','; 
            while (!isEmptyStack(stack) && precedence(infix[i]) <= precedence(peek(stack))) 
            {
                //printf("%c\n" , infix[j]);
                j++;
                infix[j] = peek(stack); 
                h++;
                temp[h] = peek(stack); 
                pop(&stack);
            }
            push(&stack, infix[i]); 
        } 
    }

    while (!isEmptyStack(stack)) 
    {
        j++;
        infix[j] = peek(stack); 
        h++;
        temp[h] = peek(stack); 
        pop(&stack);
    }
    j++;
    infix[j] = '\0'; 
    h++;
    temp[h] = '\0'; 
    //printf("%s\n", temp);
    
    int tempNum = 0, flag = 0;

    for (int k = 0; k < strlen(temp); k++)
    {
        if (((48 <= temp[k] && temp[k] <= 57) || (65 <= temp[k] && temp[k] <= 90)|| (97 <= temp[k] && temp[k] <= 112)) && flag == 0)
        {
            tempNum = atoi(&temp[k]);
            printf("%d  \n" , tempNum);
            flag = 1;
        }
        else if (temp[k] == 44) 
        {
            if (tempNum != 0)
            {
                insertNode(inExpLL, tempNum, OPERAND);
            }
            tempNum = 0;
                flag = 0; 

        }
        else if (temp[k] < 48 || temp[k] > 57)
        {
            if (tempNum != 0)
                insertNode(inExpLL, tempNum, OPERAND);

            insertNode(inExpLL, temp[k], OPT);

            tempNum = 0;
            flag = 0;
        }
    }
    
    if (tempNum != 0)
        insertNode(inExpLL, tempNum, OPERAND);

}

