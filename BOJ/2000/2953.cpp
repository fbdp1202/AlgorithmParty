// baekjoon 2953 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int maxValue=0, idx=0;;
	for (int i=1; i<=5; i++) {
		int tmp=0, data;
		for (int j=0; j<4; j++) {
			scanf("%d", &data);
			tmp+=data;
		}
		if (maxValue < tmp){
			maxValue = tmp;
			idx=i;
		}
	}
	printf("%d %d", idx, maxValue);
	return 0;
}