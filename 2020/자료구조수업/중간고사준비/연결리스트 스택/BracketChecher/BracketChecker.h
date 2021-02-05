
#include "LinkedStack.h"

bool CheckMatching(char *filename)
{
    FILE *fp;
    fp = fopen(filename, "r");
    printf("%s\n", filename);

    LinkedStack stack;
    int nLine = 1, nChar = 0;
    char ch;
    Node *prev;

    if (fp == NULL)
    {
        printf("Error: 파일이 존재하지 않습니다.\n");
    }

    while ((ch = getc(fp)) != EOF)
    {
        if (ch == '\n')
        {
            nLine++;
        }
        nChar++;
        if (ch == '[' || ch == '(' || ch == '{')
        {
            stack.push(new Node(ch));
        }
        else if (ch == ']' || ch == ')' || ch == '}')
        {
            prev = stack.pop();
            int data = prev->getData();
            if ((ch == ']' && data != '[') || (ch == ')' && data != '(') || (ch == '}' && data != '{'))
            {
                break;
            }
        }
    }
    fclose(fp);
    printf("[%s] 파일 검사 결과:\n", filename);
    if (!stack.isEmpty())
    {
        printf("Error! (라인수 = %d, 문자수 = %d)\n\n", nLine, nChar);
    }
    else
    {
        printf("   OK! (라인수 = %d, 문자수 = %d)\n\n", nLine, nChar);
    }
    return stack.isEmpty();
}