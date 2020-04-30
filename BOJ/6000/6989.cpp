// baekjoon 6989 yechan
#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int,int> P;


const int MAX_N=200;
const int MAX_V=2000000; // 최대 점수

int N, K, cur, s;
bool visited[MAX_V+3];
int arr[MAX_N];
int sum[MAX_N];
int tsum[MAX_N][MAX_N]; // tsum(s, e)
vector<P> ret;

int main() {
	scanf("%d", &N);
	for (int i=1; i<=N; i++) {
		scanf("%d", &arr[i]);
		sum[i] = sum[i-1] + arr[i];
		tsum[1][i] = tsum[1][i-1] + sum[i];
		for (int j=2; j<=i; j++)
			tsum[j][i] = tsum[j][i-1] + sum[i] - sum[j-1];
	}
	scanf("%d", &K);
	if (K > MAX_V) return !printf("%d\n", K);

	ret.push_back(P(0,0));
	visited[0]=true;
	for (int i=1; i<=N+1; i++) {
		for (int idx=0; idx<ret.size(); idx++) {
			cur = ret[idx].first;
			s = ret[idx].second;
			for (int j=s+1; j<i; j++) { // i th is wrong, s is wrong point
				int nx = cur + tsum[j][i-1];
				if (nx > MAX_V) continue;
				if (!visited[nx]) {
					visited[nx] = true;
					ret.push_back(P(nx, i));
				}
			}
		}
	}

	for (int k=K; ;k++) {
		if (k > MAX_V) return !printf("%d\n", k);
		if (!visited[k]) {
			return !printf("%d\n", k);
		}
	}
	return 0;
}