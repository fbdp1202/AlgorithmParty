// baekjoon 2598 yechan
#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;

const int pos[6][6] = {
	{1,4,3,5,0,2}, // 가다 0 나마라바 1435
	{1,5,3,4,2,0}, // 다가 2 나바라마 1534
	{0,5,2,4,1,3}, // 나라 1 가바다마 0524
	{0,4,2,5,3,1}, // 라나 3 가마다바 0425
	{0,1,2,3,4,5}, // 마바 4 가나다라 0123
	{0,3,2,1,5,4}  // 바마 5 가라다나 0321
};

int convert(char c) {
	switch(c) {
		case 'Y': return 0;
		case 'R': return 1;
		case 'G': return 2;
		case 'B': return 3;
	}
	return -1;
}

char cboxes[4][7];
int boxes[4][6];
int shape[4];
int cycle[4];

set<pair<pair<int,int>,pair<int,int> > > s[3];
set<pair<pair<pair<int,int>, pair<int,int> >, int>> up;
bool acBox[4][6];

bool dfs(int count, int a1, int a2, int a3, int a4) {
	if (count == 4) {
		if ((a1 == a2) && (a2 == a3) && (a3 == a4) && (a4 == 15)) return true;
		return false;
	}
	bool ret=false;
	int n1,n2,n3,n4;
	for (int d=0; d<4; d++) {
		cycle[count]=d;
		n1 = a1, n2 = a2, n3 = a3, n4 = a4;
		if ( (a1 >> boxes[count][pos[shape[count]][(d+0)%4]]) & 1) continue;
		n1 |= (1 << boxes[count][pos[shape[count]][(d+0)%4]]);
		if ( (a2 >> boxes[count][pos[shape[count]][(d+1)%4]]) & 1) continue;
		n2 |= (1 << boxes[count][pos[shape[count]][(d+1)%4]]);
		if ( (a3 >> boxes[count][pos[shape[count]][(d+2)%4]]) & 1) continue;
		n3 |= (1 << boxes[count][pos[shape[count]][(d+2)%4]]);
		if ( (a4 >> boxes[count][pos[shape[count]][(d+3)%4]]) & 1) continue;
		n4 |= (1 << boxes[count][pos[shape[count]][(d+3)%4]]);
		ret = dfs(count+1, n1, n2, n3, n4);
		if (ret) return ret;
	}
	return ret;
}

void PreProcessing() {
	for (int c=0; c<3; c++) {
		for (int i=0; i<6; i++) {
			bool flag = false;
			for (int d=0; d<4; d++) {
				if (s[c].count({{boxes[c][pos[i][(d+0)%4]], boxes[c][pos[i][(d+1)%4]]},{boxes[c][pos[i][(d+2)%4]], boxes[c][pos[i][(d+3)%4]]}}))
					flag=true;
			}
			if (!flag) s[c].insert({{boxes[c][pos[i][0]], boxes[c][pos[i][1]]},{boxes[c][pos[i][2]], boxes[c][pos[i][3]]}});
			else acBox[c][i]=true;
		}
	}

	for (int i=0; i<6; i++) {
		bool flag = false;
		for (int d=0; d<4; d++) {
			if (up.count({{{boxes[3][pos[i][(d+0)%4]], boxes[3][pos[i][(d+1)%4]]},{boxes[3][pos[i][(d+2)%4]], boxes[3][pos[i][(d+3)%4]]}}, boxes[3][pos[i][4]]}))
				flag=true;
		}
		if (!flag) up.insert({{{boxes[3][pos[i][0]], boxes[3][pos[i][1]]},{boxes[3][pos[i][2]], boxes[3][pos[i][3]]}}, boxes[3][pos[i][4]]});
		else acBox[3][i]=true;
	}

}

int Tracking(){
	PreProcessing();

	int ret=0;
	for (int w=0; w<6; w++) { // 1st floor
		if (acBox[0][w]) continue;
		shape[0]=w;
		for (int i=0; i<6; i++) { // 2th floor
			if (acBox[1][i]) continue;
			shape[1]=i;
			for (int j=0; j<6; j++) { // 3th floor
				if (acBox[2][j]) continue;
				shape[2]=j;
				for (int k=0; k<6; k++) { // 4th floor
					if (acBox[3][k]) continue;
					shape[3]=k;
					if (dfs(0,0,0,0,0)) ret++;
				}
			}
		}
	}
	return ret;
}

int main() {
	for (int i=0; i<4; i++) {
		scanf("%s", cboxes[i]);
		for (int j=0; j<6; j++) {
			boxes[i][j] = convert(cboxes[i][j]);
		}
	}
	printf("%d\n", Tracking());
	return 0;
}