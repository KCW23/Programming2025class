
// 1. MSVC 환경의 안전하지 않은 함수 사용 경고 무시
#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS

// 2. 표준 라이브러리 포함 (E0065 오류 방지)
#include <stdio.h>
#include <string.h>
#include <stdlib.h> // size_t 사용을 위해 포함

// 3. 함수 정의: main 함수보다 먼저 정의 (E0040 오류 방지)
// 표준 입력 버퍼를 비우는 함수
void clear_input_buffer(void)
{ // clear_input_buffer 시작
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
} // clear_input_buffer 끝

// 4. main 함수 시작: C1075 오류 방지를 위해 `{` 확인
int main(void)
{ // main 시작
    // 5. 변수 선언 및 초기화
    char str1[100] = { 0, };
    char str2[100] = { 0, };
    char copy[100] = { 0, };
    char sentence[200] = { 0, };
    char temp[200] = { 0, };

    char* pos = NULL;
    char ch;

    char* p_str1 = str1;
    char* p_str2 = str2;
    char* p_copy = copy;
    char* p_sentence = sentence;
    char* p_temp = temp;

    // --- 문자열 입력 ---
    printf("Enter first string (no spaces): ");
    if (scanf("%99s", p_str1) != 1) return 1;

    printf("Enter second string (no spaces): ");
    if (scanf("%99s", p_str2) != 1) return 1;

    clear_input_buffer(); // 입력 버퍼 잔여물 제거

    printf("\n--- Printed strings ---\n");
    puts(p_str1);
    puts(p_str2);

    // --- sentence 입력 ---
    printf("\nEnter one sentence (can include spaces): ");
    if (fgets(p_sentence, sizeof(sentence), stdin) == NULL) return 1;

    // fgets로 입력된 개행 문자(\n) 제거
    if ((pos = strchr(p_sentence, '\n')) != NULL) {
        *pos = '\0';
    }

    printf("\nYou entered (sentence) = ");
    puts(p_sentence);

    // -------------------------------------------------------------------

    // 1. Practice #1: strncpy (문자열 복사 - 안전 버전)
    printf("\n--- Practice #1: strncpy ---\n");
    strncpy(p_copy, p_str1, sizeof(copy) - 1);
    p_copy[sizeof(copy) - 1] = '\0';
    printf("copy = %s\n", p_copy);

    // -------------------------------------------------------------------

    // 2. Practice #2: strncat (문자열 연결 - 안전 버전)
    printf("\n--- Practice #2: strncat ---\n");
    size_t remaining_space = sizeof(str1) - strlen(p_str1) - 1;

    if (remaining_space > 0) { // if 시작
        strncat(p_str1, p_str2, remaining_space);
        printf("After safe concatenation, str1 = ");
        puts(p_str1);
    } // if 끝
    else { // else 시작
        printf("str1 buffer is too small (0 bytes left) for strcat!\n");
    } // else 끝

    // -------------------------------------------------------------------

    // 3. Practice #3: strcmp (문자열 비교)
    printf("\n--- Practice #3: strcmp ---\n");
    int cmp = strcmp(p_str1, p_str2);
    if (cmp == 0) { // if 시작
        printf("str1 and str2 are equal.\n");
    } // if 끝
    else if (cmp < 0) { // else if 시작
        printf("In lexicographical order, str1 comes before str2.\n");
    } // else if 끝
    else { // else 시작
        printf("In lexicographical order, str1 comes after str2.\n");
    } // else 끝

    // 4. Practice #4: strchr (문자 검색)
    printf("\n--- Practice #4: strchr ---\n");
    printf("\nEnter a character to search for: ");
    if (scanf(" %c", &ch) != 1) return 1;
    clear_input_buffer();

    pos = strchr(p_str1, ch);
    if (pos != NULL) { // if 시작
        printf("'%c' is at index %ld (0-based) in str1.\n",
            ch, (long)(pos - p_str1));
    } // if 끝
    else { // else 시작
        printf("'%c' is not found in str1.\n", ch);
    } // else 끝

    // 5. Practice #5: strstr (부분 문자열 검색)
    printf("\n--- Practice #5: strstr ---\n");
    pos = strstr(p_sentence, p_str2);
    if (pos != NULL) { // if 시작
        printf("Found \"%s\" inside sentence.\n", p_str2);
        printf("Substring starting from the found position:");
        puts(pos);
    } // if 끝
    else { // else 시작
        printf("Could not find \"%s\" in sentence.\n", p_str2);
    } // else 끝

    // 6. Practice #6: strtok (문자열 분리/토큰화)
    printf("\n--- Practice #6: strtok ---\n");
    printf("\n--- strtok practice: split sentence by spaces ---\n");

    strncpy(p_temp, p_sentence, sizeof(temp) - 1);
    p_temp[sizeof(temp) - 1] = '\0';

    char* token = strtok(p_temp, " ");
    int i = 1;
    while (token != NULL) { // while 시작
        printf("Token %d: ", i++);
        puts(token);
        token = strtok(NULL, " ");
    } // while 끝

    printf("\nProgram finished.\n");
    return 0;
} // main 끝 (이것이 파일의 마지막 문자가 되어야 합니다!)