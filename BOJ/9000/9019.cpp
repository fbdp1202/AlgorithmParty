// baekjoon 9019 yechan
#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

int T, A, B;
bool visited[10000];

int main() {
	cin >> T;
	while (T--) {
		fill(visited, visited + 10000, false);
		scanf("%d %d", &A, &B);

		queue<pair<int, string>> q;
		visited[A]=true;
		q.push({A, ""});

		int curr_num = 0;
		string curr_str;
		while(q.size()) {
			int qSize = q.size();
			while(qSize--) {
				curr_num = q.front().first; 
				curr_str = q.front().second;
				q.pop();
				if (curr_num == B) break;

				int d1 = curr_num/1000;
				int d2 = (curr_num/100)%10;
				int d3 = (curr_num/10)%10;
				int d4 = curr_num%10;

				int D_num = (curr_num*2)%10000;
				int S_num = (curr_num+9999)%10000;
				int L_num = d2*1000 + d3*100 + d4*10 + d1;
				int R_num = d4*1000 + d1*100 + d2*10 + d3;

				// D
				if (!visited[D_num]) {
					// string D_str = curr_str + "D";
					visited[D_num] = true;
					q.push({D_num, curr_str + "D"});
				}
				// S
				if (!visited[S_num]) {
					// string S_str = curr_str + "S";
					visited[S_num] = true;
					q.push({S_num, curr_str + "S"});
				}
				// L
				if (!visited[L_num]) {
					visited[L_num] = true;
					q.push({L_num, curr_str + "L"});
				}
				// R
				if (!visited[R_num]) {
					visited[R_num] = true;
					q.push({R_num, curr_str + "R"});
				}
			}
			if (curr_num == B) break;
		}
		cout << curr_str << endl;
	}
	return 0;
}