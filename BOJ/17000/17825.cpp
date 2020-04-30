// baekjoon 17825 yechan
#include <bits/stdc++.h>
using namespace std;
using P=pair<int,int>;
const int MAX_N=44;
const int MAX_I=33;

P board[MAX_N][3];

void makeBoard() {
	board[0][0] = P(2,0);
	board[2][0] = P(4,0);
	board[4][0] = P(6,0);
	board[6][0] = P(8,0);
	board[8][0] = P(10,0);
	board[10][0] = P(12,0);

	board[12][0] = P(14,0);
	board[14][0] = P(16,0);
	board[16][0] = P(18,0);
	board[18][0] = P(20,0);
	board[20][0] = P(22,0);

	board[22][0] = P(24,0);
	board[24][0] = P(26,0);
	board[26][0] = P(28,0);
	board[28][0] = P(30,0);
	board[30][0] = P(32,0);

	board[30][0] = P(32,0);
	board[32][0] = P(34,0);
	board[34][0] = P(36,0);
	board[36][0] = P(38,0);
	board[38][0] = P(40,0);

	board[10][1] = P(13,1);
	board[13][1] = P(16,1);
	board[16][1] = P(19,1);
	board[19][1] = P(25,0);

	board[20][1] = P(22,1);
	board[22][1] = P(24,1);
	board[24][1] = P(25,0);

	board[30][1] = P(28,1);
	board[28][1] = P(27,1);
	board[27][1] = P(26,1);
	board[26][1] = P(25,0);

	board[25][0] = P(30,2);
	board[30][2] = P(35,2);
	board[35][2] = P(40,0);

	board[40][0] = P(0,1);
}

int idx[MAX_N][3];
P m[MAX_N];
bool isblue[MAX_N][3];

void setIdx() {
	idx[0][0]=0; m[0]=P(0,0);
	idx[2][0]=1; m[1]=P(2,0);
	idx[4][0]=2; m[2]=P(4,0);
	idx[6][0]=3; m[3]=P(6,0);
	idx[8][0]=4; m[4]=P(8,0);
	idx[10][0]=5; m[5]=P(10,0);
	idx[12][0]=6; m[6]=P(12,0);
	idx[14][0]=7; m[7]=P(14,0);
	idx[16][0]=8; m[8]=P(16,0);
	idx[18][0]=9; m[9]=P(18,0);
	idx[20][0]=10; m[10]=P(20,0);

	idx[13][1]=11; m[11]=P(13,1);
	idx[16][1]=12; m[12]=P(16,1);
	idx[19][1]=13; m[13]=P(19,1);

	idx[22][0]=14; m[14]=P(22,0);
	idx[24][0]=15; m[15]=P(24,0);
	idx[26][0]=16; m[16]=P(26,0);
	idx[28][0]=17; m[17]=P(28,0);
	idx[30][0]=18; m[18]=P(30,0);

	idx[22][1]=19; m[19]=P(22,1);
	idx[24][1]=20; m[20]=P(24,1);

	idx[28][1]=21; m[21]=P(28,1);
	idx[27][1]=22; m[22]=P(27,1);
	idx[26][1]=23; m[23]=P(26,1);

	idx[25][0]=24; m[24]=P(25,0);

	idx[30][2]=25; m[25]=P(30,2);
	idx[35][2]=26; m[26]=P(35,2);

	idx[32][0]=27; m[27]=P(32,0);
	idx[34][0]=28; m[28]=P(34,0);
	idx[36][0]=29; m[29]=P(36,0);
	idx[38][0]=30; m[30]=P(38,0);

	idx[40][0]=31; m[31]=P(40,0);

	idx[0][1]=32; m[32]=P(0,1);
	isblue[10][0]=isblue[20][0]=isblue[30][0]=true;
}

int seq[10];

int getIdx(P a) {
	return idx[a.first][a.second];
}

P move(P here, int cnt, int start) {
	if (cnt == 0) return here;
	if (getIdx(here) == 32) return here; // 마지막

	if (start && isblue[here.first][here.second]) return move(board[here.first][1], cnt-1, 0);
	else return move(board[here.first][here.second], cnt-1, 0);
}

bool match(int a, int b) {
	if (a == 0 || a == 32) return true;
	if (b == 0 || b == 32) return true;
	return (a != b);
}

bool check(int a, int b, int c, int d) {
	return match(a, b) && match(a, c) && match(a, d) && match(b, c) && match(b, d) && match(c, d);
}


int dfs(int here, int a, int b, int c, int d) {
	if (here == 10) return 0;

	int ret = 0;
	P naa = move(m[a], seq[here], 1);
	P nbb = move(m[b], seq[here], 1);
	P ncc = move(m[c], seq[here], 1);
	P ndd = move(m[d], seq[here], 1);
	int na = getIdx(naa);
	int nb = getIdx(nbb);
	int nc = getIdx(ncc);
	int nd = getIdx(ndd);
	if (check(na,b,c,d)) ret = max(ret, dfs(here+1, na, b, c, d)+naa.first);
	if (check(a,nb,c,d)) ret = max(ret, dfs(here+1, a, nb, c, d)+nbb.first);
	if (check(a,b,nc,d)) ret = max(ret, dfs(here+1, a, b, nc, d)+ncc.first);
	if (check(a,b,c,nd)) ret = max(ret, dfs(here+1, a, b, c, nd)+ndd.first);
	return ret;
}

int main() {
	makeBoard();
	setIdx();
	for (int i=0; i<10; i++)
		scanf("%d", &seq[i]);

	printf("%d\n", dfs(0, 0, 0, 0, 0));
	return 0;
}