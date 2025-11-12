#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N 10  // 정수 개수

// 합계 계산 함수
int getSum(int arr[]) {
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += arr[i];
    }
    return sum;
}

// 평균 계산 함수
double getMean(int arr[]) {
    return (double)getSum(arr) / N;
}

// 분산 계산 함수
double getVariance(int arr[]) {
    double mean = getMean(arr);
    double var = 0.0;
    for (int i = 0; i < N; i++) {
        var += (arr[i] - mean) * (arr[i] - mean);
    }
    return var / N;
}

// 표준편차 계산 함수
double getStdDev(int arr[]) {
    return sqrt(getVariance(arr));
}

int main(void) {
    int numbers[N];
    int min = 1, max = 100; // 난수 범위 지정
    srand(time(NULL));

    printf("=== 무작위 정수 생성 ===\n");
    for (int i = 0; i < N; i++) {
        numbers[i] = rand() % (max - min + 1) + min; // 1~100 사이 난수 생성
        printf("%d ", numbers[i]);
    }

    printf("\n\n=== 계산 결과 ===\n");
    int sum = getSum(numbers);
    double mean = getMean(numbers);
    double var = getVariance(numbers);
    double stddev = getStdDev(numbers);

    printf("총합: %d\n", sum);
    printf("평균: %.2f\n", mean);
    printf("분산: %.2f\n", var);
    printf("표준편차: %.2f\n", stddev);

    // 선택문 사용 예시: 평균 기준 판단
    if (mean >= 50)
        printf("평균이 50 이상이므로 높은 값입니다.\n");
    else
        printf("평균이 50 미만이므로 낮은 값입니다.\n");

    return 0;
}
