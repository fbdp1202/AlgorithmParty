#include <bits/stdc++.h>
using namespace std;
const int MAX_N=1000001;

int N, S, cur, result;
char str[MAX_N];

int main() {
	scanf("%d%d", &N, &S);
	scanf("%s", str);

	bool flag = true;
	for (int i=0; i<S; i++) {
		if (str[i] == (flag ? 'I':'O')) {
			if (flag) {
				cur++;
				if (cur > N) cur--, result++;
			}
			flag = 1 ^ flag;
		} else {
			if (str[i] == 'I') flag = false, cur = 1;
			else flag = true, cur = 0;
		}
	}
	printf("%d\n", result);
	return 0;
}