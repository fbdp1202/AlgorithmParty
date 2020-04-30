#include <string>
#include <vector>
#include <stack>

#include <iostream>

using namespace std;

string ret;

string ChangeString(int start, int end) {
	string s = "";
	for (int i=start; i<=end; i++) {
		if (ret[i] =='(') s += ')';
		else s += '(';
	}
	return s;
}

bool checkCorrect(int start, int end) {
	stack<int> s;
	for (int i=start; i<=end; i++) {
		if (ret[i] == '(') {
			s.push(1);
		}
		else {
			if (s.empty()) return false;
			else s.pop();
		}
	}
	return (s.empty()) ? true : false;
}

string DivideString(int start, int end) {
	if (start == end) return "";

	string s = "";
	int A=0, B=0;
	s += ret[start];
	if (ret[start] == '(') A++;
	else B++;

	for (int i=start+1; i<end; i++) {
		s += ret[i];
		if (ret[i] == '(') A++;
		else B++;
		if (A == B) {
			if (checkCorrect(start, i)) {
				s = s + DivideString(i+1, end);
			} else {
				s = '(' + DivideString(i+1, end) + ')' + ChangeString(start+1, i-1);
			}
			break;
		}
	}
	return s;
}

string solution(string p) {
    string answer = "";
    int len = p.length();
    ret = p;
    answer = DivideString(0, len);

    return answer;
}


int main()
{
	string S;
	cin >> S;
	cout << solution(S) << endl;
	return 0;
}