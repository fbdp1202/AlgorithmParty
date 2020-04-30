// baekjoon 2539 yechan
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX_R = 1000001;
const int MAX_N = 101;
const int MAX_P = 1001;

int R, C;
int N, P;
pair<int,int> point[MAX_P]; // (C, R)
bool visited[MAX_P];

bool isPossible(int mid)
{
	memset(visited, 0, sizeof(visited));
	int numPaper=0;
	for (int i=0; i<P; i++)
	{
		if (visited[i]) continue;
		if (point[i].second > mid) return false;

		int cur_x = point[i].first; // (cur_x, 1) ~ (cur_x + mid-1 , mid) // range
		visited[i]=true;

		numPaper++;
		if (numPaper > N) return false;

		for (int j=0; j<P; j++)
		{
			if (visited[j]) continue;
			int nx = point[j].first, ny = point[j].second;

			if (cur_x + mid <= nx || mid < ny) continue;
			else visited[j] =true;
		}
	}
	return true;
}


int main()
{
	scanf("%d%d", &R, &C);
	scanf("%d%d", &N, &P);
	for (int i=0; i<P; i++)
		scanf("%d%d", &point[i].second, &point[i].first);

	sort(point, point+P);
	int left = 1, right = MAX_R;
	int ret = MAX_R;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (isPossible(mid)) ret = min(ret, mid), right = mid-1;
		else left = mid+1;
	}
	printf("%d\n", ret);
	return 0;
}