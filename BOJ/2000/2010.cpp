// baekjoon 2010
#include <iostream>
using namespace std;
int main()
{
	int N, tmp;
	cin >> N;
	int result = 1-N;
	for (int i = 0; i < N; ++i)
	{
		cin >> tmp; result += tmp;
	}
	cout << result;
}