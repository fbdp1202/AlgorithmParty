// baekjoon 11399
#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main(void)
{
	int N;
	int tmp = 0;
	int result = 0;
	cin >> N;
	int *p = new int[N];
	for (int i = 0; i < N; ++i)
		cin >> p[i];
	sort(p, p+N);
	for (int i = 0; i < N; ++i){
		tmp += p[i];
		result += tmp;
	}
	cout << result;
	return 0;
}