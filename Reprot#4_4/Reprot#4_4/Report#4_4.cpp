#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LOTTO_NUM 6
#define MAX_NUM 45

// Random Seed
void GenRandSeed()
{
    srand((unsigned int)time(NULL));
}

// 중복 없는 번호 생성
void GenLottoNumbers(int* lotto)
{
    int i = 0;
    while (i < LOTTO_NUM)
    {
        int num = rand() % MAX_NUM + 1;
        int duplicate = 0;

        for (int j = 0; j < i; j++)
        {
            if (lotto[j] == num)
            {
                duplicate = 1;
                break;
            }
        }

        if (!duplicate)
        {
            lotto[i] = num;
            i++;
        }
    }
}

// 일치 개수 계산
int CountMatches(int* com, int* user)
{
    int count = 0;
    for (int i = 0; i < LOTTO_NUM; i++)
        for (int j = 0; j < LOTTO_NUM; j++)
            if (com[i] == user[j])
                count++;
    return count;
}

// 등수 결정
void PrintRank(int match)
{
    if (match == 6)
        printf("★ 1등 당첨! 축하합니다!!\n");
    else if (match == 5)
        printf("★ 3등 당첨!\n");
    else if (match == 4)
        printf("★ 4등 당첨!\n");
    else if (match == 3)
        printf("★ 5등 당첨!\n");
    else
        printf("꽝입니다...\n");
}

int main(void)
{
    GenRandSeed();

    int lotto[LOTTO_NUM];
    int user[LOTTO_NUM];

    // 로또 번호 생성
    GenLottoNumbers(lotto);

    // 사용자 입력
    printf("당신의 로또 번호 6개를 입력하세요 (1~45):\n");
    for (int i = 0; i < LOTTO_NUM; i++)
        scanf_s("%d", &user[i]);

    // 일치 개수
    int match = CountMatches(lotto, user);

    // 결과 출력
    printf("\n=== 로또 결과 ===\n");
    printf("컴퓨터 번호: ");
    for (int i = 0; i < LOTTO_NUM; i++)
        printf("%d ", lotto[i]);

    printf("\n사용자 번호: ");
    for (int i = 0; i < LOTTO_NUM; i++)
        printf("%d ", user[i]);

    printf("\n\n일치 개수: %d개\n", match);

    // 등수 출력
    PrintRank(match);

    return 0;
}
