/*
문제: https://www.acmicpc.net/problem/2798

Input: 첫째 줄에 카드의 개수 N(3 ≤ N ≤ 100)과 M(10 ≤ M ≤ 300,000)이 주어진다. 둘째 줄에는 카드에 쓰여 있는 수가 주어지며, 이 값은 100,000을 넘지 않는다.
합이 M을 넘지 않는 카드 3장을 찾을 수 있는 경우만 입력으로 주어진다.

Output: 첫째 줄에 M을 넘지 않으면서 M에 최대한 가까운 카드 3장의 합을 출력한다.
*/

#include <iostream>

using namespace std;

int calc(int length, int value, int card[])
{ //연산 함수
	int sum = 0;	//	합계를 위한 변수 선언
	int max = 0;	//	최고값 비교를 위한 변수 선언
	for (int i = 0; i < length; i++)	//	card의 첫번째 요소(1)
	{
		for (int j = i; j < length; j++)	//	card의 두번째 요소(2)
		{
			for (int k = j; k < length; k++)	//	card의 세번째 요소(3)
			{
				if (i == j || i == k || j == k)	//	같은 카드일 경우를 방지
				{
				}
				else
				{
					sum = card[i] + card[j] + card[k];	//	ex) 1. sum = card[0] + card[1] + card[2],  2. sum = card[0] + card[1] + card[3] ...
					if (sum <= value)
					{
						if (sum >= max)
						{
							max = sum;
						}
					}
				}
			}
		}
	}
	cout << max << endl;
	return max;
}

int main(int argc, char *argv[])
{
	int length;
	cin >> length; //	length : 카드의 개수
	if (length < 3 || length > 100)	//	문제에서 제시한 예외 처리
	{
		return 0;
	}
	int *card = new int[length]; //	카드의 개수만큼의 요소를 가진 배열 card 생성

	int value;
	cin >> value; //	value : 카드의 숫자의 합
	if (value < 10 && value > 300000)	//	문제에서 제시한 예외 처리
	{
		return 0;
	}
	for (int i = 0; i < length; i++)
	{
		cin >> card[i];
		if (card[i]> 100000){	//	문제에서 제시한 예외 처리
			return 0;
		}
	}
	calc(length, value, card);
	delete[] card;
	return 0;
}