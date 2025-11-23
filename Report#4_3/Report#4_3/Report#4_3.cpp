#include <stdio.h>

// 내적 함수
double DotProduct(double* a, double* b)
{
    return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
}

// 외적 함수
void CrossProduct(double* a, double* b, double* result)
{
    result[0] = a[1] * b[2] - a[2] * b[1];
    result[1] = a[2] * b[0] - a[0] * b[2];
    result[2] = a[0] * b[1] - a[1] * b[0];
}

int main(void)
{
    double A[3], B[3], C[3];

    printf("3D 벡터 A(x y z) 입력: ");
    scanf_s("%lf %lf %lf", &A[0], &A[1], &A[2]);

    printf("3D 벡터 B(x y z) 입력: ");
    scanf_s("%lf %lf %lf", &B[0], &B[1], &B[2]);

    double dot = DotProduct(A, B);
    CrossProduct(A, B, C);

    printf("\n내적 = %.4lf\n", dot);
    printf("외적 = (%.4lf, %.4lf, %.4lf)\n", C[0], C[1], C[2]);

    printf("\n※ 공학용 계산기와 결과 비교하세요.\n");

    return 0;
}
