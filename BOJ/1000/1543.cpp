// baekjoon 1543 yechan
#include <iostream>
#include <string>
using namespace std;

string S, subS;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); //cin 실행속도 향상
	getline(cin, S); // 'fget 비슷'
	getline(cin, subS);

	if(S.size() < subS.size()) {
		cout << 0 << endl; return 0;
	}

	int result = 0;
	for (int i=0; i < S.size()-subS.size()+1; i++) {
		for (int j=0; j<subS.size(); j++) {
			if (S[i+j] != subS[j]) break;

			if(j==subS.size()-1){
				result++;
				i += subS.size()-1;
			}
		}
	}
	cout << result << endl;

	return 0;
}
