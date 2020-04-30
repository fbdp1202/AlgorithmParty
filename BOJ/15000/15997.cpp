// baekjoon 15997 yechan
#include <iostream>
#include <utility>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

double ans[4];
string country[4];
double board[4][4][3]; // win 0, draw 1, lose 2
int score[4][4]; // win 0, draw 1, lose 2
pair<int,int> cost[4];
pair<int,int> table[6];
int choosen[6];

void decision() {
	double prec = 1.f;

	for (int i=0; i<6; i++)
		prec *= board[table[i].first][table[i].second][choosen[i]];

	for (int i=0; i<4; i++) {
		cost[i].first=0, cost[i].second=i;
		for (int j=0; j<4; j++) {
			if (i == j) continue;
			if (score[i][j] == 0) cost[i].first += 3;
			if (score[i][j] == 1) cost[i].first += 1;
		}
	}

	sort(cost, cost+4);

	if (cost[0].first == cost[3].first) // same 1,2,3,4 socre
	{
		for (int i=0; i<4; i++)
			ans[cost[i].second] += prec/2.f;

	} else if (cost[1].first == cost[3].first) // same 1,2,3 score
	{
		for (int i=1; i<4; i++)
			ans[cost[i].second] += prec/3.f*2.f;

	} else if (cost[0].first == cost[2].first) // same 2, 3, 4, Top 1
	{
		for (int i=0; i<3; i++)
			ans[cost[i].second] += prec/3.f;
		ans[cost[3].second] += prec;

	} else if (cost[1].first == cost[2].first) // same 2, 3 Top 1
	{
		for (int i=1; i<3; i++)
			ans[cost[i].second] += prec/2.f;
		ans[cost[3].second] += prec;
	}
	else // Top 1, 2
	{
		for (int i=2; i<4; i++)
			ans[cost[i].second] += prec;
	}
}

void dfs(int here) {
	if (here == 6) {
		decision();
		return;
	}
	int a = table[here].first;
	int b = table[here].second;
	if (board[a][b][0] > 0) { // win 0, draw 1, lose 2
		score[a][b] = 0;
		score[b][a] = 2;
		choosen[here] = 0;
		dfs(here + 1);
	}
	if (board[a][b][1] > 0) {
		score[a][b] = 1;
		score[b][a] = 1;
		choosen[here] = 1;
		dfs(here + 1);
	}
	if (board[a][b][2] > 0) {
		score[a][b] = 2;
		score[b][a] = 0;
		choosen[here] = 2;
		dfs(here + 1);
	}
}

int main()
{
	for (int i=0; i<4; i++)
		cin >> country[i];

	string A, B;
	for (int i=0; i<6; i++) {
		cin >> A >> B;
		int Apos, Bpos;
		for (int j=0; j<4; j++) {
			if (A == country[j]) Apos=j;
			if (B == country[j]) Bpos=j;
		}
		double W, D, L;
		cin >> W >> D >> L;
		board[Apos][Bpos][0] = board[Bpos][Apos][2] = W;
		board[Apos][Bpos][1] = board[Bpos][Apos][1] = D;
		board[Apos][Bpos][2] = board[Bpos][Apos][0] = L;
	}

	int tpos=0;
	for (int i=0; i<4; i++)
		for (int j=i+1; j<4; j++)
			table[tpos++] = {i, j};

	dfs(0);
	cout << fixed;
	cout.precision(100);
	for (int i=0; i<4; i++)
		cout << ans[i] << endl;

	return 0;
}