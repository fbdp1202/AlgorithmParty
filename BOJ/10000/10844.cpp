// baekjoon 10844 yechan
#include <iostream>
#include <algorithm>
using namespace std;
#define DIV_NUM 1000000000
typedef long long unsigned int LL; 
int main()
{
	int N;
	LL rst = 0, value[10], next[10];
	value[0] = 0; fill(value + 1, value + 10, 1);
	cin >> N;
	for (int i = 1; i < N; ++i){
		next[0] = value[1];
		next[1] = value[0] + value[2];
		next[2] = value[1] + value[3];
		next[3] = value[2] + value[4];
		next[4] = value[3] + value[5];
		next[5] = value[4] + value[6];
		next[6] = value[5] + value[7];
		next[7] = value[6] + value[8];
		next[8] = value[7] + value[9];
		next[9] = value[8];
    	for (int j = 0; j < 10; ++j){ 
    		next[j] %= DIV_NUM;
    		value[j] = next[j];
    	}
	}
	for (int i = 0; i < 10; ++i) rst += value[i];
	cout << rst % DIV_NUM;
}