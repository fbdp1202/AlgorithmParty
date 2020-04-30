// baekjoon 2467 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N=100001;

int N, arr[MAX_N];
	
int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++)
		scanf("%d", &arr[i]);

	int left = 0, right=N-1;
	int minV=2e9;
	pair<int,int> ans;
	int ret;
	while (left < right) {
		ret = arr[left] + arr[right];
		if (abs(ret) < minV) {
			ans.first = arr[left];
			ans.second = arr[right];
			minV = abs(ret);
		}

		if (ret < 0) {
			left++;
		} else {
			right--;
		}
	}

	printf("%d %d\n", ans.first, ans.second);

	return 0;
}