// baekjoon 2033 yechan
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char buf[11];

bool backtracking(int pos) {
	if (buf[pos] >= '5') return true;
	else if (buf[pos] == '4') return backtracking(pos+1);
	else return false;
}

int main() {
	scanf(" %s", buf);
	bool check = backtracking(1);
	if (check) {
		printf("%d", (buf[0]-'0')+1);
	}else {
		printf("%d", buf[0]-'0');
	}
	for (int i=1; buf[i]; i++) printf("0");
	return 0;
}