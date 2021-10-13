	/*edit*/

/*custom header*/

	/*end_edit*/
#include <stdio.h>
int digitValue1(int num, int k);
void digitValue2(int num, int k, int *result);
int main()
{
   int num, digit, result=-1;
   
   printf("Enter the number: \n");
   scanf("%d", &num);     
   printf("Enter k position: \n");
   scanf("%d", &digit);   
   printf("digitValue1(): %d\n",  digitValue1(num, digit));
   digitValue2(num, digit, &result);
   printf("digitValue2(): %d\n", result);   
   return 0;
}
int digitValue1(int num, int k)
{
	/*edit*/
    int count = 1;
    int tempNum = 0;

    while(num > 0)
    {
        tempNum = num % 10;
        if(count == k)
        {
            return tempNum;
        }
        num = num / 10;
        count++;
    }

	/*end_edit*/
}
void digitValue2(int num, int k, int *result) 
{
	/*edit*/
   /* Write your code here */
    int count = 1;
    *result = 0;

    while(num > 0)
    {
        *result = num % 10;
        if(count == k)
        {
            break;
        }
        num = num / 10;
        count++;
    }

	/*end_edit*/
}