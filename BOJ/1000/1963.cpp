// baekjoon 1963 yechan
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
const int pos[4] = {1000, 100, 10, 1};

int T, oldCode, newCode;
bool prime[10000], tmp[10000];

int main() {
	scanf("%d", &T);
	for (int i=2; i<10000; i++) {
		if (!prime[i]){
			for (int j=i*i; j<10000; j+=i)
				prime[j]=true;
		}
	}
	for (int i=0; i<1000; i++)
		prime[i]=true;

	while (T--) {
		for (int i=0; i<10000; i++)
			tmp[i] = prime[i];
		scanf("%d %d", &oldCode, &newCode);
		queue<int> q;
		q.push(oldCode);
		int depth = 0, result = -1;
		while (!q.empty()) {
			int sz = q.size();
			while(sz--) {
				int code = q.front(); q.pop();
				int cpos[4];
				if (code == newCode && result == -1) result=depth;
				cpos[0] = (code/1000)*1000;
				cpos[1] = ((code/100)%10)*100;
				cpos[2] = ((code/10)%10)*10;
				cpos[3] = code%10;
				for (int d=0; d<4; d++) {
					int cCode=code-cpos[d];
					for (int i=0; i<10; i++) {
						int nCode = cCode + i*pos[d];
						if (!tmp[nCode]) {
							tmp[nCode]=true;
							q.push(nCode);
						}
					}
				}
			}
			depth++;
		}
		if(result == -1) printf("Impossible\n");
		else printf("%d\n", result);
	}

	return 0;
}
