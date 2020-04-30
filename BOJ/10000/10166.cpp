// baekjoon 10166 yechan
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

bool visited[2002];

int gcd(int a, int b) {
	if (a % b == 0) return b;
	return gcd(b, a%b);
}

int main()
{
	int D1, D2;
	scanf("%d%d", &D1, &D2);
	int ret = 0;
	for (int i=D1; i<=D2; i++) {
		memset(visited, 0, sizeof(visited));
		ret += i;
		for (int j=D1; j<i; j++) {
			int g = gcd(i, j);
			for (int k=0; k<i; k+= i/g)
				if (!visited[k])
					visited[k]=true, ret--;
		}
	}
	printf("%d\n", ret);
	return 0;
}