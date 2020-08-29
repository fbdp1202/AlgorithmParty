#include <bits/stdc++.h>
using namespace std;

string s[2001];
string match[2001];
string pattern[3];

int curlen(int num) {
	int len = 0;
	while (num) {
		num /= 10;
		len++;
	}
	return len;
}

int main() {
	s[1] = "1";
	s[2] = "-2";
	for (int i=3; i<=2000; i++) {
		int prev_len = curlen(i)+1;
		s[i] = s[i-prev_len] + '-' + to_string(i);
	}
	pattern[0] = s[21];
	pattern[1] = s[22];
	pattern[2] = s[23];

	for (int i=1; i<=30; i++)
		cout << i << " : " << s[i].substr(0, min(i,19)) << endl;
	return 0;
}