#include <stdio.h>

float centi_to_meter(float cm);   // �Լ� ����

int main(void)
{
    float res;                    // ��ȯ�� ���� ����
    res = centi_to_meter(187);    // �Լ� ȣ��
    printf("%.2fm\n", res);       // ��� ��� (1.87m)
    return 0;
}

float centi_to_meter(float cm)    // �Լ� ����
{
    float meter;                  // �ʿ��� ���� ����
    meter = cm / 100.0;           // cm �� m ��ȯ
    return meter;                 // ��ȯ�� �� ��ȯ
}
