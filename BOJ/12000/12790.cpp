// baekjoon 12790 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
int T;
int SHP, SMP, SATK, SSD;
int MHP, MMP, MATK, MSD;

int main()
{
	scanf("%d", &T);
	for(int i=0; i<T; i++){
		scanf("%d %d %d %d %d %d %d %d",
			&SHP, &SMP, &SATK, &SSD,
			&MHP, &MMP, &MATK, &MSD);
		int THP = max(1, SHP+MHP);
		int TMP = max(1, SMP+MMP);
		int TATK = max(0, SATK+MATK);
		int TSD = SSD+MSD;
		int result = 1 * THP + 5 * TMP 
				   + 2 * TATK + 2 * TSD;
		printf("%d\n", result);
	}
}