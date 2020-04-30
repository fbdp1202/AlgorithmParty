// baekjoon 2966 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

const int pattern[3][12] ={
	{0, 1, 2, 0, 1, 2, 0, 1, 2, 0, 1, 2},
	{1, 0, 1, 2, 1, 0, 1, 2, 1, 0, 1, 2},
	{2, 2, 0, 0, 1, 1, 2, 2, 0, 0, 1, 1}
};

int ans[3];
char str[101];

void printAnswer(int here) {
	if (here == 0) puts("Adrian");
	else if (here == 1) puts("Bruno");
	else if (here == 2) puts("Goran");
}

int main(){
	int N;
	scanf("%d", &N);
	scanf("%s", str);
	for (int d=0; d<3; d++) {
		for (int i=0; i<N; i++) {
			if (pattern[d][i%12] == (str[i]-'A')) ans[d]++;
		}
	}

	int maxV = 0;
	for (int i=0; i<3; i++)
		maxV = max(maxV, ans[i]);

	printf("%d\n", maxV);
	for (int i=0; i<3; i++) {
		if (maxV == ans[i])
			printAnswer(i);
	}
	return 0;
}