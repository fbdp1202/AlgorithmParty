#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N=100001;

int N, room[10];
char str[MAX_N];

int main()
{
	scanf("%d", &N);
	scanf("%s", str);
	for (int i=0; i<N; i++) {
		if (str[i] == 'L') {
			for (int i=0; i<10; i++) {
				if (!room[i]) {
					room[i] = 1;
					break;
				}
			}
		}
		else if (str[i] == 'R') {
			for (int i=9; i>=0; i--) {
				if (!room[i]) {
					room[i] =1;
					break;
				}
			}
		} else {
			room[str[i]-'0']--;
		}
	}
	for (int i=0; i<10; i++) {
		printf("%d", room[i]);
	}
	puts("");
	return 0;
}