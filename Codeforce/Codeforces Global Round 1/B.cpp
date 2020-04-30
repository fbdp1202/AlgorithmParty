#include <cstdio>
#include <algorithm>
#include <queue>
#include <functional>
#include <utility>
using namespace std;
const int MAX_N = 100001;
typedef pair<int,int> P;

int n, m, k;
int data[MAX_N];
bool visited[MAX_N];

int main() {
	scanf("%d%d%d", &n, &m, &k);
	priority_queue<P, vector<P>, greater<P>> pq;
	for (int i=0; i<n; i++) {
		scanf("%d", &data[i]);
	}

	for (int i=0; i<n-1; i++) {
		pq.push({data[i+1]-data[i], i});
	}

	int ret = k;
	while (pq.size()) {
		if (n == k) break;
		int start = pq.top().second;
		ret += pq.top().first;
		pq.pop();
		if (!visited[start]) n--;
		else k++;
		if (!visited[start+1]) n--;
		else k++;
		visited[start]=visited[start+1]=true;
		k--;
	}
	printf("%d\n", ret);
	return 0;
}