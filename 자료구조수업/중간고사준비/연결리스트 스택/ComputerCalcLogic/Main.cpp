#define _CRT_SECURE_NO_WARNINGS

#include "stdio.h"
#include "Infix2Postfix.h"
#include "calcPostfixExpr.h"

int main(int argc, char const *argv[])
{

    printf("수식 입력 (Infix) = ");
    infix2Postfix();
    printf("\n");

    printf("수식 입력 (Postfix) = ");
    printf("%f", calcPostfixExpr());

    return 0;
}
