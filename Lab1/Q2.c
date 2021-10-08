#include <stdio.h>
int main()
{
    int numOfline;
    printf("Enter number of lines: \n");
    scanf("%d", &numOfline);

    for (int i = 0; i < numOfline; i++)
    {
        char numFromUser[99] = "";

        printf("Enter line %d (end with -1): \n", i + 1);
        scanf(" %[^\n]s", &numFromUser);

        int count = 0 , numCount = 0;
        float total = 0.0;
        float average;  
        int doneFlag = 1;

        while (doneFlag != 0)
        {
            if ((int)numFromUser[count] == '-' )
            {
                average = total / numCount;
                printf("Average = %.2f\n", average);
                doneFlag = 0;
            }
            else if((int)numFromUser[count] >= 48)
            {
                total += ((int)numFromUser[count] - 48);
                numCount++;
            }

            count++;
        }
    }

    return 0;
}