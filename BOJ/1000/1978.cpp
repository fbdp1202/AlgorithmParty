// baekjoon 1978
#include <iostream>
using namespace	std;

int main(void)
{
	int N, tmp;
	int count = 0;
	bool num[1001];
	cin >> N;
	num[1] = false;
	for (int i = 2; i < 1001; ++i)
		num[i] = true;
	for (int i = 2; i < 1001; ++i)
		if(num[i])
			for (int j = i*i; j < 1001; j+=i)
				num[j] = false;
	for (int i = 0; i < N; ++i) { cin >> tmp; count += (num[tmp]) ? 1 : 0; }
	cout << count;
}