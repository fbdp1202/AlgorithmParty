// baekjoon 2621 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int color[4];
int number[11];
pair<char, int> card[5];

int main() {
	for (int i=0; i<5; i++) {
		scanf(" %c %d", &card[i].first, &card[i].second);
		if (card[i].first == 'R') color[0]++;
		if (card[i].first == 'B') color[1]++;
		if (card[i].first == 'Y') color[2]++;
		if (card[i].first == 'G') color[3]++;
		number[card[i].second]++;
	}

	// 5Color and sequence
	int maxColor=0;
	int seq = 0;
	int ret = 0;
	int maxV = 0;
	int maxNum=0;
	int maxCntNum=0;
	int secondNum=0;
	int secondCntNum=0;
	for (int i=0; i<4; i++)
		maxColor = max(maxColor, color[i]);

	for (int j=1; j<10; j++) {
		if (number[j]) seq++, maxV = j;
		else seq=0;
		ret = max(ret, seq);
		if (maxNum <= number[j]) {
			secondNum = maxNum;
			secondCntNum = maxCntNum;
			maxNum = number[j];
			maxCntNum = j;
		}
		else if (secondNum <= number[j]) {
			secondNum = number[j];
			secondCntNum = j;
		}
	}
	if (maxColor == 5 && ret == 5) {
		return !printf("%d\n", 900+maxV);
	}
	if (maxNum == 4) {
		return !printf("%d\n", 800+maxCntNum);
	}
	if (maxNum == 3 && secondNum == 2) {
		return !printf("%d\n", 700+10*maxCntNum+secondCntNum);
	}
	if (maxColor == 5) {
		return !printf("%d\n", 600+maxV);
	}
	if (ret == 5) {
		return !printf("%d\n", 500+maxV);
	}
	if (maxNum == 3) {
		return !printf("%d\n", 400+maxCntNum);
	}
	if (maxNum == 2 && secondNum == 2) {
		return !printf("%d\n", 300+10*maxCntNum+secondCntNum);
	}
	if (maxNum == 2) {
		return !printf("%d\n", 200+maxCntNum);
	}
	printf("%d\n",100+maxV);

	return 0;
}