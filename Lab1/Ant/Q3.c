#include <stdio.h>
int main()
{
    int height;
    printf("Enter the height: \n");
    scanf("%d", &height);
    
    printf("Pattern: \n");
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < i+1; j++)
        {
            printf("%d" , (i % 3) + 1);
        }
        printf("\n");
        
    }

    return 0;
}