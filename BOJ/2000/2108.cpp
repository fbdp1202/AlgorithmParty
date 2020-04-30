// baekjoon 2108 yechan
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int BIAS=4000;

int N, data[8001];

int main()
{
	scanf("%d", &N);
	int x;
	int minValue=1e9, maxValue=-1e9;
	for (int i=0; i<N; i++)
	{
		scanf("%d", &x);
		minValue = min(minValue, x);
		maxValue = max(maxValue, x);
		data[BIAS+x]++;
	}

	float ans = 0;
	for (int i=0; i<8001; i++)
		ans += (i-BIAS)*data[i];
	printf("%.0f\n", ans/N);

	int pos = 0;
	for (int i=0; i<8001; i++) {
		pos += data[i];
		if (pos > N/2) {
			printf("%d\n", i-BIAS);
			break;
		}
	}

	int maxV=0;
	int maxIdx=-1, secIdx=-1;
	for (int i=0; i<8001; i++) {
		if (maxV < data[i]) {
			maxV = data[i];
			maxIdx = i;
			secIdx = -1;
		} else if (maxV == data[i]) {
			if (secIdx == -1) secIdx = i;
		}
	}
	printf("%d\n", (secIdx != -1 ? secIdx : maxIdx) - BIAS);
	printf("%d\n", maxValue - minValue);

	return 0;
}