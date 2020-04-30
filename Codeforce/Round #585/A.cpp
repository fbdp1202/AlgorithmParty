#include <cstdio>
#include <cstring>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

const int MAX_N = 1000;
const int MAX_INF = 1e9;

int T, a, b, k1, k2;

int main()
{
	scanf("%d%d", &a, &b);
	scanf("%d%d", &k1, &k2);
	int D;
	scanf("%d", &D);
	if (!D) {
		printf("0 0\n");
		return 0;
	}
	if (k1 > k2) {
		swap(a, b);
		swap(k1, k2);
	}
	// k1 < k2
	int value = a*(k1-1) + b*(k2-1);
	printf("%d ", max(D-value,0));

	int maxV = 0;
	maxV = min(D/k1, a);
	D -= maxV*k1;
	if (D) {
		maxV += min(D/k2, b);
	}
	printf("%d\n", maxV);
	return 0;
}