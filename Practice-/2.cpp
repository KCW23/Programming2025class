#include <stdio.h>

int rec_func(int n);  // �Լ� ����

int main(void)
{
    int result;
    result = rec_func(10);     // 1���� 10������ ��
    printf("%d\n", result);    // ���� ���: 55
    return 0;
}

int rec_func(int n)            // �Լ� ����
{
    if (n == 1)                // ���� ����
        return 1;
    else
        return n + rec_func(n - 1);  // ��� ȣ��
}
