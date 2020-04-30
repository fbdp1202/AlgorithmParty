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

int T, N, M;
char str[MAX_N];

void ans(int x) {
	if (x) printf("Bicarp\n");
	else printf("Monocarp\n");
}

int main()
{
	scanf("%d", &N);
	scanf("%s", str);

	int lnum = 0, rnum = 0;
	int lvalue = 0, rvalue = 0;
	for (int i=0; i<N/2; i++) {
		if (str[i] == '?') lnum++;
		else lvalue += (str[i] - '0');
	}
	for (int i=N/2; i<N; i++) {
		if (str[i] == '?') rnum++;
		else rvalue += (str[i] - '0');
	}

	if (lnum == rnum) {
		ans(lvalue == rvalue);
		return 0;
	} else if (rnum < lnum){
		swap(rnum, lnum);
		swap(rvalue, lvalue);
	}

	int turn = (rnum - lnum)/2;
	if (lvalue - rvalue == turn*9) {
		ans(1);
		return 0;
	}
	ans(0);
	return 0;
}