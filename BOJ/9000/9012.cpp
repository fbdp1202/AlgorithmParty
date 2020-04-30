// baekjoon 9012 yechan
#include <cstdio>
#include <algorithm>
#include <stack>
using namespace std;

int T;
char buf[52];
int main(){
	stack<char> st;
	scanf("%d", &T);
	while (T--) {
		scanf("%s", buf);
		int i = 0, check = 1;
		while (buf[i]){
			if (buf[i] =='(')
				st.push(buf[i]);
			else {
				if (st.empty()) { check=0; break; }
				else st.pop();
			}
			i++;
		}
		if (!st.empty()) {
			check=0;
			while(!st.empty()) st.pop();
		}
		if(check) 	printf("YES\n");
		else 		printf("NO\n");
	}
	return 0;
}