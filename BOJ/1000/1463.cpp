// baekjoon 1463
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int num;
	cin >> num;

	int minDP[1000001];

	minDP[1] = 0;

	for(int i=2; i<=num; i++){
		minDP[i] = minDP[i-1] + 1;
		if(i%3 == 0) minDP[i] = min(minDP[i],minDP[i/3]+1);
		if(i%2 == 0) minDP[i] = min(minDP[i],minDP[i/2]+1);
	}
	cout << minDP[num];
	return 0;
}
