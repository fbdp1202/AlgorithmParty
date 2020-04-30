// baekjoon 15965 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N = 7368788;

int K, cnt;
bool isprime[MAX_N];

int main() {
	isprime[1]=true;
	for (int i=2; i*i<MAX_N; i++)
		if (!isprime[i])
			for (int j=i*i; j<MAX_N; j+=i)
				isprime[j]=true;

	scanf("%d", &K);

	for (int i=2; i<MAX_N; i++) {
		if (!isprime[i]) K--;
		if (K==0) {
			printf("%d\n", i);
			break;
		}
	}

	return 0;
}
