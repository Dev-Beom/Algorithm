#define _CRT_SECURE_NO_WARNINGS    // fopen 보안 경고로 인한 컴파일 에러 방지


#include "stdio.h"

// #include "Infix2Postfix.h"  //  중위를 후위로
#include "calcPostfixExpr.h" //  후위 계산



int main(int argc, char const *argv[])
{
    printf("수식 입력 (Infix) = ");
    // infix2Postfix();
    // calcPostfixExpr();
    printf("%f", calcPostfixExpr());
    return 0;
}
