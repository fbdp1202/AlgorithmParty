// baekjoon 16431
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int Br, Bc;
int Dr, Dc;
int Jr, Jc;

int main()
{
	scanf("%d %d", &Br, &Bc);
	scanf("%d %d", &Dr, &Dc);
	scanf("%d %d", &Jr, &Jc);
	int Bdis = abs(Jr-Br)+abs(Jc-Bc)-abs(min(abs(Jr-Br),abs(Jc-Bc)));
	int Ddis = abs(Jr-Dr)+abs(Jc-Dc);
	if(Bdis == Ddis) printf("tie");
	if(Bdis < Ddis) printf("bessie");
	if(Bdis > Ddis) printf("daisy");
	return 0;
}