// baekjoon 2309 yechan
#include <bits/stdc++.h>
using namespace std;

int sum, arr[11];

int main() {
	for (int i=0; i<9; i++) {
		scanf("%d", &arr[i]);
		sum += arr[i];
	}
	sort(arr, arr+9);

	for (int i=0; i<9; i++) {
		for (int j=i+1; j<9; j++) {
			if (sum - arr[i] - arr[j] == 100) {
				for (int k=0; k<9; k++) {
					if (k == i || k == j) continue;
					printf("%d\n", arr[k]);
				}
				return 0;
			}
		}
	}

	return 0;
}