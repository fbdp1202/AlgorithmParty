#include <cstdio>
#include <cstring>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

const int MAX_N = 1001;
const int MAX_INF = 1e9;

int T, N, M;
int board[MAX_N][MAX_N];

int main()
{
	scanf("%d", &N);
	for (int i=0; i<N; i++)
		for (int j=0; j<N; j++)
			scanf("%d", &board[i][j]);

	int maxV = 0;
	for (int i=0; i<N; i++)
		maxV = max(maxV, board[0][i]);

	for (int i=1; i*i<=maxV; i++) {
		bool check=false;
		for (int j=1; j<N; j++) {
			if (board[0][j] % i != 0) {
				check=true;
				break;
			}
		}
		if (check) continue;
		// all divided
		check=false;
		for (int j=1; j<N; j++) {
			int divider = board[0][j] / i;
			if (!divider) {
				for (int k=0; k<N; k++) {
					if (board[j][k] != 0) {
						check=true;
						break;
					}
				}
			} else {
				for (int k=0; k<N; k++) {
					if (board[j][k] % divider != 0) {
						check=true;
						break;
					}
				}
			}
			if (check) break;
		}
		if (!check) {
			printf("%d ", i);
			for (int j=1; j<N; j++) {
				printf("%d ", board[0][j] / i);
			}
			puts("");
			return 0;
		}
	}
	printf("%d ", maxV);
	for (int j=1; j<N; j++) {
		printf("%d ", board[0][j] / maxV);
	}
	puts("");
	return 0;
}