// baekjoon 1713 yechan
#include <cstdio>
#include <vector>
#include <utility>
#include <functional>
#include <algorithm>
using namespace std;
const int MAX_N=20;
const int MAX_NUM=101;

int N, K, x;
pair<pair<int, int>, int> poster[MAX_N]; // ((count, day), student Index)
vector<int> ans;

int main() {
	scanf("%d%d", &N, &K);
	for (int i=1; i<=K; i++) {
		scanf("%d", &x);
		sort(poster, poster+N, greater<pair<pair<int, int >, int> >());
		bool check=false;
		for (int j=0; j<N; j++) {
			if (poster[j].first.first == 0) {
				poster[j].first.first = 1; // count
				poster[j].first.second = i; // day
				poster[j].second = x; // index
				check = true;
				break;
			}
			if (poster[j].second == x) { // match index
				poster[j].first.first++; // count
				check = true;
				break;
			}
		}
		if (check) continue;
		poster[N-1].first.first = 1; // count
		poster[N-1].first.second = i; // day
		poster[N-1].second = x; // index
	}
	for (int i=0; i<N; i++) {
		if (poster[i].second) {
			ans.push_back(poster[i].second);
		}
	}
	sort(ans.begin(), ans.end());
	for (int i=0; i<ans.size(); i++)
		printf("%d ", ans[i]);
	puts("");
	return 0;
}