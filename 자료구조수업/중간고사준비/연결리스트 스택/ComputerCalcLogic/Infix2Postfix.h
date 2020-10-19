//  중위식을 후위식으로 변환

#include "LinkedStack.h"

int precedence(char op)
{
    switch (op)
    {
    case '(':
    case ')':
        return 0;
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    }
    return -1;
}

void infix2Postfix(FILE *fp = stdin)
{
    char c, op;
    double val;

    Node *tmpNode;
    LinkedStack stack;

    while ((c = getc(fp)) != '\n')
    {
        if ((c >= '0' && c <= '9'))
        {
            ungetc(c, fp);
            fscanf(fp, "%lf", &val);
            printf("%4.1f", val);
        }
        else if (c == '(')
        {
            stack.push(new Node(c));
        }
        else if (c == ')')
        {
            while (!stack.isEmpty())
            {
                op = stack.pop()->getData();
                if (op == '(')
                {
                    break;
                }
                else
                {
                    printf("%c ", op);
                }
            }
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/')
        {
            while (!stack.isEmpty())
            {
                op = stack.peek()->getData();
                if (precedence(c) <= precedence(op))
                {
                    printf("%c ", op);
                    stack.pop();
                }
                else
                {
                    break;
                }
            }
            stack.push(new Node(c));
        }
    }
    while (!stack.isEmpty())
    {
        printf("%c ", stack.pop()->getData());
    }
}