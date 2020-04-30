// baekjoon 1181 yechan
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<pair<int, string> > v;
	for (int i=0; i<N; i++) {
		string str;
		cin >> str;
		int len = str.size();
		v.push_back(pair<int, string>(len, str));
	}
	sort(v.begin(), v.end());
	cout << v[0].second << endl;
	for (int i=1; i<N; i++) {
		if(v[i-1].second.compare(v[i].second) !=0)
			cout << v[i].second << endl;
	}
}