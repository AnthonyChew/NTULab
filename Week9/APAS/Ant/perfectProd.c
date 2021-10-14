/*edit*/

/*custom header*/

#include <math.h>
/*end_edit*/
#include <stdio.h>
int perfectProd1(int num);
void perfectProd2(int num, int *prod);
int main()
{
    int number, result = 0;

    printf("Enter a number: \n");
    scanf("%d", &number);
    printf("Calling perfectProd1() \n");
    printf("perfectProd1(): %d\n", perfectProd1(number));

    printf("Calling perfectProd2() \n");
    perfectProd2(number, &result);
    printf("perfectProd2(): %d\n", result);
    return 0;
}
int perfectProd1(int num)
{
    /*edit*/
    int count = 1, results = 1;

    /* Write your code here */
    while (count <= num)
    {
        //check is facot a perfect num
        int checkCount = 1, checkTotal = 0;
        while (checkCount < count)
        {
            if ((count % checkCount) == 0)
            {
                checkTotal += checkCount;
            }
            checkCount++;
        }

        if(count == checkTotal)
        {
            printf("Perfect number: %d\n" , count);
            results = (results * count);
        }

        count++;
    }

    return results;
    /*end_edit*/
}
void perfectProd2(int num, int *prod)
{
    /*edit*/
    /* Write your code here */
    int count = 1;
    *prod = 1;

    /* Write your code here */
    while (count <= num)
    {
        //check is facot a perfect num
        int checkCount = 1, checkTotal = 0;
        while (checkCount < count)
        {
            if ((count % checkCount) == 0)
            {
                checkTotal += checkCount;
            }
            checkCount++;
        }

        if(count == checkTotal)
        {
            printf("Perfect number: %d\n" , count);
            *prod = (*prod * count);
        }

        count++;
    }

    /*end_edit*/
}