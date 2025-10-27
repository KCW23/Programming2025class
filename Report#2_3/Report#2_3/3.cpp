#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Visual Studio������ M_PI�� ���ǵǾ� ���� �����Ƿ� ���� ���� */
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

int main(void) {
    const double g = 9.81;     // �߷°��ӵ�
    const double mu_s = 0.5;   // �����������
    const double mu_k = 0.4;   // ���������
    double theta_deg;          // �Է¹��� ��簢(��)

    printf("��簢 �踦 �� ������ �Է��ϼ��� (��: 30): ");
    if (scanf("%lf", &theta_deg) != 1) {
        printf("invalid input\n");
        return 1;
    }

    // ��ȿ�� �˻�
    if (theta_deg < 0.0 || theta_deg >= 90.0) {
        printf("invalid input\n");
        return 1;
    }

    // �Ӱ谢 ��� (���� �� �� ��ȯ)
    double theta_crit_deg = atan(mu_s) * 180.0 / M_PI;

    // �Է°��� �������� ��ȯ
    double theta_rad = theta_deg * M_PI / 180.0;

    // ����
    if (tan(theta_rad) <= mu_s) {
        printf("\n����: ���� (�̲������� ����)\n");
        printf("�Է� ����: %.2f��\n", theta_deg);
        printf("�Ӱ谢: %.2f�� (%.6f ����)\n", theta_crit_deg, atan(mu_s));
    }
    else {
        double a = g * (sin(theta_rad) - mu_k * cos(theta_rad));
        if (a < 0) a = 0.0;  // ��ġ���� ����
        printf("\n����: �̲����� (�Ʒ� ����)\n");
        printf("�Է� ����: %.2f��\n", theta_deg);
        printf("���ӵ� a = %.6f m/s��\n", a);
        printf("�Ӱ谢: %.2f�� (%.6f ����)\n", theta_crit_deg, atan(mu_s));
    }

    return 0;
}
