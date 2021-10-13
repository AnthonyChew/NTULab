/*edit*/

/*custom header*/

#include <math.h>
/*end_edit*/
#include <stdio.h>
#define INIT_VALUE 999
int extEvenDigits1(int num);
void extEvenDigits2(int num, int *result);
int main()
{
    int number, result = INIT_VALUE;

    printf("Enter a number: \n");
    scanf("%d", &number);
    printf("extEvenDigits1(): %d\n", extEvenDigits1(number));
    extEvenDigits2(number, &result);
    printf("extEvenDigits2(): %d\n", result);
    return 0;
}
int extEvenDigits1(int num)
{
    /*edit*/
    /* Write your code here */

    int numCount = 0;
    double results = 0;
    int tempNum;

    while (num > 0)
    {
        tempNum = num % 10;
        if (tempNum % 2 == 0)
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
void extEvenDigits2(int num, int *result)
{
    /*edit*/
    
    int numCount = 0;
    *result = 0;
    int tempNum;

    while (num > 0)
    {
        tempNum = num % 10;
        if (tempNum % 2 == 0)
        {
            *result += (tempNum *  pow(10,numCount) );
            numCount++;
        }
        num = num / 10;
    }

    if(numCount == 0) *result = -1;

    /*end_edit*/
}