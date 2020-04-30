///////////////////////////////////////
// ACM ICPC Asia Regional Seoul 2018 //
// Problem F.cpp                     //
// Write: Yechan(fbdp1202)           //
///////////////////////////////////////

#include <cstdio>
#include <algorithm>
#include <stack>
using namespace std;
#define ERROR() { return !printf("error\n"); }

char str[1111];

int main() {
	fgets(str, sizeof(str), stdin);
	stack<char> st;
	stack<int> ast;
	stack<int> pst;

	bool proper = true;
	bool alpha = false;
	bool oper = false;

	int noper = 0;
	int nalpha = 0;
	int nparenth = 0;

	int cur_alpha = 0;
	int cur_parenth = 0;

	char prev = '\0';

	for (int i=0; str[i] != '\0'; i++) {
		// space 처리
		// printf("%d: %c\n", i, str[i]);
		if (str[i] == ' ' || str[i] == '\n') continue; 
		// '(' stack 처리
		else if (str[i] == '(') {
			st.push(str[i]);

			cur_alpha++;
			ast.push(cur_alpha);
			cur_alpha=0;

			cur_parenth++;
			pst.push(cur_parenth);
			cur_parenth=0;
		}
		// ')' 처리
		else if (str[i] == ')') {
			if (oper) ERROR();
			if (st.empty()) ERROR();
			st.pop();

			nparenth++;
			if (cur_alpha < 2) proper = false;
			cur_alpha = ast.top();
			ast.pop();

			if (cur_parenth >= 2) proper = false;
			cur_parenth = pst.top();
			pst.pop();
		}
		// alphabet 처리
		else if ('a' <= str[i] && str[i] <= 'z') {
			nalpha++;
			cur_alpha++;
			if (cur_alpha >= 3) proper = false;
			if (prev == ')') ERROR();
			if (alpha) ERROR();
			alpha = true;
			oper = false;
		}
		// operator 처리
		else {
			noper++;
			if (oper && !alpha) ERROR();
			if (prev == '(') ERROR();
			oper = true;
			alpha = false;
		}
		prev = str[i];
	}

	if (oper) ERROR();
	if (!st.empty()) ERROR();

	if (nalpha >= 2 && cur_alpha != 2) proper = false;
	if (nalpha >= 3 && (nalpha != noper+1 || nalpha != nparenth+2)) proper = false;
	if (cur_parenth >= 2) proper = false;

	if (proper) printf("proper\n");
	else printf("improper\n");
	return 0;
}