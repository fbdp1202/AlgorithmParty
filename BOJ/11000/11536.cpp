// baekjoon 11536 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX_N=21;
const int SIZE=13;

int N;
char str[MAX_N][SIZE];

bool check(int pos)
{
	for (int i=0; str[pos][i]; i++) {
		if (str[pos][i] == str[pos+1][i]) continue;
		return str[pos][i] < str[pos+1][i];
	}

	return true;
}

int main()
{
	scanf("%d", &N);
	for (int i=0; i<N; i++)
		scanf("%s", str[i]);

	bool dec = false, inc = false;
	for (int i=0; i<N-1; i++) {
		if (check(i)) inc=true;
		else dec=true;
	}

	if (dec && inc) puts("NEITHER");
	else if (dec) puts("DECREASING");
	else puts("INCREASING");
}