/*edit*/

/*custom header*/

#include <math.h>
/*end_edit*/
#include <stdio.h>
int reverseDigits1(int num);
void reverseDigits2(int num, int *result);
int main()
{
    int num, result = 999;

    printf("Enter a number: \n");
    scanf("%d", &num);
    printf("reverseDigits1(): %d\n", reverseDigits1(num));
    reverseDigits2(num, &result);
    printf("reverseDigits2(): %d\n", result);
    return 0;
}
int reverseDigits1(int num)
{
    /*edit*/
    /* Write your code here */
    int result = 0;
    int tempNum;

    int numCount = log10((num)+1);

    while (num > 0)
    {
        tempNum = num % 10;
        result += (tempNum * pow(10, numCount));
        numCount--;
        num = num / 10;
    }

    return result;
    /*end_edit*/
}
void reverseDigits2(int num, int *result)
{
    /*edit*/
    /* Write your code here */
    *result = 0;
    int tempNum;

    int numCount = log10((num)+1);

    while (num > 0)
    {
        tempNum = num % 10;
        *result += (tempNum * pow(10, numCount));
        numCount--;
        num = num / 10;
    }

    /*end_edit*/
}