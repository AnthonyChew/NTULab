#include <stdio.h>
#include <math.h>

int main()
{
    char userChar;
    printf("Enter a character:\n");

    scanf("%c", &userChar);

    if(userChar >= 48 && userChar <= 57)
    {
        printf("Digit");
    }
    else if (userChar >= 65 && userChar <= 90)
    {
        printf("Upper case letter");
    }    
    else if (userChar >= 97 && userChar <= 122)
    {
        printf("Lower case letter");
    }
    else
    {
        printf("Other character");
    }
    
    
   
    return 0;
}