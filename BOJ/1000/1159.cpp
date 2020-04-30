// baekjoon 1159 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int N, alpha[26];
char buf[31];

int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++) {
		scanf("%s", buf);
		alpha[buf[0]-'a']++;
	}

	int flag = 0;
	for (int i=0; i<26; i++) {
		if(alpha[i]>=5) {
			flag=1;
			printf("%c", i+'a');
		}
	}
	if (!flag) printf("PREDAJA");
	return 0;
}