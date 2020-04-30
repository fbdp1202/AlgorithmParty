// baekjoon 9375 yechan
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

int T, N;

int main() {
	cin >> T;
	while (T--) {
		cin >> N;

		int num = 1;
		map<string,int> m;
		int costume[31] = {0};

		int ret = 1;
		for (int i=0; i<N; i++) {
			string a, b;
			cin >> a >> b;
			if (!m[b]) {
				m[b] = num++;
				costume[m[b]]++;
			} else {
				costume[m[b]]++;
			}
		}
		for (int i=1; i<num; i++)
			ret *= (costume[i]+1);
		printf("%d\n", ret-1);
	}
	return 0;
}