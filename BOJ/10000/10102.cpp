// baekjoon 10102 yechan
#include <cstdio>
using namespace std;

int V, AV;
char buf[16];

int main() {
	scanf("%d", &V);
	scanf("%s", buf);
	for (int i=0; i<V; i++) {
		if (buf[i] == 'A') AV++;
	}
	if (AV == V-AV) puts("Tie");
	else if (AV > V-AV) puts("A");
	else puts("B");
	return 0;
}