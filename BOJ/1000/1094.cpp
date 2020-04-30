// baekjoon 1094
#include <iostream>
using namespace std;

int main(void)
{
	int X, nstic;
	int arr[7] = {64, 32, 16, 8, 4, 2, 1};
	cin >> X;
	for (int i = 0; i < 7; ++i)
	{
		nstic += X/arr[i];
		X -= (X/arr[i])*arr[i];
	}
	cout << nstic;
}