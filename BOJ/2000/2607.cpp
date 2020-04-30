// baekjoon 2607 yechan
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

char str[11];
int base[26];
int N, i, j, ret, baselen, cmplen;

int main() {
	scanf("%d", &N);
	scanf("%s", str);
	for (i=0; str[i]; i++)
		base[str[i]-'A']++;
	baselen=i;

	for (i=1; i<N; i++) {
		int comp[26]={0};
		scanf("%s", str);
		for (j=0; str[j]; j++)
			comp[str[j]-'A']++;
		cmplen = j;
		int diff=0;
		for (j=0; j<26; j++)
			diff += abs(comp[j]-base[j]);

		if (baselen == cmplen && diff < 3) ret++;
		else if (diff < 2) ret++;
	}
	printf("%d\n", ret);
	return 0;
}