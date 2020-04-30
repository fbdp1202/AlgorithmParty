// baekjoon 11944 yechan
#include <bits/stdc++.h>
using namespace std;

char str[5];
int N, M;

int main() {
	scanf("%s%d", &str, &M);
	int Nlen = (int)strlen(str);
	for (int i=0; str[i]; i++) {
		N *= 10;
		N += str[i]-'0';
	}
	
	M = min(M, Nlen*N);
	for (int i=0; i<M/Nlen; i++)
		printf("%s", str);
	for (int i=0; i<M%Nlen; i++)
		printf("%c", str[i]);
	puts("");
	return 0;
}