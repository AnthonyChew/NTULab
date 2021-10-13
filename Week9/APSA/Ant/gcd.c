	/*edit*/

/*custom header*/

	/*end_edit*/
#include <stdio.h>
int gcd1(int num1, int num2);
void gcd2(int num1, int num2, int *result);
int main()
{
   int x,y,result=-1;      

   printf("Enter 2 numbers: \n");
   scanf("%d %d", &x, &y);
   printf("gcd1(): %d\n", gcd1(x, y)); 
   gcd2(x,y,&result);
   printf("gcd2(): %d\n", result);      
   return 0;
}
int gcd1(int num1, int num2) 
{
	/*edit*/

    int count = 1;
    int GCF = 1;

    while(count < 10)
    {
        if( ((num1 % count) == 0) && ((num2 % count) == 0) )
        {
            GCF = count;
        }

        count++;
    }

    return GCF;
	/*end_edit*/
}

void gcd2(int num1, int num2, int *result) 
{
	/*edit*/
   /* Write your code here */
    
    int count = 1;
    *result = 1;

    while(count < 10)
    {
        if( ((num1 % count) == 0) && ((num2 % count) == 0) )
        {
            *result = count;
        }
        
        count++;
    }

	/*end_edit*/
}