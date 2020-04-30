// baekjoon 2077 yechan
#include <bits/stdc++.h>
using namespace std;

char num[9][5], shp[9][4];
map<vector<int>, double> p;

int main() {
	for (int i=0; i<9; i++)
		for (int j=3; j>=0; j--)
			scanf(" %c %c", &num[i][j], &shp[i][j]);

	num[0][4] = 'a';
	for (int i=1; i<9; i++)
		num[i][4] = num[i-1][4] + 1;

	p[{0,0,0,0,0,0,0,0,0}] = 1;

	queue<vector<int> > q;
	q.push({0,0,0,0,0,0,0,0,0});
	while (!q.empty()) {
		vector<int> now = q.front();
		q.pop();

		int cnt = 0;
		for (int i=0; i<9; i++)
			for (int j=i+1; j<9; j++)
				if (num[i][now[i]] == num[j][now[j]])
					cnt++;

		for (int i=0; i<9; i++) {
			for (int j=i+1; j<9; j++) {
				if (num[i][now[i]] == num[j][now[j]]) {
					vector<int> nx = now;
					nx[i]++;
					nx[j]++;
					if (!p.count(nx))
						q.push(nx);
					p[nx] += p[now] / cnt;
				}
			}
		}
	}

	printf("%.10lf", p[{4,4,4,4,4,4,4,4,4}]);
	return 0;
}