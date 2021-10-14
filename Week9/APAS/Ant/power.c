	/*edit*/

/*custom header*/

	/*end_edit*/
#include <stdio.h>
float power1(float num, int p);
void power2(float num, int p, float *result);
int main()
{
   int power;
   float number, result=-1;
   
   printf("Enter the number and power: \n");
   scanf("%f %d", &number, &power);
   printf("power1(): %.2f\n", power1(number, power));                          
   power2(number,power,&result);
   printf("power2(): %.2f\n", result);              
   return 0;
}
float power1(float num, int p)
{
	/*edit*/
   /* Write your code here */
 int count;
    float results;
    
    if(p < 0) 
    {
        results = 1 / num;
        count = -1;
    }
    else
    
    {
        results = num;
        count = 1;
    }

    while(count != p)
    {
        if(p > 0)
        {
            results = (results*num) ;
            count ++;
        }
        else if (p < 0)
        {
            printf("%f\n" , results);
            results = (results* (1 / num)) ;
            count--;
        }
        else
        {
            results = 1;
            break;
        }
    }

    return results;
	/*end_edit*/
}
void power2(float num, int p, float *result)
{
	/*edit*/
   /* Write your code here */
    int count;
    
    //Reset 
    if(p < 0) 
    {
        *result = 1 / num;
        count = -1;
    }
    else
    {
        *result = num;
        count = 1;
    }

    while(count != p)
    {
        if(p > 0)
        {
            *result = (*result *num) ;
            count ++;
        }
        else if (p < 0)
        {
            printf("%f\n" , *result);
            *result = (*result * (1 / num)) ;
            count--;
        }
        else
        {
            *result = 1;
            break;
        }
    }

    return *result;

	/*end_edit*/
}