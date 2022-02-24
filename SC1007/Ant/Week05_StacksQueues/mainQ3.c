#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 1000 //The limit of expression length

typedef struct _stackNode{
    double item;
    struct _stackNode *next;
}StackNode;

typedef struct _stack{
   int size;
   StackNode *head;
}Stack;

void push(Stack *sPtr, double item);
int pop(Stack *sPtr);
double peek(Stack s);
int isEmptyStack(Stack s);

double exePostfix(char*);

int main()
{
    char postfix[SIZE];

    printf("Enter a postfix expression:\n");
    scanf("%[^\n]%*c",postfix);

    printf("The answer is %.2lf.\n",exePostfix(postfix));

    return 0;
}

void push(Stack *sPtr, double item){
    StackNode *newNode;
    newNode = (StackNode *) malloc(sizeof(StackNode));
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

double peek(Stack s){
    return s.head->item;
}

int isEmptyStack(Stack s){
     if(s.size == 0) return 1;
     else return 0;
}

double exePostfix(char* postfix)
{
 //Write your code here
    Stack myStack;
    double  result ;
    int flag = 0;
    int op1 , op2;
    char* p = postfix;

    while (*p)
    {
        if ((*p >= 48 && *p <= 57) && flag == 0)
        {
            push(&myStack ,  atoi(p));
            
            printf("%d\n", atoi(p));

            flag = 1;
        }
        else if (*p < 48 || *p > 57)
        {
            //printf("%d,%d,%c\n", op1,op2 , *p);

            op1 = peek(myStack);
            printf("%d,", op1 );
            pop(&myStack);
            op2 = peek(myStack);
            printf("%d\n", op2 );
            pop(&myStack);


            switch (*p)
            {
            case '+':
                result = op1 + op2;
                break;
            case '-':
                result = op1 - op2;
                break;
            case '*':
                result = op1 * op2;
                break;
            case '/':
                result = op1 / op2;
                break;
            }

            push(&myStack,result);
            
            flag = 0;
        }
        p++;
    }

    return result;

}