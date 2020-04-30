#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_N=101;

int T, N, M, K;
int tile[MAX_N];

int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d%d", &N, &M, &K);

		for (int i=0; i<N; i++)
			scanf("%d", &tile[i]);

		int bag = M;
		bool check = true;
		for (int i=0; i<N-1; i++) {
			if (tile[i] + K < tile[i+1]) {
				bag -= tile[i+1] - tile[i] - K;
				if (bag < 0) {
					check = false;
					break;
				}
			} else {
				bag += tile[i] - max(tile[i+1]-K, 0);
			}
		}
		puts(check ? "YES":"NO");
	}
	return 0;
}