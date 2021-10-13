/*edit*/

/*custom header*/

/*end_edit*/
#include <stdio.h>
double computePay1(int noOfHours, int payRate);
void computePay2(int noOfHours, int payRate, double *grossPay);
int main()
{
    int noOfHours, payRate;
    double grossPay;

    printf("Enter number of hours: \n");
    scanf("%d", &noOfHours);
    printf("Enter hourly pay rate: \n");
    scanf("%d", &payRate);
    printf("computePay1(): %.2f\n", computePay1(noOfHours, payRate));
    computePay2(noOfHours, payRate, &grossPay);
    printf("computePay2(): %.2f\n", grossPay);
    return 0;
}
double computePay1(int noOfHours, int payRate)
{
    /*edit*/
    double totalGross;
    
    if (noOfHours <= 160)
    {
        totalGross = noOfHours * payRate;
    }
    else
    {
        totalGross = 160 * payRate;
        totalGross += ((noOfHours - 160) * (payRate * 1.5));
    }

    return totalGross;

    /*end_edit*/
}
void computePay2(int noOfHours, int payRate, double *grossPay)
{
    /*edit*/
    /* Write your code here */
    *grossPay = 0;

    /*edit*/
    if (noOfHours <= 160)
    {
        *grossPay = noOfHours * payRate;
    }
    else
    {
        *grossPay = 160 * payRate;
        *grossPay += ((noOfHours - 160) * (payRate * 1.5));
    }
    /*end_edit*/
}