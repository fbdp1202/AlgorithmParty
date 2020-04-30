// baekjoon 10820
#include <cstdio>
#include <algorithm>
using namespace std;

int N;
char str[111];
int main() {
	while (fgets(str, sizeof(str), stdin)) {
		int data[4] = {0};
		for (int i=0; str[i]; i++) {
			if ('a' <= str[i] && str[i] <= 'z') data[0]++;
			if ('A' <= str[i] && str[i] <= 'Z') data[1]++;
			if ('0' <= str[i] && str[i] <= '9') data[2]++;
			if (str[i] == ' ') data[3]++;
		}
		printf("%d %d %d %d\n", data[0], data[1], data[2], data[3]);
	}
	return 0;
}