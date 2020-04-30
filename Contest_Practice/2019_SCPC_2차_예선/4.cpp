#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX_N=50;
const int MAX_M=501;
typedef pair<int,int> P;

int T, N, M, num, num2;
char board[MAX_N][MAX_M];
bool visited[MAX_N][MAX_M];
bool visited2[MAX_N][MAX_M];
P boom[25001];
P boom2[25001];

int main() {
	scanf("%d", &T);
	for (int test=1; test<=T; test++) {
		memset(visited, 0, sizeof(visited));
		memset(visited2, 0, sizeof(visited2));
		printf("Case #%d\n", test);
		scanf("%d%d", &N, &M);
		for (int i=0; i<N; i++)
			scanf("%s", board[i]);

		num = 0;
		for (int i=0; i<N; i++) {
			for (int j=0; j<M; j++) {
				if (board[i][j] == '0') continue;
				if (visited[i][j]) continue;
				int bom_x, bom_y;
				bom_x = min(i, N-3);
				bom_y = min(j, M-3);
				boom[num].first = bom_x + 1;
				boom[num].second = bom_y + 1;
				num++;
				for (int bx=bom_x; bx<bom_x+3; bx++) {
					for (int by = bom_y; by<bom_y+3; by++) {
						visited[bx][by]=true;
					}
				}
			}
		}

		num2 = 0;
		for (int i=N-1; i>=0; i--) {
			for (int j=M-1; j>=0; j--) {
				if (board[i][j] == '0') continue;
				if (visited2[i][j]) continue;
				int bom_x, bom_y;
				bom_x = min(i, N-3);
				bom_y = min(j, M-3);
				boom2[num].first = bom_x + 1;
				boom2[num].second = bom_y + 1;
				num2++;
				for (int bx=bom_x; bx<bom_x+3; bx++) {
					for (int by = bom_y; by<bom_y+3; by++) {
						visited2[bx][by]=true;
					}
				}
			}
		}
		if (num <= num2) {
			printf("%d\n", num);
			for (int i=0; i<num; i++) {
				printf("%d %d\n", boom[i].first, boom[i].second);
			}
		} else {
			printf("%d\n", num2);
			for (int i=0; i<num2; i++) {
				printf("%d %d\n", boom2[i].first, boom2[i].second);
			}
		}
	}
	return 0;
}