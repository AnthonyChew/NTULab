	/*edit*/

/*custom header*/

	/*end_edit*/
#include  <stdio.h>
int sumSqDigits1(int num);   
void sumSqDigits2(int num, int *result);   
int main()
{
   int num, result;

   printf("Enter a number: \n");
   scanf("%d", &num);
   printf("sumSqDigits1(): %d\n", sumSqDigits1(num));
   sumSqDigits2(num, &result);
   printf("sumSqDigits2(): %d\n", result);
   return 0;
}
int sumSqDigits1(int num) 
{
	/*edit*/
    int result = 0;

   /* Write your code here */
    while(num > 0)
    {
        int tempNum = num % 10;

        result += (tempNum * tempNum);

        num = num / 10;
    }

    return result;
	/*end_edit*/
}
void sumSqDigits2(int num, int *result) 
{
	/*edit*/
   /* Write your code here */
    *result= 0;

   /* Write your code here */
    while(num > 0)
    {
        int tempNum = num % 10;

        *result += (tempNum * tempNum);

        num = num / 10;
    }

	/*end_edit*/
}