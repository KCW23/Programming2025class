#include <stdio.h>
#include <math.h>

// Visual Studio는 M_PI 정의가 없음 → 직접 정의
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

int main() {
    double x = 0.0, y = 0.0;
    double v0 = 15.0;
    double theta = 75.0 * M_PI / 180.0; // 라디안 변환
    double vx = v0 * cos(theta);
    double vy = v0 * sin(theta);
    double g = 9.81;
    double dt = 0.01;

    double t = 0.0;
    double y_max = 0.0;

    while (1) {
        x += vx * dt;
        y += vy * dt;
        vy -= g * dt;
        t += dt;

        if (y > y_max)
            y_max = y;

        if (y < 0)
            break;
    }

    printf("체공시간 = %.3f sec\n", t);
    printf("최고 높이 = %.3f m\n", y_max);
    printf("수평 사거리 = %.3f m\n", x);

    return 0;
}
