// baekjoon 2863 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

double arr[2][2];
double tmp[2][2];
double ret[4];

void tmpToarr()
{
	for (int i=0; i<2; i++)
		for (int j=0; j<2; j++)
			arr[i][j] = tmp[i][j];
}

void getRotate() {
	tmp[0][0] = arr[1][0];
	tmp[0][1] = arr[0][0];
	tmp[1][0] = arr[1][1];
	tmp[1][1] = arr[0][1];
}

inline double func() {
	return arr[0][0]/arr[1][0] + arr[0][1]/arr[1][1];
}

int main()
{
	for (int i=0; i<2; i++)
		for (int j=0; j<2; j++)
			scanf("%lf", &arr[i][j]);

	for (int d=0; d<4; d++) {
		ret[d] = func();
		getRotate();
		tmpToarr();
	}

	double ans = 0;
	for (int d=0; d<4; d++) {
		ans = max(ans, ret[d]);
	}

	for (int d=0; d<4; d++) {
		if (ans == ret[d]) {
			printf("%d\n", d);
			break;
		}
	}

	return 0;
}