#include <stdio.h>
#include <math.h>

int main()
{
    int number;
    int *p;

    p = &number;
    printf("%d,%d,%d,%s,%d",number,&number,p,&p,*p);
   
    return 0;
}