#include <stdio.h>
#include <math.h>
int main(){
    float x, answer;

    printf("Enter x:\n");
    scanf("%f", &x);
    
    answer = exp(x);
    printf("Result = %.2f", answer);

    return 0
}
