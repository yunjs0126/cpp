#include "pch.h"
#include <iostream>
#include <ctime>

using namespace std;


int main()
{
	int answer[3];
	int i, j;
	int data[3];
	int count = 1;
	int strike, ball;

	srand(static_cast<unsigned int>(time(NULL)));
	for(i = 0 ; i < 3 ; i++)
	{
		answer[i] = (rand() % 9) + 1;
		for(j = 0 ; j < i ; j++)
			if (answer[i] == answer[j] && i != j)
				i--;
	}
	cout << answer[0] << answer[1] << answer[2] << endl;
	while (true)
	{
		cout << "[" << count << "회차 숫자야구" << "]" << endl;

		while (true)
		{
			for (i = 0; i < 3; i++)
			{
				cout << "1부터 9까지의 숫자를 입력하세요 : ";
				cin >> data[i];
			}
			if (data[0] < 1 || data[0] > 9 || data[1] < 1 || data[1] > 9 || data[2] < 1 || data[2] > 9)
			{
				cout << "숫자는 1부터 9사이만 입력이 가능합니다!"<< endl;
				continue;
			}

			else if((data[0] == data[1]) || (data[0] == data[2]) || (data[1] == data[2]))
			{
				cout << "중복된 숫자를 입력할 수 없습니다!" << endl;
				continue;
			}
				break;
		}

		strike = 0;
		ball = 0;

		for (i = 0 ; i < 3 ; i++)
			for (j = 0 ; j < 3 ; j++)
				if (answer[i] == data[j])
					if (i == j)
						strike++;
					else
						ball++;

		if (strike || ball)
			cout << "스트라이크 : " << strike << "볼 : " << ball << endl << endl;
		else
			cout << "아웃" << endl;
		if (strike == 3)
		{
			cout << "************ 정답!! ************" << endl;
			break;
		}
		else if (count == 9)
		{
			cout << "************ 패배! 정답 : ";
			cout << answer[0] << " | " << answer[1] << " | " << answer[2];
			cout << "************" << endl;
			break;
		}
		count++;
	}

	return 0;
}