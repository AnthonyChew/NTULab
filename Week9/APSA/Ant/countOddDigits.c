	/*edit*/

/*custom header*/

	/*end_edit*/
#include <stdio.h>
int countOddDigits1(int num);
void countOddDigits2(int num, int *result);
int main()
{
   int number, result;
   
   printf("Enter a number: \n");
   scanf("%d", &number);
   printf("countOddDigits1(): %d\n", countOddDigits1(number));
   countOddDigits2(number, &result);
   printf("countOddDigits2(): %d\n", result);
   return 0;
}

int countOddDigits1(int number) 
{  
	/*edit*/
    int oodCount = 0;

    while(number > 0)
    {
        int tempNum = number % 10;
        if(tempNum % 2 != 0)
        {
            oodCount++;
        }
        number = number / 10;
    }

    return oodCount;
	/*end_edit*/
}

void countOddDigits2(int number, int *count) 
{  
	/*edit*/
    *count = 0;

    while(number > 0)
    {
        int tempNum = number % 10;
        if(tempNum % 2 != 0)
        {
            *count += 1;
        }
        number = number / 10;
    }

	/*end_edit*/
}