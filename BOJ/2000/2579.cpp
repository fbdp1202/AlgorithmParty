// baekjoon 2579
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	int N;
	cin >> N;
	int tmp1, tmp2;
	int *score = new int[N];
	int *score_one = new int[N];
	int *score_two = new int[N];
	for (int i = 0; i < N; ++i){
		cin >> score[i];
		score_one[i]=0;
		score_two[i]=0;
	}
	if(N == 1) { cout << score[0]; return 0; }
	score_one[0] = score[0];
	score_one[1] = score[1];
	score_two[0] = score[0];
	score_two[1] = score[0]+score[1];
	for (int i = 2; i < N; ++i)
	{
		tmp1 = score[i]+score_two[i-2];
		tmp2 = score[i]+score_one[i-2];
		if(tmp1 < tmp2) score_one[i] = tmp2;
		else 			score_one[i] = tmp1;
		score_two[i] = score[i]+score_one[i-1];
	}
	if(score_one[N-1] < score_two[N-1]) cout << score_two[N-1];
	else 								cout << score_one[N-1];
}