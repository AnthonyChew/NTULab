	/*edit*/

/*custom header*/

	/*end_edit*/
#include <stdio.h>
#define INIT_VALUE 999
int extOddDigits1(int num);
void extOddDigits2(int num, int *result);
int main()
{
   int number, result = INIT_VALUE;
   
   printf("Enter a number: \n");
   scanf("%d", &number);
   printf("extOddDigits1(): %d\n", extOddDigits1(number));        
   extOddDigits2(number, &result);
   printf("extOddDigits2(): %d\n", result);
   return 0;
}
int extOddDigits1(int num) 
{  
	/*edit*/
   /* Write your code here */
    
    int numCount = 0;
    double results = 0;
    int tempNum;

    while (num > 0)
    {
        tempNum = num % 10;
        if (tempNum % 2 != 0)
        {
            results += (tempNum *  pow(10,numCount) );
            numCount++;
        }
        num = num / 10;
    }

    if(numCount == 0) return -1;

    return (int)results;

	/*end_edit*/
}
void extOddDigits2(int num, int *result) 
{  
	/*edit*/
   /* Write your code here */
     int numCount = 0;
    *result = 0;
    int tempNum;

    while (num > 0)
    {
        tempNum = num % 10;
        if (tempNum % 2 != 0)
        {
            *result += (tempNum *  pow(10,numCount) );
            numCount++;
        }
        num = num / 10;
    }

    if(numCount == 0) *result = -1;

	/*end_edit*/
}