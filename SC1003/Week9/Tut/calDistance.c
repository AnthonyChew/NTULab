#include <stdio.h>
#include <math.h>

float calDistance1(float x1, float x2, float y1, float y2);
void calDistance2(float x1, float x2, float y1, float y2 , float *result);
int main()
{
    float x1, x2, y1, y2 , result;
    printf("Please input coordinates:\n");
    scanf("%f %f %f %f", &x1, &x2, &y1, &y2);

    printf("Distance : %f\n", calDistance1(x1, x2, y1, y2));
    calDistance2(x1, x2, y1, y2 , &result);
    printf("Distance : %f\n", result);
}

float calDistance1(float x1, float x2, float y1, float y2)
{
    return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}

void calDistance2(float x1, float x2, float y1, float y2 , float *result)
{
    *result =  sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}