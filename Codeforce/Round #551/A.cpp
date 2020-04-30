#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N=101;

int N, T;

int main() {
	scanf("%d%d", &N, &T);
	int value=1e9;
	int ret=-1;
	for (int i=1; i<=N; i++) {
		int s, d, tmp;
		scanf("%d%d", &s, &d);
		if (T <= s) tmp = s-T;
		else {
			tmp = d-(T-s)%d;
			if (tmp == d) tmp=0;
		}

		if (tmp == 0) return !printf("%d\n", i);
		else if(tmp < value) {
			value = tmp;
			ret = i;
		}
	}
	printf("%d\n", ret);
	return 0;
}