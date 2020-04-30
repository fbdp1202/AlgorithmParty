// baekjoon 14739 yechan
#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX_N 100000

int N, Q;

int data[MAX_N];
int d[MAX_N];
int bad[MAX_N];
int a_len[MAX_N];

int main()
{
	scanf("%d", &N);
	for(int i = 0; i < N; i++) scanf("%d", &data[i]);
	scanf("%d", &Q);
	int count = 0;
	int neg = (data[0] > data[1]);

	int dir = neg;
	int length = 1;

	for(int i = 1; i < N; i++)
	{
		if( data[i-1] > data[i] == dir) length++;
		else {
			a_len[count] = length;
			dir = data[i-1] > data[i];
			count++;
			length = 1;
		}
	}
	a_len[count] = length;
	count++;
	for(int i = 0; i < Q; i++)
	{
		int t_bad = 0;
		int MINRUN = 0;
		int curr_pos = 0;
		int compo = 0;
		int pre_bad = 0;
		int ap = 0;
		scanf("%d", &MINRUN);
		for(int j = 0; j < count; j++)
		{
			// printf("a_len[j] - pre_bad + ap: %d\n", a_len[j] - pre_bad + ap);
			curr_pos += a_len[j];
			if(a_len[j] - pre_bad + ap >= MINRUN){
				pre_bad = 0;
				compo++;
				ap = 0;
			}else if(a_len[j] - pre_bad + ap == 1){
				ap = ((neg+j+1)%2 == (data[curr_pos-1]  > data[curr_pos]));
				pre_bad = 0;
				if(!ap){
					pre_bad = MINRUN-1;
					t_bad += pre_bad;
				}
			}else if(a_len[j] - pre_bad + ap < MINRUN && a_len[j] - pre_bad + ap> 1){
				pre_bad = MINRUN-a_len[j]+pre_bad - ap;
				t_bad += pre_bad;
				compo++;
				ap = 0;
			}else{
				pre_bad -= a_len[j] + ap;
				ap = 0;
			}
			// printf("pre_bad: %d, t_bad: %d, ap: %d, combo: %d, a_len[j]: %d\n", pre_bad, t_bad, ap, compo, a_len[j]);
		}
		t_bad -= pre_bad;
		printf("%d %d\n", compo, t_bad);
	}
}