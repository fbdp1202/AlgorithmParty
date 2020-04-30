// baekjoon 7424 yechan
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <functional>
#include <vector>
using namespace std;
#define MAXL 10

int N, EQ[MAXL][MAXL];
vector<int> v;

int numlen(int a) {
	int len = 0;
	while (a) {
		a/=10;
		len++;
	}
	return max(len,1);
}

int removeP(int X, int p) {
	int tmp = 1;
	for (int i=0; i<p-1; i++) {
		tmp *=10;
	}
	int top = (X/tmp)/10;
	int rst = top*tmp+(X%tmp);
	return rst;
}

bool checkValue(int X, int Y) {
	int xlen = numlen(X);
	for (int i=0; i<=xlen; i++)
		if (Y == removeP(X,i)) return true;
	return false;
}

void backtracking(
	int value, 
	int pos,
	int EQpos,
	int maxlen,
	int curr )
{
	if (pos == maxlen) {
		if (!value) {
			v.push_back(curr);
		}
		return;
	}
	int div = value/EQ[EQpos][pos];
	if (div < 10) backtracking(value-div*EQ[EQpos][pos], pos+1, EQpos, maxlen, curr*10+div);
	if (div < 11) backtracking(value-(div-1)*EQ[EQpos][pos], pos+1, EQpos, maxlen, curr*10+(div-1));
};

void fillEQ(int tmp, int pos, int except) {
	if (tmp == 0) return;
	if (except == pos) {
		fillEQ(tmp, pos+1, except);
		return;
	}
	EQ[except][pos] += tmp;
	fillEQ(tmp/10, pos+1, except);
}

void generEQ(int len) {
	long long value = 1;
	for (int i=len-1; i>=0; i--) {
		for (int j=0; j<len; j++)
			EQ[j][i] = (int)value;
		value *=10;
	}
	for (int i=0; i<len; i++)
		fillEQ((int)value/100, 0, i);
}

int main() {
	scanf("%d", &N);
	int maxlen = numlen(N);
	generEQ(maxlen);
	for (int i=0; i<maxlen; i++)
		backtracking(N, 0, i, maxlen, 0);

	memset(EQ, 0, sizeof(EQ));
	generEQ(maxlen-1);
	for (int i=0; i<maxlen-1; i++)
		backtracking(N, 0, i, maxlen-1, 0);

	sort(v.begin(), v.end());
	int cnt = 0;

	int prev = 0;
	for (int i=0; i<v.size(); i++) {
		if (!checkValue(v[i], N-v[i])) {
			cnt++;
			v[i] = -1;
			continue;
		}
		if (prev == v[i]) {
			cnt++;
			v[i] = -1;
			continue;
		}
		prev = v[i];
		if (numlen(v[i]) <= numlen(N-v[i])) {
			cnt++;
			v[i]= -1;
		}
	}

	printf("%d\n", v.size()-cnt);
	prev = 0;
	for (int i=0; i<v.size(); i++) {
		if (v[i] == -1) continue;
		printf("%d + ", v[i]);
		for (int j=0; j<numlen(v[i])-numlen(N-v[i])-1; j++)
			printf("0");
		printf("%d = %d\n", N-v[i], N);
		prev = v[i];
	}
	return 0;
}