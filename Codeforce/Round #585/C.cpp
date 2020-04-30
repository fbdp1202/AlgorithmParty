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

const int MAX_N = 200001;
const int MAX_INF = 1e9;

int N;
char A[MAX_N];
char B[MAX_N];
vector<int> a01;
vector<int> a10;

int main()
{
	scanf("%d", &N);
	scanf("%s", A);
	scanf("%s", B);

	int cnt = 0;

	for (int i=0; i<N; i++) {
		if (A[i] == B[i]) continue;
		cnt++;
		if (A[i] == 'a') {
			a01.push_back(i+1);
		} else {
			a10.push_back(i+1);
		}
	}

	if (cnt % 2) {
		return !printf("-1");
	}

	int ret = 0;
	ret += a01.size()/2;
	ret += a10.size()/2;
	if (a01.size() % 2) {
		ret += 2;
	}
	printf("%d\n", ret);
	for (int i=0; i<a01.size()/2; i++) {
		printf("%d %d\n", a01[i*2], a01[i*2+1]);
	}
	for (int i=0; i<a10.size()/2; i++) {
		printf("%d %d\n", a10[i*2], a10[i*2+1]);
	}
	if (a01.size() % 2) {
		printf("%d %d\n", a01[a01.size()-1], a01[a01.size()-1]);
		printf("%d %d\n", a01[a01.size()-1], a10[a10.size()-1]);
	}
	return 0;
}