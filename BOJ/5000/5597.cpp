// baekjoon 5597
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX_N 31
#define ATTEND 29
bool note[MAX_N];

int main()
{
	int tmp;
	for(int i=1; i<ATTEND; i++)
		scanf("%d", &tmp), note[tmp] = true;
	for(int i=1; i<MAX_N; i++)
		if(!note[i]) printf("%d\n", i);
}