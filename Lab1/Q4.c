#include <stdio.h>
#include <math.h>

int main()
{
    double userInput , result;
    printf("Enter x: \n");
    scanf("%lf", &userInput);

    result = exp(userInput);

    printf("Result = %.2f" , result);

    return 0;
}