// baekjoon 2822 yechan
#include <cstdio>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;
#define NUM_P 9
#define NUM_S 5
typedef pair<int, int> P;

int result, tmp;
bool person[NUM_P];

int main()
{
	vector<P> score;
	for(int i=1; i<NUM_P; i++)
		scanf("%d", &tmp), score.push_back(P(tmp, i));

	sort(score.begin(), score.end(), greater<P>());

	for(int i=0; i<NUM_S; i++){
		result += score[i].first;
		person[score[i].second] = true;
	}
	printf("%d\n", result);

	for(int i=1; i<NUM_P; i++)
		if(person[i]) printf("%d ", i);
}