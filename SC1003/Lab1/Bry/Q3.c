#include <stdio.h>
int main(){
    int num_list[3] = {1,2,3}, index, num, height, i, j;
    printf("Enter the height:\n");
    scanf("%d", &height);
    printf("Pattern:\n");

    for (i=0;i<height;i++){
        index = i%3; 
        num = num_list[index];
    
        for (j=0;j<=i;j++){
            printf("%d", num);
        }

        printf("\n");
    }
    return 0
}
