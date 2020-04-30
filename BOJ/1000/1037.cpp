// baekjoon 1037
#include <iostream>
#include <algorithm>
using namespace std;
int main(void)
{
	int N;
	cin >> N;
	int *tmp = new int[N];
	for (int i = 0; i < N; ++i)
		cin >> tmp[i];
	sort(tmp, tmp+N);
	cout << tmp[0]*tmp[N-1];
}