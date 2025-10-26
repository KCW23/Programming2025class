#define _CRT_SECURE_NO_WARNINGS   // scanf ��� ���� (Visual Studio ����)
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    const double rho = 998.2;    // �е� (kg/m��)
    const double mu = 0.001002; // ������� (Pa��s)
    const double D = 0.05;     // ������ (m)
    double V;                    // ���� (m/s)

    printf("���� V�� �Է��ϼ��� (m/s): ");
    if (scanf("%lf", &V) != 1) {
        printf("invalid input\n");
        return 1;
    }

    if (V < 0.0) {
        printf("invalid input\n");
        return 1;
    }

    // ���̳��� �� �� ���� ���
    double Re = rho * V * D / mu;
    double q = 0.5 * rho * V * V;

    printf("\n=============================\n");
    printf("�Է� ���� V = %.3f m/s\n", V);
    printf("Reynolds �� = %.2f\n", Re);

    // ���� ���� ����
    if (Re < 2300.0)
        printf("���� ����: ���� (Laminar)\n");
    else if (Re <= 4000.0)
        printf("���� ����: õ�̿��� (Transitional)\n");
    else
        printf("���� ����: ���� (Turbulent)\n");

    // ���� ���
    printf("���� (Dynamic pressure) q = %.3f Pa\n", q);
    printf("=============================\n");

    return 0;
}
