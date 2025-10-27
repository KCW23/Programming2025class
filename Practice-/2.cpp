#include <stdio.h>

int rec_func(int n);  // 함수 선언

int main(void)
{
    int result;
    result = rec_func(10);     // 1부터 10까지의 합
    printf("%d\n", result);    // 실행 결과: 55
    return 0;
}

int rec_func(int n)            // 함수 정의
{
    if (n == 1)                // 종료 조건
        return 1;
    else
        return n + rec_func(n - 1);  // 재귀 호출
}
