#define _CRT_SECURE_NO_WARNINGS  // C4996 경고 제거
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 업다운 게임 함수 선언
void playGame(void);

int main(void) {
    playGame();  // 함수 호출
    return 0;
}

void playGame(void) {
    int answer = 0;    // 컴퓨터가 생성한 정답
    int guess = 0;     // 사용자가 입력한 숫자
    int tries = 0;     // 시도 횟수

    srand((unsigned int)time(NULL));  // C4244 방지 (형 변환 명시)
    answer = rand() % 100 + 1;        // 1~100 사이 난수 생성

    printf("=== 업다운 게임을 시작합니다! ===\n");
    printf("1부터 100 사이의 숫자를 맞혀보세요. (총 10회 시도 가능)\n");

    while (tries < 10) {
        printf("\n%d번째 시도 - 숫자 입력: ", tries + 1);

        // C6031 방지: scanf의 반환값 확인
        if (scanf("%d", &guess) != 1) {
            printf("잘못된 입력입니다. 프로그램을 종료합니다.\n");
            return;
        }

        tries++;

        // 조건문 (선택문) 처리
        if (guess == answer) {
            printf("정답입니다! %d번째 만에 맞히셨습니다!\n", tries);
            return;
        }
        else if (guess < answer) {
            printf("Up! 더 큰 수를 입력하세요.\n");
        }
        else {
            printf("Down! 더 작은 수를 입력하세요.\n");
        }
    }

    printf("\n기회가 모두 소진되었습니다. 정답은 %d였습니다.\n", answer);
}

