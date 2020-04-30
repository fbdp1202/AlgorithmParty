// baekjoon 1003
#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	int T;
	cin >> T;
	int N0[41] = {0};
	int N1[41] = {0};
	N0[0] = 1;
	N1[1] = 1;
	N0[2] = 1;
	N1[2] = 1;
	for (int i = 3; i < 41; ++i)
	{
		N0[i] = N0[i-1] + N0[i-2];
		N1[i] = N1[i-1] + N1[i-2];
	}
	int tmp;
	for (int i = 0; i < T; ++i)
	{
		cin >> tmp;
		cout << N0[tmp] << ' ' << N1[tmp] <<endl;
	}
}
