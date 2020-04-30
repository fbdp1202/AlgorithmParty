#include <cstdio>
#include <algorithm>
using namespace std;

bool visited[101];

int main()
{
	int N;
	scanf("%d", &N);
	int ret=0;
	for (int i=0; i<N; i++) {
		int x;
		scanf("%d", &x);
		if (visited[x]) ret++;
		visited[x] = true;
	}
	printf("%d\n", ret);
	return 0;
}