// baekjoon 2948 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int	monthday[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char buf[7][15] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

int month, day;

int main() {
	scanf("%d %d", &day, &month);
	int start=2;
	for (int i=0; i<month-1; i++) {
		start += monthday[i];
	}
	start+=day;
	printf("%s", buf[start%7]);
	return 0;
}