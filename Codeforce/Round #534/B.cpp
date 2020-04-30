#include <cstdio>
#include <cstring>
using namespace std;
#define MAX_N 100001

int len;
bool visited[MAX_N];
char data[MAX_N];

int trial() {
	int i, j;
	int rst = 0;
	for (i=0; i<len; i++) {
		if (visited[i]) continue;
		j = i+1;
		while (visited[j]){ j++; }
		if (data[i] == data[j]) {
			visited[i] = visited[j] = true;
			rst++;
		}
	}
	if (rst) {
		rst += trial();
	}
	return rst;
}

int main() {
	scanf("%s", data);
	len = strlen(data);
	if (trial() % 2) puts("Yes");
	else puts("No");
	return 0;
}