#include <stdio.h>
int main(){
    float x, answer, numer, denom;
    int i;
    printf("Enter x:\n");
    scanf("%f", &x);
    answer = numer = denom = 1;

    for (i=1; i<=10; i++){
        numer *= x;
        denom *= i;
        answer += numer/denom;
    }

    printf("Result = %.2f", answer);

    return 0
}
