// baekjoon 11365 yechan
#include <iostream>
#include <string>
using namespace std;

int main() {
	string code;
	while (1) {
		getline(cin, code);
		if (code == "END") return 0;
		for (int i=0; i<code.size() / 2; i++){
			char t;
			t = code[i];
			code[i] = code[code.size() - 1 - i];
			code[code.size() - 1 - i] = t;
		}
		for (int i=0; i < code.size(); i++)
			cout << code[i];
		cout << '\n';
	}
}
