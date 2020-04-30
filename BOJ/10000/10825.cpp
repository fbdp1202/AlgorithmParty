// baekjoon 10825 yechan
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX_N=100001;
struct student{
	char name[101];
	int a, b, c;
	bool operator<(const student& o) {
		if (a == o.a) {
			if (b == o.b) {
				if (c == o.c) {
					return strcmp(name, o.name) < 0;
				}
				return c > o.c;
			}
			return b < o.b;
		}
		return a > o.a;
	}
};

int N;
student st[MAX_N];

int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++)
		scanf("%s %d %d %d", st[i].name, &st[i].a, &st[i].b, &st[i].c);
	sort(st, st+N);

	for (int i=0; i<N; i++)
		printf("%s\n", st[i].name);
	return 0;
}
