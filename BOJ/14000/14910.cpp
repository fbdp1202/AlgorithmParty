// baekjoon 14910
#include <cstdio>
using namespace std;

int tmp, prev=-1000001, result, flag;
int main() {
	while(~scanf("%d", &tmp)){
		if (tmp < prev) {
			flag=1;
			break;
		}
		prev = tmp;
	}
	if (flag) 	printf("Bad\n");
	else 		printf("Good\n");
	return 0;
}