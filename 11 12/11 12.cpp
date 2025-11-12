#include <stdio.h>
#include <math.h>

int main(void) {
    double data[10];
    double mean = 0.0, variance = 0.0, stddev = 0.0;
    int rank[10];
    int i, j;

    printf("실수 10개를 입력하세요:\n");
    for (i = 0; i < 10; i++) {
        printf("%2d번째 실수: ", i + 1);
        if (scanf_s("%lf", &data[i]) != 1) {   
            printf("입력 오류!\n");
            return 1;
        }
    }

    for (i = 0; i < 10; i++) mean += data[i];
    mean /= 10.0;

    for (i = 0; i < 10; i++)
        variance += (data[i] - mean) * (data[i] - mean);
    variance /= 10.0;
    stddev = sqrt(variance);

    for (i = 0; i < 10; i++) {
        rank[i] = 1;
        for (j = 0; j < 10; j++) {
            if (data[j] > data[i]) rank[i]++;
        }
    }

    printf("\n순번\t입력값\t\t순위\n");
    for (i = 0; i < 10; i++) {
        printf("%2d\t%8.3f\t%2d\n", i + 1, data[i], rank[i]);
    }

    printf("\n전체 데이터 평균: %.3f\n", mean);
    printf("전체 데이터 분산: %.3f\n", variance);
    printf("전체 데이터 표준편차: %.3f\n", stddev);

    return 0;
}
