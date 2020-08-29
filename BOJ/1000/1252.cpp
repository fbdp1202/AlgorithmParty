#include <bits/stdc++.h>
using namespace std;

const int MAX_L=85;

char a[MAX_L], b[MAX_L], c[MAX_L], ret[MAX_L];

void sum(int pos, int carry, int aLen, int bLen) {
	if (pos >= aLen && pos >= bLen && carry == 0) {
		for (int i=0; i<pos; i++) {
			ret[pos-1-i] = c[i];
		}
		ret[pos]='\0';
		return;
	}

	int total = carry;
	if (pos < aLen) total += (a[aLen-1-pos]-'0');
	if (pos < bLen) total += (b[bLen-1-pos]-'0');
	c[pos] = (total % 2) + '0';
	sum(pos+1, total/2, aLen, bLen);
}

int main() {
	scanf("%s%s", a, b);
	sum(0, 0, strlen(a), strlen(b));
	int start = 0;
	while (ret[start]=='0') start++;
	if (start == strlen(ret)) puts("0");
	else  printf("%s\n",ret+start);

	return 0;
}