// baekjoon 11653 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N = 10000001;
int N;
bool isprime[MAX_N];

int main() {
	isprime[1] = true;
	for (int i=2; i*i < MAX_N; i++)
		if (!isprime[i])
			for (int j=i*i; j < MAX_N; j+=i)
				isprime[j]=true;

	scanf("%d",&N);

	for (int i=2; i <= N; i++) {
		if (!isprime[i]) {
			while (N && N % i == 0) {
				N/=i;
				printf("%d\n", i);
			}
		}
	}
	return 0;
}