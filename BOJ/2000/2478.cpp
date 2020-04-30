// baekjoon 2478 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N=501;

int N, arr[MAX_N], s, e;
int tmp[MAX_N];
bool visited[MAX_N];

int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++)
		scanf("%d", &arr[i]);

	for (int i=0; i<N; i++) {
		if (arr[(N+i-1)%N]-arr[i] == 1)
			visited[(N+i-1)%N] = visited[i] = true;
		if (arr[(N+i-1)%N] == 1 && arr[i] == N)
			visited[(N+i-1)%N] = visited[i] = true;
	}
	s=e=-1;
	for (int i=0; i<N; i++) {
		if (!visited[(N+i-1)%N] && visited[i]) s = i;
		if (visited[i] && !visited[(i+1)%N]) e = i;
	}
	if (s == -1) s=0,e=N-1;
	int sh=0;
	if (s > e) {
		sh = (N-s);
		for (int i=0; i<N; i++) tmp[i] = arr[i];
		for (int i=0; i<N; i++) arr[i] = tmp[(N+i-sh)%N];
		s=(s+sh)%N, e=(e+sh)%N;
	}

	reverse(arr+s, arr+e+1);
	for (int i=0; i<N; i++) {
		if (arr[i] == 1) {
			printf("%d\n", N-i);
			break;
		}
	}
	printf("%d %d\n", s+1, e+1);
	printf("%d\n", (sh)? sh:N);
	return 0;
}