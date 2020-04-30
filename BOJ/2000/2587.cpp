// baekjoon 2587 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int result, data[5];
int main() {
	for (int i=0; i<5; i++){
		scanf("%d", &data[i]);
		result += data[i];
	}
	sort(data, data+5);
	printf("%d\n%d\n", result/5, data[2]);
	return 0;
}