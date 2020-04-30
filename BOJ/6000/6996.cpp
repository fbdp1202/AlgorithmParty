// baekjoon 6996 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

char A[101], B[101];
int T;
int cnt[26];

bool checkCnt() {
	for (int i=0; i<26; i++)
		if (cnt[i])
			return false;
	return true;
}

int main() {
	scanf("%d", &T);
	while (T--) {
		fill(cnt, cnt+26, 0);
		scanf("%s%s", A, B);
		for (int i=0; A[i]; i++)
			cnt[A[i]-'a']++;

		for (int i=0; B[i]; i++)
			cnt[B[i]-'a']--;

		if (checkCnt()) {
			printf("%s & %s are anagrams.\n", A, B);
		} else {
			printf("%s & %s are NOT anagrams.\n", A, B);
		}
	}
	return 0;
}