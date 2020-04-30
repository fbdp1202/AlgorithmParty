// baekjoon 9660 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

ll N;
const bool arr[7] = {1, 0, 1, 1, 1, 1, 0};

int main()
{
	scanf("%lld", &N);
	N = (N-1)%7;
	puts(arr[N] ? "SK":"CY");
	return 0;
}