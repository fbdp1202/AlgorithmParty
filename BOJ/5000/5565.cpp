// baekjoon 5565 yechan
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int N, tmp;
	cin >> N;
	for (int i = 0; i < 9; ++i){
		cin >> tmp;
		N -= tmp;
	}
	cout << N;
}