// baekjoon 6359 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX_N 101

int arr[MAX_N];
bool visit[MAX_N];

int main()
{
	int T, N;
	scanf("%d", &T);

	for(int i = 1; i <= 100; i++){
		int tmp = 0;
		for(int j = i; j<= 100; j += i){
			if(visit[j])
				visit[j] = false;
			else
				visit[j] = true;
		}
		for(int j=1; j<=i; j++)
			if(visit[j]) tmp += 1;
		arr[i]=tmp;
	}

	for(int i=0; i<T; i++)
		scanf("%d", &N), printf("%d\n", arr[N]);
	return 0;
}