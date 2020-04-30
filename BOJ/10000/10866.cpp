// baekjoon 10866 yechan
#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

int main() {
	int N, x;
	deque<int> dq;
	string str;

	cin >> N;
	for (int i=0; i<N; i++) {
		cin >> str;
		if (str == "push_front") {
			cin >> x;
			dq.push_front(x);
		}
		if (str == "push_back") {
			cin >> x;
			dq.push_back(x);
		}
		if (str == "pop_front") {
			if (dq.size()) {
				cout << dq.front() << endl;
				dq.pop_front();
			}
			else cout << -1  << endl;
		}
		if (str == "pop_back") {
			if (dq.size()) {
				cout << dq.back() << endl;
				dq.pop_back();
			}
			else cout << -1 << endl;
		}
		if (str == "size") {
			cout << dq.size() << endl;
		}
		if (str == "empty") {
			cout << !dq.size() << endl;
		}
		if (str == "front") {
			if (dq.size()) cout << dq.front() << endl;
			else cout << -1 << endl;
		}
		if (str == "back") {
			if (dq.size()) cout << dq.back() << endl;
			else cout << -1 << endl;
		}
	}
	return 0;
}