// baekjoon 9421 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N = 1000001;

int N;
bool isprime[MAX_N];
int visited[MAX_N];

bool dfs(int i, int index) {
	if (visited[i] == index) return true;
	if (visited[i] == 1) return false;
	if (visited[i] == 2) return true;
	visited[i]=index;
	int ret = 0;
	while (i) {
		ret += (i%10)*(i%10);
		i/=10;
	}
	return dfs(ret, index);
}

int main() {
	scanf("%d", &N);
	for (int i=2; i*i<=N; i++)
		if (!isprime[i])
			for (int j=i*i; j<=N; j+=i)
				isprime[j] = true;

	visited[1]=1;
	for (int i=2; i<=N; i++) {
		if (!isprime[i]) {
			if (dfs(i, 3)) {
				dfs(i, 2);
			} else {
				dfs(i, 1);
			}
		}
	}

	for (int i=2; i<=N; i++)
		if (!isprime[i] && visited[i] == 1)
			printf("%d\n", i);
	return 0;
}