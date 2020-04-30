// baekjoon 1837 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXK=1e6+1;

int k;
char p[101];
bool visited[MAXK];

bool isDivied(int x) {
	int ret=0;
	for (int i=0; p[i]; i++) ret=(ret*10+p[i]-'0')%x;
	return ret==0;
}

int main() {
	scanf("%s %d", p, &k);
	for (int i=2; i<k; i++) {
		if (!visited[i]) {
			if (isDivied(i)) return !printf("BAD %d\n", i);
			for (int j=i+i; j<k; j+=i) visited[j]=true;
		}
	}
	return !printf("GOOD\n");
}