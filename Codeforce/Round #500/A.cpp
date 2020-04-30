#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N=65001;
int N;
char s[MAX_N];

int main() {
	scanf("%d", &N);
	scanf("%s", s);
	long long ret = 0;
	for (int i=0; s[i]; i++)
		if ( (s[i]-'0')%2 == 0)
			ret += i+1;
	printf("%lld\n", ret);
	return 0;
}