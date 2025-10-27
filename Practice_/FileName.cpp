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
    printf("µÎ Á¤¼ö¸¦ ÀÔ·ÂÇÏ¼¼¿ä: ");
    scanf("%d %d", &x, &y);

    printf("µ¡¼À °á°ú: %d\n", add(x, y));
    printf("»¬¼À °á°ú: %d\n", sub(x, y));
    printf("°ö¼À °á°ú: %d\n", mul(x, y));
    printf("³ª´°¼À °á°ú: %.2f\n", divi(x, y));
    printf("³ª¸ÓÁö °á°ú: %d\n", mod(x, y));

    return 0;
}

int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mul(int a, int b) { return a * b; }
float divi(int a, int b) { return (float)a / b; }
int mod(int a, int b) { return a % b; }
