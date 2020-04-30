// baekjoon 1525 yechan
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;

const int dz[4] = {3, -3, 1, -1};
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};


int main() {
	set<string> s;
	string str = "";
	string dst = "123456780";
	string tmp, curr_str;
	for (int i=0; i<9; i++) {
		cin >> tmp;
		str += tmp;
	}

	queue<string> q;
	q.push(str);
	s.insert(str);
	int depth=0;
	while (q.size()) {
		int qSize = q.size();
		while (qSize--) {
			curr_str = q.front(); q.pop();
			if (curr_str == dst) {
				break;
			}
			int z = 0;
			for (int i=0; i<9; i++) {
				if (curr_str[i] == '0') z=i;
			}

			for (int d=0; d<4; d++) {
				string next_str = curr_str;
				int nx = z%3 + dx[d];
				int ny = z/3 + dy[d];
				if (nx < 0 || nx >= 3 || ny < 0 || ny >= 3) continue;
				swap(next_str[z], next_str[z+dz[d]]);
				if (!s.count(next_str)) {
					s.insert(next_str);
					q.push(next_str);
				}
			}
		}
		if (curr_str == dst) {
			break;
		}
		depth++;
	}
	if (curr_str == dst) printf("%d\n", depth);
	else puts("-1");

	return 0;
}