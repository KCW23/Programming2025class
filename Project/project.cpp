#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disbale:4966)
#include <stdio.h>

int main(void)
{
	int nAge = 99;
	float fHeight = 999.0f;
	double dWeight = 999.0;

	char chTemp = ' ';
	char chString[100] = " ";

	//printf("Input your information(Age, Height, Weight):\n");
	//scanf_s("%d %flf", &nAge, &fHeight, &dWeight);
	printf("Input your alphabet and word:\n");
	//scanf("%c%s", &chTemp, (unsigned int)sizeof(chTemp), 
	//	chString, (unsigned int)sizeof(chString));
	int nReScanf = scanf("%c%s", &chTemp, chString);

	printf("Output\n", nReScanf);
	//printf("(Age:%d)(Height:%.2f)(Weight:%.1If)\n", nAge, fHeight, dWeight);
	printf("(Alphabet:%c)(Word:%s)\n", chTemp, chString);

	return 0;
}