// baekjoon ??
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;
const int MAX_N=1000001;

stack<char> st_front, st_end;

char str[MAX_N], com[MAX_N];

int main() {
	scanf("%s %s", str, com);
	int str_len= strlen(str);
	int com_len = strlen(com);
	for (int i=0; i<str_len ; i++) {
		st_end.push(str[str_len - i - 1]);
	}
	int com_idx, com_pos; 
	bool is_find_com = false;
	while (!st_end.empty()) {
		com_idx=0, com_pos=0;
		is_find_com = false;
		char now = st_end.top();
		st_end.pop();
		st_front.push(now);
		if (now != com[com_idx++]) continue;

		while (!st_end.empty() && com_idx < com_len) {
			now = st_end.top();
			st_end.pop();
			st_front.push(now);

			if (com_pos == 0 && com[0])
				com_pos = com_idx;
			if (now == com[com_idx]) com_idx++;
			else break;
		}

		if (com_idx == com_len) is_find_com=true;

		if (is_find_com) {
			for (int i=0; i<com_len; i++) st_front.pop();
			for (int i=0; !st_front.empty() && i < com_len-1; i++) {
				char now = st_front.top();
				st_front.pop();
				st_end.push(now);
			}
		}
		else {
			if (st_end.empty() || com_pos == 0 ) break;
			for (int i = 0; i < com_idx + 1 - com_pos; i++) {
				char now = st_front.top();
				st_front.pop();
				st_end.push(now);
			}
		}
	}

	while (!st_front.empty()) {
		char now = st_front.top();
		st_front.pop();
		st_end.push(now);
	}
	while (!st_end.empty()) {
		char now = st_end.top();
		st_end.pop();
		printf("%c", now);
	}
	return 0;
}