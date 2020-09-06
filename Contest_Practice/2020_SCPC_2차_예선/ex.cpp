// baekjoon 2621 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int color[4];
int number[11];
int maxColor;
int seq, ret;
int maxV;
int maxNum, maxCntNum;
int secondNum, secondCntNum;

int getIdx(char c) {
    switch(c) {
        case 'R': return 0;
        case 'B': return 1;
        case 'Y': return 2;
        case 'G': return 3;
    }
    return -1;
}

int main() {
    for (int i=0; i<5; i++) {
        char c; int x;
        scanf(" %c %d", &c, &x);
        color[getIdx(c)]++; number[x]++;
    }

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

    if (maxColor == 5 && ret == 5)      return !printf("%d\n", 900 + maxV);
    if (maxNum == 4)                    return !printf("%d\n", 800 + maxCntNum);
    if (maxNum == 3 && secondNum == 2)  return !printf("%d\n", 700 + 10 * maxCntNum + secondCntNum);
    if (maxColor == 5)                  return !printf("%d\n", 600 + maxV);
    if (ret == 5)                       return !printf("%d\n", 500 + maxV);
    if (maxNum == 3)                    return !printf("%d\n", 400 + maxCntNum);
    if (maxNum == 2 && secondNum == 2)  return !printf("%d\n", 300 + 10 * maxCntNum + secondCntNum);
    if (maxNum == 2)                    return !printf("%d\n", 200 + maxCntNum);
    printf("%d\n",100+maxV);

    return 0;
}