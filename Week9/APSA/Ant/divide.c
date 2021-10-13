/*edit*/

/*custom header*/

/*end_edit*/
#include <stdio.h>
int divide1(int m, int n, int *r);
void divide2(int m, int n, int *q, int *r);
int main()
{
    int m, n, q, r;

    printf("Enter two numbers (m and n): \n");
    scanf("%d %d", &m, &n);
    q = divide1(m, n, &r);
    printf("divide1(): quotient %d remainder %d\n", q, r);
    divide2(m, n, &q, &r);
    printf("divide2(): quotient %d remainder %d\n", q, r);
    return 0;
}
int divide1(int m, int n, int *r)
{
    /*edit*/
    int count = 0;
    int divide = 1;

    while (1)
    {

         if (m < n)
        {
            *r = m;
            return 0;
        }

        m -= n;

        if (m - n < 0)
        {
            *r = m;
            break;
        }
        divide++;
    }

    return divide;
    /*end_edit*/
}
void divide2(int m, int n, int *q, int *r)
{
    /*edit*/
    /* Write your code here */
    int count = 0;
    *q = 1;

    while (1)
    {
        if (m < n)
        {
            *r = m;
            *q = 0;
            break;
        }

        m -= n;
        if (m - n < 0)
        {
            *r = m;
            break;
        }

        *q += 1;
    }

    /*end_edit*/
}