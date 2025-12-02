#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_matrix(double M[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) printf("%6.2f ", M[i][j]);
        printf("\n");
    }
}

void print_matrix_int(int M[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) printf("%4d ", M[i][j]);
        printf("\n");
    }
}

int det3(int A[3][3]) {
    return
        A[0][0] * (A[1][1] * A[2][2] - A[1][2] * A[2][1])
        - A[0][1] * (A[1][0] * A[2][2] - A[1][2] * A[2][0])
        + A[0][2] * (A[1][0] * A[2][1] - A[1][1] * A[2][0]);
}

void inverse3(int A[3][3], double inv[3][3]) {
    int d = det3(A);
    double det = (double)d;

    inv[0][0] = (A[1][1] * A[2][2] - A[1][2] * A[2][1]) / det;
    inv[0][1] = -(A[0][1] * A[2][2] - A[0][2] * A[2][1]) / det;
    inv[0][2] = (A[0][1] * A[1][2] - A[0][2] * A[1][1]) / det;

    inv[1][0] = -(A[1][0] * A[2][2] - A[1][2] * A[2][0]) / det;
    inv[1][1] = (A[0][0] * A[2][2] - A[0][2] * A[2][0]) / det;
    inv[1][2] = -(A[0][0] * A[1][2] - A[0][2] * A[1][0]) / det;

    inv[2][0] = (A[1][0] * A[2][1] - A[1][1] * A[2][0]) / det;
    inv[2][1] = -(A[0][0] * A[2][1] - A[0][1] * A[2][0]) / det;
    inv[2][2] = (A[0][0] * A[1][1] - A[0][1] * A[1][0]) / det;
}

void add(int A[3][3], int B[3][3], int C[3][3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            C[i][j] = A[i][j] + B[i][j];
}

void sub(int A[3][3], int B[3][3], int C[3][3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            C[i][j] = A[i][j] - B[i][j];
}

void scalar_mul(int A[3][3], int k, int C[3][3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            C[i][j] = k * A[i][j];
}

void matmul(int A[3][3], int B[3][3], int C[3][3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) {
            C[i][j] = 0;
            for (int k = 0; k < 3; k++)
                C[i][j] += A[i][k] * B[k][j];
        }
}

int main() {
    srand(time(NULL));

    int A[3][3], B[3][3], C[3][3], k;

    // 랜덤 행렬 생성
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) {
            A[i][j] = rand() % 10;
            B[i][j] = rand() % 10;
        }
    k = rand() % 10;

    printf("Matrix A:\n"); print_matrix_int(A);
    printf("\nMatrix B:\n"); print_matrix_int(B);
    printf("\nScalar k = %d\n\n", k);

    add(A, B, C);
    printf("A + B:\n"); print_matrix_int(C);

    sub(A, B, C);
    printf("\nA - B:\n"); print_matrix_int(C);

    scalar_mul(A, k, C);
    printf("\nkA:\n"); print_matrix_int(C);

    matmul(A, B, C);
    printf("\nA * B:\n"); print_matrix_int(C);

    int d = det3(A);
    printf("\nDet(A) = %d\n", d);

    if (d != 0) {
        double invA[3][3];
        inverse3(A, invA);
        printf("\nInverse(A):\n");
        print_matrix(invA);
    }
    else {
        printf("\nInverse does not exist (det=0)\n");
    }

    return 0;
}
