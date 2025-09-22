#include <stdio.h>

int main() {
    char singleChar = 'A';
    
    const char* message = "First \tline\nIndented second line\nThird line";
    double average = 87.3524;

    printf("=== Char/String & Escapes ===\n");
    printf("Char : %c, code: %d\n", singleChar, singleChar);
    printf("Message:\n%s\n", message);
    printf("Quotes: \"double quotes\" and 'single quotes'\n");
    printf("Backslash: \\\n");
    printf("Average: [%8.2f]\n", average);

    return 0;
}