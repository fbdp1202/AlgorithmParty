// Ries Blog
#include <cstdio>
#include <algorithm>
using namespace std;

int N, H[100000];

// 분할 정복으로 히스토그램 [s, e) 문제를 푸는 함수
int histogram(int s, int e) {
	if (s == e) return 0;
	if (s+1 == e) return H[s];

	int mid = (s+e)/2;
	int result = max(histogram(s, mid), histogram(mid, e));

	// 양쪽 구간에 걸쳐 있는 답을 O(e-s)에 찾음
	int w = 1, h = H[mid], l = mid, r = mid;
	while (r-l+1 < e-s) {
		int p = l>s ? min(h, H[l-1]) : -1;
		int q = r<e-1 ? min(h, H[r+1]) : -1;

		if (p >= q) {
			h = p;
			l--;
		} 
		else {
			h = q;
			r++;
		}
		// 최댓값 갱신
		result = max(result, ++w*h);
	}
	return result;
}

int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++)
		scanf("%d", H+i);
	printf("%d\n", histogram(0, N));
}