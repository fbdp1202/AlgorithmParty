// baekjoon 2193
#include <iostream>
#include <algorithm>
using namespace std;
typedef unsigned long long int LL;

int main(void)
{
	int N;
	cin >> N;
	if(N==1){ cout << 1; return 0; }
	if(N==2){ cout << 1; return 0; }
	LL N0[91]={0};
	LL N1[91]={0};
	N0[3]=1; N1[3]=1;
	for (int i = 4; i < N+1; ++i)
	{
		N0[i]=N0[i-1]+N1[i-1];
		N1[i]=N0[i-1];
	}
	cout << N0[N]+N1[N];
}
