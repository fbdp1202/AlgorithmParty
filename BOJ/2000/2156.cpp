// baekjoon 2156
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
	int *score_zero = new int[N];
	int *score_one = new int[N];
	int *score_two = new int[N];
	for (int i = 0; i < N; ++i){ 
		cin >> score[i]; 	score_zero[i]=0;
		score_one[i]=0; 	score_two[i]=0; 	
	}
	if(N == 1) {	cout << score[0];	return 0; }
	score_zero[1]=score[0];
	score_one[0]=score[0];	score_one[1]=score[1];
	score_two[0]=score[0];	score_two[1]=score[0]+score[1];
	for (int i = 2; i < N; ++i){
		score_zero[i] = max(score_one[i-1], score_two[i-1]);
		score_one[i] = score[i] + max(max(score_two[i-2], score_zero[i-2]), max(score_one[i-2], score_zero[i-1]));
		score_two[i] = score[i] + score_one[i-1];
	}
	cout << max(score_zero[N-1], max(score_two[N-1], score_one[N-1]));
}