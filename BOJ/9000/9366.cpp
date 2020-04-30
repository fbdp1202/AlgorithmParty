// baekjoon 9366 yechan
#include <bits/stdc++.h>
using namespace std;

int T;
int arr[3];

int main() {
	scanf("%d", &T);
	for (int t=1; t<=T; t++) {
		printf("Case #%d: ", t);
		for (int i=0; i<3; i++)
			scanf("%d", &arr[i]);
		sort(arr, arr+3);
		if (arr[0] + arr[1] <= arr[2]) puts("invalid!");
		else if (arr[0] == arr[2]) puts("equilateral");
		else if (arr[0] == arr[1] || arr[1] == arr[2]) puts("isosceles");
		else puts("scalene");
	}
	return 0;
}