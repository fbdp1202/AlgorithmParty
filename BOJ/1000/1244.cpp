// baekjoon 1244 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N=101;

int N, arr[MAX_N], K, cmd, x;

int main() {
	scanf("%d", &N);
	for (int i=1; i<=N; i++)
		scanf("%d", &arr[i]);
	scanf("%d", &K);

	for (int i=0; i<K; i++) {
		scanf("%d%d", &cmd, &x);
		if (cmd == 1) {
			for (int i=x; i<=N; i+=x) {
				arr[i] = (arr[i]+1)%2;
			}
		} else {
			for (int i=0; 1<=x-i && x+i<=N; i++) {
				if (arr[x-i] == arr[x+i]) {
					arr[x-i] = arr[x+i] = (arr[x-i]+1)%2;
				} else {
					break;
				}
			}
		}
	}

	for (int i=1; i<=N; i++) {
		printf("%d ", arr[i]);
		if (i%20 == 0)
			puts("");
	}

	return 0;
}