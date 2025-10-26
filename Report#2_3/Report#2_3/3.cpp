#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Visual Studio에서는 M_PI가 정의되어 있지 않으므로 직접 정의 */
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

int main(void) {
    const double g = 9.81;     // 중력가속도
    const double mu_s = 0.5;   // 정지마찰계수
    const double mu_k = 0.4;   // 동마찰계수
    double theta_deg;          // 입력받을 경사각(도)

    printf("경사각 θ를 도 단위로 입력하세요 (예: 30): ");
    if (scanf("%lf", &theta_deg) != 1) {
        printf("invalid input\n");
        return 1;
    }

    // 유효성 검사
    if (theta_deg < 0.0 || theta_deg >= 90.0) {
        printf("invalid input\n");
        return 1;
    }

    // 임계각 계산 (라디안 → 도 변환)
    double theta_crit_deg = atan(mu_s) * 180.0 / M_PI;

    // 입력각을 라디안으로 변환
    double theta_rad = theta_deg * M_PI / 180.0;

    // 판정
    if (tan(theta_rad) <= mu_s) {
        printf("\n판정: 정지 (미끄러지지 않음)\n");
        printf("입력 각도: %.2f°\n", theta_deg);
        printf("임계각: %.2f° (%.6f 라디안)\n", theta_crit_deg, atan(mu_s));
    }
    else {
        double a = g * (sin(theta_rad) - mu_k * cos(theta_rad));
        if (a < 0) a = 0.0;  // 수치오차 보정
        printf("\n판정: 미끄러짐 (아래 방향)\n");
        printf("입력 각도: %.2f°\n", theta_deg);
        printf("가속도 a = %.6f m/s²\n", a);
        printf("임계각: %.2f° (%.6f 라디안)\n", theta_crit_deg, atan(mu_s));
    }

    return 0;
}
