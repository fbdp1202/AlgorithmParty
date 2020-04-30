// baekjoon 7785 yechan
#include <iostream>
#include <string>
#include <set>
#include <functional>
#include <algorithm>
using namespace std;

int N;
char cmd[6];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	set<string> s;
	string name;
	cin >> N;
	for (int i=0; i<N; i++) {
		cin >> name >> cmd;
		if (cmd[0] == 'l') {
			s.erase(name);
		} else {
			s.insert(name);
		}
	}
	for (set<string>::reverse_iterator IterPos=s.rbegin(); IterPos != s.rend(); ++IterPos) {
		cout << *IterPos << '\n';
	}
	return 0;
}