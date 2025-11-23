#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define TOTAL_NUM 100
#define EXTRACT_NUM 10

void GenRandSeed()
{
    srand((unsigned int)time(NULL));
}

unsigned int GenRandNum(unsigned int range)
{
    return rand() % range;
}

int CalcSum(int* pArr, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += *(pArr + i);
    return sum;
}

double CalcVariance(int* pArr, int n)
{
    int sum = CalcSum(pArr, n);
    double mean = (double)sum / n;

    double var = 0.0;
    for (int i = 0; i < n; i++)
        var += pow(*(pArr + i) - mean, 2);

    return var / n;
}

int main(void)
{
    GenRandSeed();

    int arr[TOTAL_NUM];
    int extracted[EXTRACT_NUM];

    int rangeMax;
    int A, B;

    printf("난수 최대값 입력 (예: 100 → 0~99): ");
    scanf_s("%d", &rangeMax);

    for (int i = 0; i < TOTAL_NUM; i++)
        arr[i] = GenRandNum(rangeMax);

    printf("추출 범위 A B 입력: ");
    scanf_s("%d %d", &A, &B);

    int idx = 0;
    for (int i = 0; i < TOTAL_NUM; i++)
    {
        if (arr[i] >= A && arr[i] <= B)
        {
            extracted[idx] = arr[i];
            idx++;
            if (idx >= EXTRACT_NUM)
                break;
        }
    }

    if (idx < EXTRACT_NUM)
    {
        printf("범위 내 값이 10개 미만입니다. (추출 개수: %d)\n", idx);
        return 0;
    }

    int sum = CalcSum(extracted, EXTRACT_NUM);
    double var = CalcVariance(extracted, EXTRACT_NUM);
    double stdev = sqrt(var);

    printf("\n=== 추출된 10개 정수 ===\n");
    for (int i = 0; i < EXTRACT_NUM; i++)
        printf("%d ", extracted[i]);

    printf("\n\n총합: %d\n", sum);
    printf("분산: %.4lf\n", var);
    printf("표준편차: %.4lf\n", stdev);

    return 0;
}
