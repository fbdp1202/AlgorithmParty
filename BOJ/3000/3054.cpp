// baekjoon 3054 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
char str[16], ret[5][75];
int i,slen;

void pitter(int pos) {
	int base=pos*4;
	ret[0][base+2]=ret[4][base+2]=ret[2][base]=ret[2][base+4]='#';
	ret[1][base+1]=ret[1][base+3]=ret[3][base+1]=ret[3][base+3]='#';
	ret[2][base+2]=str[pos];
}

void wendy(int pos) {
	int base=pos*4;
	ret[0][base+2]=ret[4][base+2]=ret[2][base]=ret[2][base+4]='*';
	ret[1][base+1]=ret[1][base+3]=ret[3][base+1]=ret[3][base+3]='*';
	ret[2][base+2]=str[pos];
}

int main() {
	scanf("%s", str);
	while(str[i++]);
	slen=4*(i-1)+1;
	for (i=0; i<5; i++) fill(ret[i],ret[i]+slen,'.');
	for (i=0; str[i]; i++) if (i%3!=2) pitter(i);
	for (i=0; str[i]; i++) if (i%3==2) wendy(i);
	for (i=0; i<5; i++) printf("%s\n", ret[i]);
	return 0;
}