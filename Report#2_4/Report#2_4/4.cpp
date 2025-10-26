#define _CRT_SECURE_NO_WARNINGS   // scanf 경고 방지 (Visual Studio 전용)
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    const double rho = 998.2;    // 밀도 (kg/m³)
    const double mu = 0.001002; // 점성계수 (Pa·s)
    const double D = 0.05;     // 관내경 (m)
    double V;                    // 유속 (m/s)

    printf("유속 V를 입력하세요 (m/s): ");
    if (scanf("%lf", &V) != 1) {
        printf("invalid input\n");
        return 1;
    }

    if (V < 0.0) {
        printf("invalid input\n");
        return 1;
    }

    // 레이놀즈 수 및 동압 계산
    double Re = rho * V * D / mu;
    double q = 0.5 * rho * V * V;

    printf("\n=============================\n");
    printf("입력 유속 V = %.3f m/s\n", V);
    printf("Reynolds 수 = %.2f\n", Re);

    // 유동 상태 판정
    if (Re < 2300.0)
        printf("유동 상태: 층류 (Laminar)\n");
    else if (Re <= 4000.0)
        printf("유동 상태: 천이영역 (Transitional)\n");
    else
        printf("유동 상태: 난류 (Turbulent)\n");

    // 동압 출력
    printf("동압 (Dynamic pressure) q = %.3f Pa\n", q);
    printf("=============================\n");

    return 0;
}
