#include <iostream>

void reverse(char *s)
{
    if (*s == 0)
        return;
    reverse(s + 1);
    printf("%c", *s);
}

void asterisk(int i)
{
    if (i > 1)
    {
        asterisk(i / 2);
        asterisk(i / 2);
    }
    printf("%d", i);
}

int add(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return n + add(n - 1);
}

double divid(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return (1 / (double)n) + divid(n - 1);
}

int main(int argc, char const *argv[])
{
    reverse("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    // asterisk(5);
    // int sum = add(5);
    // printf("%d\n", sum);

    // double dividSum = divid(5);
    // printf("%f\n", dividSum);
    return 0;
}
