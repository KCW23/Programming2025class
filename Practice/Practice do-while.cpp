#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int dan;
    int i = 2;

    printf("����� ������ �ܼ� �Է� (2~9 �Ǵ� 0: ��ü ���): ");
    if (scanf("%d", &dan) != 1) {
        printf("�Է� ���� �߻�\n");
        return 1;
    }

    if (dan == 0) {
        do {
            printf("---- %d�� ----\n", i);
            for (int j = 1; j <= 9; j++) {
                printf("%d x %d = %d\n", i, j, i * j);
            }
            i++;
        } while (i <= 9);
    }
    else if (dan >= 2 && dan <= 9) {
        printf("---- %d�� ----\n", dan);
        for (int j = 1; j <= 9; j++) {
            printf("%d x %d = %d\n", dan, j, dan * j);
        }
    }
    else {
        printf("2���� 9 ������ �� �Ǵ� 0�� �Է� �����մϴ�.\n");
    }

    return 0;
}
