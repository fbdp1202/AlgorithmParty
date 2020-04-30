// baekjoon 1874 yechan
#include <cstdio>
#include <algorithm>
#include <stack>
using namespace std;
#define MAX_N 100001

char buf[MAX_N*2];
int N, dataidx, bufidx, data[MAX_N];
stack<int> st;

int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++)
		scanf("%d", &data[i]);
	int S=1;
	while (S <= N) {
		while (!st.empty()) {
			if( st.top() == data[dataidx]) {
				st.pop();
				dataidx++;
				buf[bufidx++]='-';
			}
			else
				break;
		}
		st.push(S++);
		buf[bufidx++]='+';
	}
	if (dataidx != N) {
		while(!st.empty()){
			if( st.top() == data[dataidx]) {
				st.pop();
				dataidx++;
				buf[bufidx++]='-';
			}
			else {
				printf("NO"); return 0;
			}
		}
	}
	bufidx=0;
	while(buf[bufidx]){
		printf("%c\n", buf[bufidx++]);
	}
	return 0;
}