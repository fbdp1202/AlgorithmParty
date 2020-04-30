// baekjoon 1912
#include <iostream>
using namespace std;
#define NINF -987654321 

int main(void)
{
	int N;
	cin >> N;
	int tmp;
	int result = 0;
	int max = NINF;
	for (int i = 0; i < N; ++i)
	{
		cin >> tmp;
		result += tmp;
		if(max < result) 	max = result;
		if(result < 0) 		result  = 0;
	}
	cout << max;
}