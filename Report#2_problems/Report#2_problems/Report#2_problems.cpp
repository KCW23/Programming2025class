#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char door_state[10];  // 문 상태: open 또는 closed
    double open_time;     // 문이 열린 시간 (초)
    double temp;          // 온도 (°C)
    char result[20];      // 결과 저장용 (조건연산자용)

    printf("문 상태를 입력하세요 (open 또는 closed): ");
    if (scanf("%s", door_state) != 1) {
        printf("invalid input\n");
        return 1;
    }

    printf("문이 열린 시간을 입력하세요 (초): ");
    if (scanf("%lf", &open_time) != 1) {
        printf("invalid input\n");
        return 1;
    }

    printf("현재 온도를 입력하세요 (°C): ");
    if (scanf("%lf", &temp) != 1) {
        printf("invalid input\n");
        return 1;
    }

    // 입력값 유효성 검사
    if (open_time < 0.0 || temp < -50.0 || temp > 100.0) {
        printf("invalid input\n");
        return 1;
    }

    // 대소문자 구분 제거
    for (int i = 0; door_state[i]; i++) {
        if (door_state[i] >= 'A' && door_state[i] <= 'Z')
            door_state[i] += 'a' - 'A';
    }

    if (strcmp(door_state, "open") != 0 && strcmp(door_state, "closed") != 0) {
        printf("invalid input\n");
        return 1;
    }

    printf("\n=============================\n");
    printf("문 상태: %s\n", door_state);
    printf("열린 시간: %.1f 초\n", open_time);
    printf("온도: %.1f °C\n", temp);
    printf("=============================\n\n");

    /* ---------- ① if문 방식 ---------- */
    printf("[ if문 판정 결과 ]\n");

    if (strcmp(door_state, "closed") == 0 && temp >= 2.0 && temp <= 8.0) {
        printf("Normal\n");
    }
    else if (strcmp(door_state, "open") == 0 && open_time >= 60.0 &&
        (temp >= 8.0 || temp <= 2.0)) {
        printf("Critical\n");
    }
    else if (strcmp(door_state, "closed") == 0 && (temp < 2.0 || temp > 8.0)) {
        if (open_time <= 30.0)
            printf("Warning\n");
        else
            printf("Critical\n");
    }
    else {
        printf("invalid input\n");
        return 1;
    }

    /* ---------- ② 조건연산자 방식 ---------- */
    printf("\n[ 조건연산자 판정 결과 ]\n");

    strcpy(result,
        (strcmp(door_state, "closed") == 0 && temp >= 2.0 && temp <= 8.0) ? "Normal" :
        (strcmp(door_state, "open") == 0 && open_time >= 60.0 &&
            (temp >= 8.0 || temp <= 2.0)) ? "Critical" :
        (strcmp(door_state, "closed") == 0 && (temp < 2.0 || temp > 8.0) &&
            open_time <= 30.0) ? "Warning" :
        (strcmp(door_state, "closed") == 0 && (temp < 2.0 || temp > 8.0) &&
            open_time > 30.0) ? "Critical" :
        "invalid input"
    );

    printf("%s\n", result);

    return 0;
}
