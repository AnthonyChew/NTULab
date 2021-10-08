#include <stdio.h>
int main(){
    int line_num, num, total, num_count, i;
    float avg;
    printf("Enter number of lines:\n");
    scanf("%d", &line_num);
    
    for (i=1; i<=line_num; i++){
        printf("Enter line %d (end with -1):\n", i);
        num = total = num_count = 0;
        scanf("%d", &num);
        
        do {
            total += num;
            num_count++;
            scanf("%d", &num);
        } while (num != -1);
        
        avg = (float)total/(float)num_count;
        printf("Average = %.2f", avg);
    }
    return 0
}
