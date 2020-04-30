// baekjoon 2480
#include <cstdio>

using namespace std;
int tmp, num[7];

int main() {
	for (int i=0; i<3; i++){
		scanf("%d", &tmp);
		num[tmp]++;
	}
	int maxidx=0;
	int freq=0, freqIdx=0;
	for (int i=1; i<7; i++) {
		if (num[i]) maxidx=i;
		if (num[i]>1) freq=num[i], freqIdx=i;
	}
	int result=0;
	if (freq) {
		if (freq == 2) result=1000+100*freqIdx;
		if (freq == 3) result=10000+1000*freqIdx;
	}
	else {
		result=100*maxidx;
	}
	printf("%d",result);
	return 0;
}