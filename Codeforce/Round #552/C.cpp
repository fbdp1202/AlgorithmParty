#include <cstdio>
#include <algorithm>
using namespace std;

int arr[7] = {0, 1, 2, 0, 2, 1, 0};
int week[3] = {3, 2, 2};
long long food[3];

int main() {
	for (int i=0; i<3; i++)
		scanf("%lld", &food[i]);

	long long ret = 1e9;
	long long ans = 0;
	for (int i=0; i<3; i++) {
		ret = min(ret, food[i]/week[i]);
	}
	for (int i=0; i<3; i++) {
		food[i] -= week[i]*ret;
	}
	ans += ret*7;

	ret = 0;
	for (int start=0; start<7; start++) {
		long long tmp = 0;
		long long foodtmp[3];
		for (int i=0; i<3; i++) {
			foodtmp[i] = food[i];
		}
		while (!(foodtmp[0] < 0 || foodtmp[1] < 0 || foodtmp[2] < 0)) {
			foodtmp[arr[(tmp+start)%7]]--;
			tmp++;
		}
		ret = max(tmp, ret);
	}
	ans += ret-1;
	printf("%lld\n", ans);
	return 0;
}