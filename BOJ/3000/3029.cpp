// baekjoon 3029 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	int x, y, z;
	scanf("%02d:%02d:%02d", &x, &y, &z);
	int t1 = x*3600 + y*60 + z;
	scanf("%02d:%02d:%02d", &x, &y, &z);
	int t2 = x*3600 + y*60 + z;

	if (t1 >= t2) t2 += 24*3600;
	int delay = t2 - t1;
	printf("%02d:%02d:%02d\n",delay/3600, (delay%3600)/60, delay%60);
	return 0;
}