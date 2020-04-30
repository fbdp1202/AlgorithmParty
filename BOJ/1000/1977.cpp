// baekjoon 1977
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
	int M, N;
	int rst = 0;
	cin >> M >> N;
	M = sqrt(M-1)+1; N = sqrt(N);
	if(M > N) { cout << -1; return 0; }
	for (int i = M; i < N+1; ++i) rst += i*i;
	cout << rst << M*M;
}