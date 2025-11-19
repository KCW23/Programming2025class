#include <stdio.h>

void get_line(double* p1, double* p2, double* slope, double* bias)
{
    double x1 = p1[0], y1 = p1[1];
    double x2 = p2[0], y2 = p2[1];

    *slope = (y2 - y1) / (x2 - x1);
    *bias = y1 - (*slope) * x1;
}

int main(void)
{
    double point1[2];
    double point2[2];
    double slope, bias;

    printf("Input 1st point information:\n");
    scanf_s("%lf %lf", &point1[0], &point1[1]);

    printf("Input 2nd point information:\n");
    scanf_s("%lf %lf", &point2[0], &point2[1]);

    get_line(point1, point2, &slope, &bias);

    printf("\nCalculated Output, line equation:\n");
    printf("slope: %.4lf\n", slope);
    printf("bias: %.4lf\n", bias);

    return 0;
}
