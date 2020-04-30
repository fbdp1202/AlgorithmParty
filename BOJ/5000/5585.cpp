//baekjoon 5585

#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	int N;
	int arr[6] = {500, 100, 50, 10, 5, 1};
	cin >> N;
	N = 1000 - N;
	int result = 0;
	int tmp = 0;
	for (int i = 0; i < 6; ++i)
	{
		tmp = N/arr[i];
		result += tmp;
		N -= tmp*arr[i];
		if(N == 0)
			break;
	}
	cout << result;
}