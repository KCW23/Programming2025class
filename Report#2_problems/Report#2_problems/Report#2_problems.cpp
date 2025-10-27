#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char door_state[10];  // �� ����: open �Ǵ� closed
    double open_time;     // ���� ���� �ð� (��)
    double temp;          // �µ� (��C)
    char result[20];      // ��� ����� (���ǿ����ڿ�)

    printf("�� ���¸� �Է��ϼ��� (open �Ǵ� closed): ");
    if (scanf("%s", door_state) != 1) {
        printf("invalid input\n");
        return 1;
    }

    printf("���� ���� �ð��� �Է��ϼ��� (��): ");
    if (scanf("%lf", &open_time) != 1) {
        printf("invalid input\n");
        return 1;
    }

    printf("���� �µ��� �Է��ϼ��� (��C): ");
    if (scanf("%lf", &temp) != 1) {
        printf("invalid input\n");
        return 1;
    }

    // �Է°� ��ȿ�� �˻�
    if (open_time < 0.0 || temp < -50.0 || temp > 100.0) {
        printf("invalid input\n");
        return 1;
    }

    // ��ҹ��� ���� ����
    for (int i = 0; door_state[i]; i++) {
        if (door_state[i] >= 'A' && door_state[i] <= 'Z')
            door_state[i] += 'a' - 'A';
    }

    if (strcmp(door_state, "open") != 0 && strcmp(door_state, "closed") != 0) {
        printf("invalid input\n");
        return 1;
    }

    printf("\n=============================\n");
    printf("�� ����: %s\n", door_state);
    printf("���� �ð�: %.1f ��\n", open_time);
    printf("�µ�: %.1f ��C\n", temp);
    printf("=============================\n\n");

    /* ---------- �� if�� ��� ---------- */
    printf("[ if�� ���� ��� ]\n");

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

    /* ---------- �� ���ǿ����� ��� ---------- */
    printf("\n[ ���ǿ����� ���� ��� ]\n");

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
