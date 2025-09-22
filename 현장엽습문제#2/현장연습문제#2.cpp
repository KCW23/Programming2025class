#include <stdio.h>

#define PI_VALUE 3.14159265358979323846

int main(void)
{
	const int year = 2025;

	const char* title = "C \"printf\"demo:";
	int widt_demo_num = 123;

	char sample_char = 'A';

	printf("===Constants & Formats ===\n");
		
	printf("Course; C Programming (v1, %u))\n", year);

	printf("Title : %s\n", title);

	printf("Pl defalut \t : %f\n", PI_VALUE);
    printf("Pl 2 sigits \t : %.2f\n", PI_VALUE);

	printf("Width demo \t : [%8d]\n", widt_demo_num);

	printf("Char sample \t : %c\n", sample_char);
	printf("Backs Iach \t : \\\\n");
	return 0;
}