// baekjoon 1744 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX_N 10000
typedef long long ll;

ll result, tmp, data[MAX_N];
int N;

int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++)
		scanf("%lld", &data[i]);
	sort(data, data+N);

	for (int i=0; i<N; i++) {
		if (data[i] > 0){
			result += tmp;
			break;
		}
		if (!tmp || i == N-1)
			tmp = data[i];
		else
			result += tmp*data[i], tmp = 0;
	}

	tmp = 0;
	for (int i=N-1; i>=0; i--) {
		if (data[i] <= 0) {
			result += tmp;
			break;
		}
		if (!tmp || i == 0)
			tmp = data[i];
		else
			result += tmp * data[i], tmp = 0;
	}
	printf("%lld\n", result);
}