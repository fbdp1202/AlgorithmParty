// baekjoon 10814 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N = 100001;

struct dict{
	int index, age;
	bool operator<(const dict &O) {
		if (age == O.age) return index < O.index;
		return age < O.age;
	}
};

int N;
char str[MAX_N][101];
dict data[MAX_N];

int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++) {
		scanf("%d %s", &data[i].age, str[i]);
		data[i].index = i;
	}

	sort(data, data+N);
	for (int i=0; i<N; i++)
		printf("%d %s\n", data[i].age, str[data[i].index]);

	return 0;
}