// baekjoon 2217
// 
#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main(void)
{
	int N;
	int Max_weight = 0;
	int tmp = 0;
	cin >> N;
	int *rope = new int[N]; 
	for (int i = 0; i < N; ++i) cin >> rope[i];
	sort(rope, rope+N, greater<int>());
	for (int i = 0; i < N; ++i)
	{
		tmp = rope[i]*(i+1);
		if(tmp > Max_weight){
			Max_weight = tmp;
		}
	}
	cout << Max_weight;
	return 0;
}