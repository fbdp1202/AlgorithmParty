// baekjoon 1124 yechan
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

const int MAX_V=100001;

int N, A, B;
bool isprime[MAX_V];
vector<int> primes;

bool isuprime(int num) {
	int cnt = 0;
	for (int i=0; i<primes.size(); i++) {
		while (num % primes[i] == 0) num /= primes[i], cnt++;
		if (num == 1) break;
	}

	return !isprime[cnt];
}

int main() {
	isprime[0]=isprime[1]=true;
	for (int i=2; i*i<MAX_V; i++)
		if (!isprime[i])
			for (int j=i*i; j<MAX_V; j+=i)
				isprime[j]=true;

	for (int i=2; i<MAX_V; i++)
		if (!isprime[i]) primes.push_back(i);


	scanf("%d%d", &A, &B);
	int ret = 0;
	for (int i=A; i<=B; i++)
		if (isuprime(i)) ret++;

	printf("%d\n", ret);
	return 0;
}