#include "stdafx.h"
#include <cstdio>

//OR 연산자를 구현하는 함수 (퍼셉트론 학습 이용)
void perceptron()
{
    double theta = 0.2;         // theta, 즉 임계값을 0.2로 설정
    double a = 0.1;             // a = 학습률, 0.1로 설정
    double w1 = 0.3, w2 = -0.1; // w1과 w2는 초기 가중치이다.
    double w3 = 0.3;            // w3은 w1의 최종 가중치이다.
    double w4 = 0.1;            // w4는 w2의 최종 가중치이다.
    int x2[4] = {0, 1, 0, 1};   // x2의 입력 값
    int yd[4], y[4], x1[4] = {0, 0, 1, 1};  // x1의 입력값,  Yd의 목표 출력값과 Y의 값도 초기화
    int e, epoch = 1; //e = 오차 ,    epoch = 에폭
    int i;            //idnex

    for (i = 0; i < 4; i++)
    {
        yd[i] = x1[i] || x2[i];
    }
    printf("---------------------------------------------------\n");
    printf("퍼셉트론: OR\n");

    while (true)
    {
        if (yd[0] == y[0] && yd[1] == y[1] && yd[2] == y[2] && yd[3] == y[3])
            break;
        printf("---------------------------------------------------\n");
        printf("%d번째 에폭\n", epoch);
        printf("- - - - - - - - - - - - - - - - - - - - - - - - - -\n");
        epoch++;
        printf("    x1   x2   Yd    w1      w2     Y   e    w3   w4\n");
        printf("- - - - - - - - - - - - - - - - - - - - - - - - - -\n");

        for (i = 0; i < 4; i++)
        {
            if (x1[i] * w1 + x2[i] * w2 - theta + 1 >= 1)
            {
                y[i] = 1;
            }
            else
                y[i] = 0;
            e = yd[i] - y[i]; // 오차
            w3 = w1 + (a * x1[i] * e);
            w4 = w2 + (a * x2[i] * e);
            printf("    %d    %d    %d    %0.1f     %0.1f     %d   %d   %0.1f  %0.1f\n", x1[i], x2[i], yd[i], w1, w2, y[i], e, w3, w4);
            w1 = w3;
            w2 = w4;
        }
    }
}

int main()
{
    perceptron();
}