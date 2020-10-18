#define _CRT_SECURE_NO_WARNINGS    // fopen 보안 경고로 인한 컴파일 에러 방지

// #include "Infix2Postfix.h"
#include "calcPostfixExpr.h"


int main(int argc, char const *argv[])
{
    printf("수식 입력 (Infix) = ");
    // infix2Postfix();
    calcPostfixExpr();
    // printf("%s", calcPostfixExpr());
    return 0;
}
