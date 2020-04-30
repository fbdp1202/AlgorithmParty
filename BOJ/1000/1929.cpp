// baekjoon 1929 yechan
#include <cstdio>
#include <algorithm>
#include <time.h>
using namespace std;
#define MAX_N 1000001
int M, N, rst, minb;
bool prime[1000001];

double what_time_is_it_now() {
	struct timespec now;
	clock_gettime(CLOCK_REALTIME, &now);
	return now.tv_sec + now.tv_nsec*1e-9;
}

int main() {
	srand(time(NULL));
	double start, end;
	int cnt = 0;
	start = what_time_is_it_now();
	scanf("%d %d", &M, &N);
	prime[1] = true;
	for(int i=2; i < 1000; i++) {
		if(prime[i]) continue;
		for(int j=i*i; j<1000001; j+=i) {
			prime[j]=true;
		}
	}
	for(int i=M; i<=N; i++) {
		if(!prime[i]) {
			cnt++;
			// printf("%d\n", i);
		}
	}
	end = what_time_is_it_now();
	printf("TIME: %f seconds\n", end-start);
	return 0;
}