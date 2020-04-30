// baekjoon 2875
#include <iostream>
#include <algorithm>
using namespace std;
int main(void)
{
	int N, M, K; // N: Gril, M: Man, K: remained
	int result;
	cin >> N >> M >> K;
	int tmp = N/2;
	if(tmp >= M) { K -= (tmp-M)*2 + N%2; result = M; }
	else 		 { K -= (M-tmp)   + N%2; result = tmp; }
	if(K > 0){
		result -= (K+2)/3;
	}
	cout << result;
}