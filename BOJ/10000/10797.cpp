// baekjoon 10797
#include <iostream>
using namespace std;
int main(void)
{
	int N;
	cin >> N;
	int tmp, result = 0;
	for (int i = 0; i < 5; ++i) { 
		cin >> tmp; result += (tmp == N) ? 1 : 0; 
	}
	cout << result;
}