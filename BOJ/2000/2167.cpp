// baekjoon 2167 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int arr[301][301];
int N, M, K, i, j, x, y;

int main()
{
	scanf("%d %d", &N, &M);
	int tmp, result;
	scanf("%d", &tmp);
	arr[1][1] = tmp;
	for(int j=2; j<M+1; j++){
		scanf("%d", &tmp);
		arr[1][j] = tmp + arr[1][j-1];
	}

	for(int i=2; i<N+1; i++){
		scanf("%d", &tmp);
		arr[i][1] = tmp+arr[i-1][1];
		for(int j=2; j<M+1; j++){
			scanf("%d", &tmp);
			arr[i][j] = tmp+arr[i-1][j]+arr[i][j-1]-arr[i-1][j-1];
		}
	}

	scanf("%d", &K);
	for(int k=0; k<K; k++){
		scanf("%d %d %d %d", &i, &j, &x, &y);
		result = arr[x][y]-arr[x][j-1]-arr[i-1][y]+arr[i-1][j-1];
		printf("%d\n",result);
	}
	return 0;
}