// baekjoon 4963
#include <iostream>
#include <algorithm>
using namespace std;

#define FOR(i,n) for(int i = 0; i < n; i++)

bool arr[50][50] = {0};

void erase_island(int x, int y, int w, int h)
{
	if(x < w && y < h && x > -1 && y > -1 && arr[y][x]){
		arr[y][x] = 0; // erase
		erase_island(x-1, 	y-1, 	w, 	h);
		erase_island(x-1, 	y, 		w, 	h);
		erase_island(x-1,	y+1, 	w, 	h);
		erase_island(x, 	y-1, 	w, 	h);
		erase_island(x, 	y, 		w, 	h);
		erase_island(x, 	y+1, 	w, 	h);
		erase_island(x+1, 	y-1, 	w, 	h);
		erase_island(x+1, 	y, 		w, 	h);
		erase_island(x+1, 	y+1, 	w, 	h);
	}
}

int main(void)
{
	int w, h;
	int result;
	while(1){
		result = 0;
		cin >> w >> h;
		if(w == 0 && h == 0)
			break;
		FOR(j, h)
			FOR(i, w)
				cin >> arr[j][i];

		FOR(j, h){
			FOR(i, w){
				if(arr[j][i]){
					result++;
					erase_island(i, j, w, h);
				}
			}
		}
		cout << result << endl;
	}
	return 0;
}