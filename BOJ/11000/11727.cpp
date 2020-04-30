// baekjoon 11727 yechan 2xn 타일링 2
#include<iostream>
#include<algorithm>
using namespace std;
#define MAX_N 1001
#define NUM_DIV 10007
int *tile_1x2 = new int[MAX_N];
int *tile_2x1 = new int[MAX_N];
int *tile_2x2 = new int[MAX_N];

int main()
{
	int n;
	cin >> n;
	tile_1x2[0] = 0; tile_2x1[0] = 0; tile_2x2[0] = 0;
	tile_1x2[1] = 0; tile_2x1[1] = 1; tile_2x2[1] = 0;
	tile_1x2[2] = 1; tile_2x1[2] = 1; tile_2x2[2] = 1;
	for (int i = 3; i < n+1; ++i)
	{
		tile_1x2[i] = (tile_1x2[i-2] + tile_2x1[i-2] + tile_2x2[i-2])%NUM_DIV;
		tile_2x1[i] = (tile_1x2[i-1] + tile_2x1[i-1] + tile_2x2[i-1])%NUM_DIV;
		tile_2x2[i] = tile_2x1[i-1]%NUM_DIV;
	}
	cout << (tile_1x2[n] + tile_2x1[n] + tile_2x2[n])%NUM_DIV;
}