// baekjoon 14582 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int ret[2], data[2][9];

int main()
{
	for (int d=0; d<2; d++)
		for (int i=0; i<9; i++)
			scanf("%d", &data[d][i]);

	bool check = false;
	for (int i=0; i<9; i++) {
		for (int d=0; d<2; d++) {
			ret[d] += data[d][i];
			if (ret[0] > ret[1]) check=true;
		}
	}
	puts(check ? "Yes" : "No");
	return 0;
}