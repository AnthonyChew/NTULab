#include <stdio.h>
int main(){
    int student_id, mark;
    char grade;
    printf("Enter Student ID:\n");
    scanf("%d", &student_id);

    do {
        printf("Enter Mark:\n");
        scanf("%d", &mark);

        if (mark >= 75){
            grade = 'A';
        }
        else if (mark >= 65){
            grade = 'B';
        }
        else if (mark >= 55){
            grade = 'C';
        }
        else if (mark >= 45){
            grade = 'D';
        }
        else {
            grade = 'F';
        }
        printf("Grade = %c\n", grade);

        printf("Enter Student ID:\n");
        scanf("%d", &student_id);
    } while (student_id != -1);

    return 0
}
