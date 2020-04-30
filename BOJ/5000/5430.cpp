// baekjoon 5430 yechan
#include <cstdio>
#include <algorithm>
#include <deque>
using namespace std;
const int MAX_N=100001;

int T, p, N;
int data[MAX_N];
char cmd[MAX_N];
int spos, epos, tmppos;
int dx;

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%s", cmd);
		scanf("%d", &N);
		char tmp;
		scanf(" %c", &tmp);
		for (int i=0; i<N; i++) {
			scanf("%d", &data[i]);
			if (i != N-1) scanf(" %c", &tmp);
		}
		scanf(" %c", &tmp);

		dx = 1;
		spos = 0; epos = N-1;
		bool check=false;
		for (int i=0; cmd[i]; i++) {
			if (cmd[i] == 'R') {
				tmppos = spos;
				spos = epos;
				epos = tmppos;
				dx *= -1;
			}
			else {
				if (!N) {
					check = true;
					break;
				}
				N--;
				spos += dx;
			}
		}

		if (check) {
			printf("error\n");
			continue;
		}
		printf("[");
		for (int i=0, pos=spos; i<N; i++, pos+=dx) {
			printf("%d", data[pos]);
			if (i != N-1) printf(",");
		}
		printf("]\n");
	}
}
