// baekjoon 14647 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX_N 501

int n, m, data, tmp, total, board[MAX_N][MAX_N];

int main() {
	scanf("%d %d", &n, &m);
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			scanf("%d", &data);
			tmp=0;
			while (data > 0) {
				if (data%10 == 9) tmp++;
				data /= 10;
			}
			board[i][j] = tmp;
			total += tmp;
		}
	}

	int maxValue = 0;
	for (int i=0; i<n; i++) {
		int rowValue = 0;
		for (int j=0; j<m; j++) {
			rowValue+=board[i][j];
		}
		maxValue = max(maxValue, rowValue);
	}

	for (int j=0; j<m; j++) {
		int colValue = 0;
		for (int i=0; i<n; i++) {
			colValue+=board[i][j];
		}
		maxValue = max(maxValue, colValue);
	}
	printf("%d", total-maxValue);
	return 0;
}