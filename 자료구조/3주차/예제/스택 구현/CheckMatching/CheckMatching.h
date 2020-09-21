#include "ArrayStack.h"

bool CheckMatching(char *filename)
{
    FILE *fp = fopen(filename, "r");
    ArrayStack stack;

    if (fp == NULL)
    {
        stack.error("Error: 파일이 존재하지 않습니다.\n");
    }

    int nLine = 1, nChar = 0;
    char ch;

    while ((ch = getc(fp)) != EOF)
    {
        if (ch == '\n')
        {
            nLine++;
        }
        nChar++;
        if (ch == '[' || ch == '(' || ch == '{')
            stack.push(ch);
    }
}