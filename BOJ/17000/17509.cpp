// baekjoon 17509 yechan
#include <bits/stdc++.h>
using namespace std;

int ret, cur;
pair<int,int> arr[11];

int main() {
	for (int i=0; i<11; i++) {
		int D, V;
		scanf("%d%d", &D, &V);
		arr[i].first = D;
		arr[i].second = V;
	}

	sort(arr, arr+11);
	for (int i=0; i<11; i++) {
		cur += arr[i].first;
		ret += cur + 20*arr[i].second;
	}
	printf("%d\n", ret);
	return 0;
}