#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int add(int a, int b);
int sub(int a, int b);
int mul(int a, int b);
float divi(int a, int b);
int mod(int a, int b);

int main(void)
{
    int x, y;
    printf("�� ������ �Է��ϼ���: ");
    scanf("%d %d", &x, &y);

    printf("���� ���: %d\n", add(x, y));
    printf("���� ���: %d\n", sub(x, y));
    printf("���� ���: %d\n", mul(x, y));
    printf("������ ���: %.2f\n", divi(x, y));
    printf("������ ���: %d\n", mod(x, y));

    return 0;
}

int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mul(int a, int b) { return a * b; }
float divi(int a, int b) { return (float)a / b; }
int mod(int a, int b) { return a % b; }
