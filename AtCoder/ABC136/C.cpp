#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N=100001;

int N;
int hi[MAX_N];

int main()
{
	scanf("%d", &N);
	for (int i=0; i<N; i++) {
		scanf("%d", &hi[i]);
	}

	bool check = true;

	hi[0]--;
	for (int i=1; i<N; i++)
	{
		if (hi[i-1] == hi[i]) continue;
		else if (hi[i-1] < hi[i]) {
			hi[i]--;
		}
		else {
			check = false;
			break;
		}
	}
	puts(check ? "Yes" : "No");
	return 0;
}
