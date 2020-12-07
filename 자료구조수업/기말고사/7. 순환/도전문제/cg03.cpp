/*
문자열의 내용을 반대로 바꾸는 순환적인 함수 reverse()를 구현하라
*/

#include <iostream>
#include <string.h>

using namespace std;
 
void reverse(char *msg, int len)
{
        if (len == -1)
               return;
        else
        {
               cout << msg[len];
               reverse(msg, --len);
        }
}
 
int main(void)
{
        reverse("ABCDE", strlen("ABCDE")-1);
        return 0;
}