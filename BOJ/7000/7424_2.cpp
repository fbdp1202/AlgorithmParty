// baekjoon 7424 yechan
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <functional>
#include <vector>
using namespace std;
#define MAXL 10
typedef pair<int,int> P;
int N, EQ[1<<10][MAXL];
vector<P> v;

int numlen(int a) {
	int len = 0;
	while (a) {
		a/=10;
		len++;
	}
	return max(len,1);
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
			v.push_back({curr,EQpos});
		}
		return;
	}
	int div = value/EQ[EQpos][pos];
	if (div < 10) backtracking(value-div*EQ[EQpos][pos], pos+1, EQpos, maxlen, curr*10+div);
	if (div < 11) backtracking(value-(div-1)*EQ[EQpos][pos], pos+1, EQpos, maxlen, curr*10+(div-1));
};

void fillEQ(int tmp, int pos, int except) {
	if (tmp == 0) return;
	if ((except>>pos) & 1) {
		fillEQ(tmp, pos+1, except);
		return;
	}
	EQ[except][pos] += tmp;
	fillEQ(tmp/10, pos+1, except);
}

void generEQ(int len) {
	long long value = 1;
	for (int i=len-1; i>=0; i--) {
		for (int j=0; j<(1<<len)-1; j++)
			EQ[j][i] = (int)value;
		value *=10;
	}
	value /=10;

	for (int i=0; i<(1<<len)-2; i++) {
		long long tmp = value;
		for (int j=0; j<len; j++) {
			if ((i>>j) & 1) tmp/=10;
		}
		fillEQ((int)tmp, 0, i);
	}

	for (int i=1; i<(1<<len)-2; i++) {
		for (int j=0; j<len; j++)
			printf("%d ", EQ[i][j]);
		puts("");
	}
}

int main() {
	// scanf("%d", &N);
	scanf(" %d", &N);
	int maxlen = numlen(N);
	generEQ(maxlen);
	for (int i=1; i<(1<<maxlen)-2; i++)
		backtracking(N, 0, i, maxlen, 0);
	memset(EQ, 0, sizeof(EQ));
	generEQ(maxlen-1);
	for (int i=1; i<(1<<(maxlen-1))-2; i++)
		backtracking(N, 0, i, maxlen-1, 0);

	sort(v.begin(), v.end());
	int cnt = 0;

	int prev = 0;
	for (int i=0; i<v.size(); i++) {
		if (prev == v[i].first) {
			cnt++;
			v[i].first = -1;
			continue;
		}
		prev = v[i].first;
		if (numlen(v[i].first) <= numlen(N-v[i].first)) {
			cnt++;
			v[i].first= -1;
		}
	}

	printf("%d\n", v.size()-cnt);
	prev = 0;
	for (int i=0; i<v.size(); i++) {
		if (v[i].first == -1) continue;
		cnt = 0;
		printf("%d + ", v[i].first);
		for (int j=0; j<numlen(v[i].first); j++)
			if ((v[i].second>>j) & 1) cnt++;

		for (int j=0; j<numlen(N-v[i].first)-cnt; j++)
			printf("0");
		printf("%d = %d\n", N-v[i].first, N);
		prev = v[i].first;
	}
	return 0;
}