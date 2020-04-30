// baekjoon 9324 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int T, alpha[26];
char pv, c, str[100001];
int main() {
	scanf("%d", &T);
	while (T--) {
		fill(alpha, alpha+26, 0);
		bool flag=false;
		scanf("%s", str);
		for (int i=0; str[i]; i++) {
			c=str[i];
			if (flag) {
				flag=false;
				if (pv!=c) {
					flag=true; break;
				}
			} else {
				alpha[c-'A']++;
				if (alpha[c-'A']==3) {
					flag=true;
					alpha[c-'A']=0;
				}
			}
			pv=c;
		}
		puts(flag ? "FAKE" : "OK");
	}
	return 0;
}