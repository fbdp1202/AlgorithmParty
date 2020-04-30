// baekjoon
#include <cstdio>
using namespace std;

char buf[111];

int i, flag;

int main() {
	scanf("%s", buf);
	flag = 1;
	while (buf[i]) {
		if (buf[i] == '-') flag = 1;
		else {
			if (flag) printf("%c", buf[i]);
			flag = 0;
		}
		i++;
	}
	return 0;
}