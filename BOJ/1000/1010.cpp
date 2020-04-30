// baekjoon 1010 yechan <다리놓기>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long LL;
LL bridge[31][31];

void fill_mCn(int m, int n){
	if(m > 30 || n > 30 || m < n) return;
	if(n == 0 || m == n) bridge[m][n] = 1;
	else bridge[m][n] = bridge[m-1][n-1] + bridge[m-1][n];
}

int main()
{
	int T, N, M; cin >> T;
	memset(&bridge[0][0], 0, sizeof(flags));
// 조합 mCn 이 결과이다.
	for (int i = 0; i < 31; ++i)
		for (int j = 0; j < 31; ++j)
			fill_mCn(i, j);

	for (int i = 0; i < T; ++i){
		cin >> N >> M;
		cout << bridge[M][N] << endl;
	}
}