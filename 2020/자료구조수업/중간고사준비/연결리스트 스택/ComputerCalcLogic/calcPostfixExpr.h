//  후위 표기 수식 계산

#include "LinkedStack.h"
#include <iostream>

using namespace std;

double calcPostfixExpr(FILE *fp = stdin)
{

    char c;
    double val;
    LinkedStack stack;

    while ((c = getc(fp)) != '\n')
    {

        if (c == '+' || c == '-' || c == '*' || c == '/') //  항목이 연산자 operation이면
        {

            double val2 = stack.pop()->getData();
            double val1 = stack.pop()->getData();

            switch (c)
            {
            case '+':
                stack.push(new Node(val1 + val2));
                break;
            case '-':
                stack.push(new Node(val1 - val2));
                break;
            case '*':
                stack.push(new Node(val1 * val2));
                break;
            case '/':
                stack.push(new Node(val1 / val2));
                break;
            }
        }
        else if (c >= '0' && c <= '9')
        {
            ungetc(c, fp);
            fscanf(fp, "%lf", &val);
            stack.push(new Node(val));
        }
    }

    return (stack.pop()->getData());
}