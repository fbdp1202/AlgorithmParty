// baekjoon 6987 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int board[6][3], cnt;

int main() {
	for (int t=0; t<4; t++) {
		int arr[3]={0,};
		bool proper=true;
		for (int i=0; i<6; i++) {
			int sum = 0;
			for (int j=0; j<3; j++) {
				scanf("%d", &board[i][j]);
				arr[j]+=board[i][j];
				sum+=board[i][j];
			}
			if (sum != 5) {
				proper=false;
				break;
			}
		}
		if (arr[0] != arr[2]) proper=false;
		if (arr[1] % 2) proper=false;
		for (int i=0; i<6; i++) {
			cnt=board[i][0];
			for (int k=0; k<6; k++) {
				if (i==k) continue;
				if (board[k][2]) {
					cnt--;
					board[k][2]--;
				}
			}
			if (cnt) proper=false;
		}
		printf(proper ? "1 ":"0 ");
	}
	return 0;
}