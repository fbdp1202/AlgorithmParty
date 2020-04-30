#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX_N=200001;
typedef pair<int,int> P;

int N, K, num[MAX_N];
int L[MAX_N], R[MAX_N];
char ans[MAX_N];

priority_queue<P> PQ;

int main() {
	scanf("%d%d", &N, &K);
	for (int i=0; i<N; i++) {
		scanf("%d", &num[i]);
		L[i]=i-1;
		R[i]=i+1;
		PQ.push(P(num[i], i));
	}

	int flag=0;
	while (!PQ.empty()) {
		while (!PQ.empty() && ans[PQ.top().second]) PQ.pop();
		if (PQ.empty()) break;
		flag=(flag+1)%2;
		char c = (flag) ? '1' : '2';
		int cur_A = PQ.top().second;
		PQ.pop();
		ans[cur_A]= c;
		int rpos = R[cur_A];
		int lpos = L[cur_A];
		int rnum = K, lnum = K;
		while (rpos < N && rnum) {
			ans[rpos]=c;
			rpos = R[rpos];
			rnum--;
		}
		while (lpos >= 0 && lnum) {
			ans[lpos]=c;
			lpos = L[lpos];
			lnum--;
		}
		L[rpos]=lpos;
		R[lpos]=rpos;
	}
	printf("%s\n", ans);
	return 0;
}