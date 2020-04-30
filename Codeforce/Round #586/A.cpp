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

int N;
char str[111111];
int alpha[27];

int main()
{
	scanf("%d", &N);
	scanf("%s", str);
	for (int i=0; str[i]; i++)
		alpha[str[i]-'a']++;

	int oneCnt = min(alpha['o'-'a'], min(alpha['n'-'a'], alpha['e'-'a']));
	alpha['o'-'a'] -= oneCnt;
	alpha['n'-'a'] -= oneCnt;
	alpha['e'-'a'] -= oneCnt;

	int zeroCnt = min(min(alpha['z'-'a'], alpha['e'-'a']), min(alpha['r'-'a'], alpha['o'-'a']));
	for (int i=0; i<oneCnt; i++)
		printf("1 ");
	for (int j=0; j<zeroCnt; j++)
		printf("0 ");
	return 0;
}