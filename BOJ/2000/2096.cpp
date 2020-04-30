// baekjoon 2096 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX_N 100001

int N, arr[MAX_N][3], dpmin[3], dpmax[3];

int main()
{
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d %d %d", &arr[i][0], &arr[i][1], &arr[i][2]);

	for(int i=0; i<3; i++){
		dpmin[i]=arr[0][i];
		dpmax[i]=arr[0][i];
	}

	for(int i=1; i<N; i++){
		int tmpmin[3], tmpmax[3];
		tmpmin[0] = dpmin[0]; tmpmin[1] = dpmin[1]; tmpmin[2] = dpmin[2];
		tmpmax[0] = dpmax[0]; tmpmax[1] = dpmax[1]; tmpmax[2] = dpmax[2];
		dpmin[0] = arr[i][0]+min(tmpmin[0], tmpmin[1]);
		dpmin[1] = arr[i][1]+min(tmpmin[0], min(tmpmin[1], tmpmin[2]));
		dpmin[2] = arr[i][2]+min(tmpmin[1], tmpmin[2]);
		dpmax[0] = arr[i][0]+max(tmpmax[0], tmpmax[1]);
		dpmax[1] = arr[i][1]+max(tmpmax[0], max(tmpmax[1], tmpmax[2]));
		dpmax[2] = arr[i][2]+max(tmpmax[1], tmpmax[2]);
	}
	int maxnum = max(dpmax[0], max(dpmax[1],dpmax[2]));
	int minnum = min(dpmin[0], min(dpmin[1],dpmin[2]));
	printf("%d %d", maxnum, minnum);
}