// baekjoon 8595 yechan
#include <cstdio>

using namespace std;

char str[5000001];

int main() {
	int N;
	scanf("%d%s", &N, str);
	long long ret = 0, num = 0;
	for (int i=0; i<N; i++) {
		if ('0' <= str[i] && str[i] <= '9')
			num = num*10 + str[i] - '0';
		else
			ret += num, num = 0;
	}
	ret += num;
	printf("%lld", ret);
	return 0;
}