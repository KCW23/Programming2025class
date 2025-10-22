#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int dan;
    int i = 2;

    printf("출력할 구구단의 단수를 입력하세요 (2~9, 0은 전체 출력): ");
    if (scanf("%d", &dan) != 1) {
        printf("입력 오류가 발생했습니다.\n");
        return 1;
    }

    if (dan == 0) {
        while (i <= 9) {
            printf("---- %d단 ----\n", i);
            for (int j = 1; j <= 9; j++) {
                printf("%d x %d = %d\n", i, j, i * j);
            }
            i++;
        }
    }
    else if (dan >= 2 && dan <= 9) {
        printf("---- %d단 ----\n", dan);
        for (int j = 1; j <= 9; j++) {
            printf("%d x %d = %d\n", dan, j, dan * j);
        }
    }
    else {
        printf("2에서 9 사이의 수 또는 0만 입력 가능합니다.\n");
    }

    return 0;
}
