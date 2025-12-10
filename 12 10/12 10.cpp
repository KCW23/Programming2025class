#include <stdio.h>
#include <string.h>

struct MyStruct {
    int   a;
    float b;
    char  c[10];
};

union MyUnion {
    int   a;
    float b;
    char  c[10];
};

int main(void) {
    struct MyStruct s;
    union MyUnion  u;

    printf("sizeof(struct MyStruct) = %zu\n", sizeof(s));
    printf("sizeof(union  MyUnion ) = %zu\n\n", sizeof(u));

    // --- 구조체(struct) ---
    printf("=== 구조체(struct) 예제 ===\n");
    s.a = 10;
    s.b = 3.14f;
    strncpy_s(s.c, sizeof(s.c), "Hello", _TRUNCATE);

    printf("s.a = %d\n", s.a);
    printf("s.b = %.2f\n", s.b);
    printf("s.c = %s\n\n", s.c);

    // --- 공용체(union) ---
    printf("=== 공용체(union) 예제 ===\n");
    strncpy_s(u.c, sizeof(u.c), "Hello", _TRUNCATE);
    printf("u.c = %s\n", u.c);

    u.a = 100;  // 같은 메모리 덮어쓰기
    printf("u.a = %d\n", u.a);
    printf("u.c(덮어쓰기 후) = %s\n", u.c);   // 깨짐

    u.b = 3.14f;  // 다시 덮어쓰기
    printf("u.b = %.2f\n", u.b);
    printf("u.a(다시 덮어쓰기 후) = %d\n", u.a);
}
