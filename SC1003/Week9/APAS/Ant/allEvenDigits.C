	/*edit*/

/*custom header*/

	/*end_edit*/
#include  <stdio.h>
int allEvenDigits1(int num); 
void allEvenDigits2(int num, int *result);    
int main()
{
   int number, p=999, result=999;

   printf("Enter a number: \n");
   scanf("%d", &number);
   p = allEvenDigits1(number);
   if (p == 1)
      printf("allEvenDigits1(): yes\n");
   else if (p == 0)
      printf("allEvenDigits1(): no\n");
   else 
      printf("allEvenDigits1(): error\n");
   allEvenDigits2(number, &result);
   if (result == 1)
      printf("allEvenDigits2(): yes\n");
   else if (result == 0)
      printf("allEvenDigits2(): no\n");
   else 
      printf("allEvenDigits2(): error\n");
   return 0;
}
int allEvenDigits1(int num) 
{
	/*edit*/
   /* Write your code here */
    int flag = 1;

    while(num > 0)
    {
        int tempNum = num % 10;
        if(tempNum % 2 != 0)
        {
            flag = 0;
        }
        num = num / 10;
    }

    return flag;

	/*end_edit*/
}
void allEvenDigits2(int num, int *result) 
{
	/*edit*/
   /* Write your code here */
    *result = 1;

    while(num > 0)
    {
        int tempNum = num % 10;
        if(tempNum % 2 != 0)
        {
            *result = 0;
        }
        num = num / 10;
    }

	/*end_edit*/
}