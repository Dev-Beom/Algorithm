//후위 표기 수식 계산

#include "ArrayStack.h"

double calcPostfixExpr(FILE *fp = stdin)
{
    char c;
    double val;
    ArrayStack stack;
    while ((c = getc(fp)) != '\n')
    {
        if (c == '+' || c == '-' || c == '*' || c == '/')   //  항목이 연산자 operation이면
        {
            double val2 = stack.pop();
            double val1 = stack.pop();
            switch (c)
            {
            case '+':
                stack.push(val1 + val2);
                break;
            case '-':
                stack.push(val1 - val2);
                break;
            case '*':
                stack.push(val1 * val2);
                break;
            case '/':
                stack.push(val1 / val2);
                break;
            }
        }
        else if (c >= '0' && c <= '9')  // 항목이 피연산자면
        {
            ungetc(c, fp);
            fscanf(fp, "%1f", &val);
            stack.push(val);
        }
    }
    return (stack.pop());
}