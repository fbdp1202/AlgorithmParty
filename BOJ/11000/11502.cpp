// baekjoon 11502 yechan
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N=1001;

struct Answer{
	int a, b, c;
	Answer():a(-1),b(-1),c(-1){}
	Answer(int a, int b, int c):a(a),b(b),c(c){}
};

int T, N;

bool visited[MAX_N];
vector<int> primes;
Answer ans[MAX_N];

int main()
{
	for (int i=2; i*i<MAX_N; i++) {
		if (visited[i]) continue;
		for (int j=i*i; j<MAX_N; j+=i) {
			visited[j] = true;
		}
	}

	for (int i=2; i<MAX_N; i++)
		if (!visited[i]) 
			primes.push_back(i);

	for (int i=0; i<primes.size(); i++) 
		for (int j=i; j<primes.size(); j++)
			for (int k=j; k<primes.size(); k++) {
				int sum = primes[i]+primes[j]+primes[k];
				if (sum >= MAX_N) break;
				ans[sum] = Answer(primes[i],primes[j],primes[k]);
			}

	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &N);
		if (ans[N].a != -1) printf("%d %d %d\n", ans[N].a, ans[N].b, ans[N].c);
		else printf("0\n");
	}

	return 0;
}