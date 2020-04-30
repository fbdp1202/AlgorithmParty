// baekjoon 10804 yechan
#include <bits/stdc++.h>
using namespace std;

int arr[20];

int main() {
	for (int i=0; i<20; i++) arr[i]=i+1;
	for (int i=0; i<10; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		a--, b--;
		for (int i=0; i<=(b-a)/2; i++)
			swap(arr[a+i], arr[b-i]);
	}

	for (int i=0; i<20; i++)
		printf("%d ", arr[i]);
	puts("");
	return 0;
}