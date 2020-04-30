#include <cstdio>
#include <algorithm>
#include <utility>
using namespace std;
const int DIV_NUM=2147483647; // 2<<31 -1
const int MAX_T=1000;
typedef pair<int, int> P;
P arr[MAX_T];
int T, ret[MAX_T];
long long tmp[3];

int main() {
	scanf("%d", &T);
	for (int i=0; i<T; i++) {
		arr[i].second=i;
		scanf("%d", &arr[i].first);
		if (arr[i].first == 0) ret[i]=0;
		if (arr[i].first== 1) ret[i]=1;
	}
	sort(arr, arr+T);
	tmp[1]=1;
	int cnt=0;
	for (int i=2; i<=arr[T-1].first; i++) {
		tmp[2] = tmp[1] + tmp[0];
		tmp[2] %= DIV_NUM;
		tmp[0]=tmp[1];
		tmp[1]=tmp[2];
		while (arr[cnt].first < i) cnt++;
		if (arr[cnt].first == i) {
			ret[arr[cnt].second]=(int)tmp[1];
		}
	}
	for (int i=0; i<T;i++) printf("%d\n", ret[i]);
	return 0;
}