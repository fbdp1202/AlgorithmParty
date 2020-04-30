// baekjoon 11656 yechan
#include <iostream>
#include <string>
#include <cstring>
#include <set>
using namespace std;

string str;
set<string> s;

int main() {
	cin >> str;
	int slen = str.length();
	for (int i=0; i < slen; i++)
		s.insert(str.substr(i, slen));
	for (auto i : s) cout << i << '\n';
	return 0;
}