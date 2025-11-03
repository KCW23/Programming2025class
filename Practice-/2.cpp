#include <stdio.h>

float centi_to_meter(float cm);   // 함수 선언

int main(void)
{
    float res;                    // 반환값 저장 변수
    res = centi_to_meter(187);    // 함수 호출
    printf("%.2fm\n", res);       // 결과 출력 (1.87m)
    return 0;
}

float centi_to_meter(float cm)    // 함수 정의
{
    float meter;                  // 필요한 변수 선언
    meter = cm / 100.0;           // cm → m 변환
    return meter;                 // 변환된 값 반환
}
