#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int N, ret, x;
set<int> s;
vector<int> a;

int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++){
		scanf("%d", &x);
		if (!s.count(x)) ret++;
		s.insert(x);
	}
	if (ret > 3) return !printf("-1");
	for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
		a.push_back(*it);
	}
	sort(a.begin(), a.end());
	if (a.size() == 3) {
		if ((a[0]+a[2]) != a[1]*2 ) return !printf("-1");
		else printf("%d\n", a[1]-a[0]);
	} else if(a.size() == 2) {
		if ((a[1]-a[0])%2) printf("%d", a[1]-a[0]);
		else printf("%d", (a[1]-a[0])/2);
	} else {
		printf("0");
	}
	return 0;
}