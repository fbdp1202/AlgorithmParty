///////////////////////////////////////
// ACM ICPC Asia Regional Seoul 2018 //
// Problem F_2.cpp                   //
// Write: Yechan(fbdp1202)           //
///////////////////////////////////////

#include <cstdio>
#include <algorithm>
#include <stack>
using namespace std;

char str[3000];
stack<char> cst;

int pos=0;
bool ip_flag = false;
bool e_flag  = false;
bool p_flag = false;

void checkParenthese() {
	int nalpha=0;
	bool oper=true;
	bool alpha=false;

	while (str[pos] != '\0') {
		if (e_flag) return;
		// printf("%c\n",str[pos]);
		if (str[pos] == ' ') {
			pos++;
			continue;
		}
		else if (str[pos] == '(') {
			p_flag=true;
			if (!oper) {
				// printf("( OPER ERROR\n");
				e_flag=true;
				return;
			}
			cst.push(str[pos]);
			pos++;
			nalpha++;
			oper=false;
			alpha=true;
			checkParenthese();
		}
		else if (str[pos] == ')') {
			if (cst.empty()) {
				e_flag=true;
				// printf("CLOSE ERROR\n");
				return;
			}
			else cst.pop();

			if (oper) {
				e_flag=true;
				// printf("OPER + ) \n");
				return;
			}

			if (nalpha != 2) {
				ip_flag=true;
			}
			pos++;
			return;
		}
		else if ('a' <=str[pos] && str[pos] <= 'z') {
			pos++;
			nalpha++;
			if (alpha) {
				// printf("ALPHABET DUPLLICATE\n");
				e_flag=true;
				return;
			}
			oper=false;
			alpha=true;
		}
		else if (str[pos] == '+' || str[pos] == '-' || str[pos] == '*' || str[pos] == '/' || str[pos] == '%') {
			pos++;
			if (oper) {
				e_flag=true;
				// printf("OPER DUPLLICATE\n");
				return;
			}
			oper=true;
			alpha=false;
		}
	}

	if (oper) {
		e_flag=true;
		// printf("HELLO\n");
		return;
	}

	if (p_flag) {
		if (nalpha != 2) ip_flag = true;
	} else {
		if (nalpha > 2) ip_flag = true;
	}
}

int main() {
	fgets(str, sizeof(str), stdin);
	checkParenthese();
	if (!cst.empty()) e_flag=true;

	if (e_flag) puts("error");
	else if (ip_flag) puts("improper");
	else puts("proper");
	return 0;
}