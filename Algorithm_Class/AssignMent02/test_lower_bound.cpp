#include <cstdio>
#include <algorithm>
using namespace std;

int N;
int arr[100];

int main() {
	for (int i=0; i<100; i++)
		arr[i]=i/10;
	for (int i=0; i<100; i++) {
		int cnt = lower_bound(arr, arr+100, i/10)-arr;
		printf("%d: %d\n", i, cnt);
	}
	return 0;
}