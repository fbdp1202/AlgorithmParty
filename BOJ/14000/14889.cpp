// baekjoon 14889 yechan
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
#define MAX_N 20

int N, result=987654321, board[MAX_N][MAX_N];
bool visited[MAX_N];

int diffTeamPerform() {
	int team1 = 0, team2 = 0;
	for (int i=0; i<N; i++){
		if (visited[i]){
			for (int j=0; j<N; j++)
				if (visited[j])
					team1 += board[i][j];
		} else {
			for (int j=0; j<N; j++)
				if (!visited[j])
					team2 += board[i][j];
		}
	}

	return abs(team1-team2);
}

void makeTeam(int num, int start) {
	if (num == N/2) {
		result = min(result, diffTeamPerform());
		return;
	}

	for (int i=start; i<N; i++) {
		if (!visited[i]) {
			visited[i]=true;
			makeTeam(num+1, i+1);
			visited[i]=false;
		}
	}
}

int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++)
		for (int j=0; j<N; j++)
			scanf("%d", &board[i][j]);
	makeTeam(0, 0);
	printf("%d",result);
	return 0;
} 