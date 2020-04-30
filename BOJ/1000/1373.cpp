// baekjoon 1373 yechan
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

char data[1000001];

int main() {
	scanf("%s", data);
	int ld = strlen(data);
	int start = ld%3;
	int tmp = 0;
	for (int i=0; i<start; i++) {
		tmp <<= 1;
		tmp += (data[i]-'0');
	}
	if (start)
		printf("%d", tmp);
	for (int i=start; i<ld; i+=3) {
		printf("%d", ((data[i]-'0')<<2) + ((data[i+1]-'0')<<1) + (data[i+2]-'0') );
	}
	puts("");
	return 0;
}