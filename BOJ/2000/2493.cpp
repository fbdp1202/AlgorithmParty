// baekjoon #NUMBER# yechan
#include <cstdio>
#include <algorithm>
#include <stack>
using namespace std;

struct town{
	int h, idx;
	town(){}
	town(int h, int idx) {
		this->h = h;
		this->idx = idx;
	}
};

int N;

int main(){
	scanf("%d", &N);
	int cur;
	stack<town> st;
	int stCnt=0;
	st.push(town(1e9, 0));
	for (int i=1; i<=N; i++) {
		scanf("%d", &cur);
		while (st.top().h < cur){
			st.pop();
		}
		printf("%d ", st.top().idx);
		st.push(town(cur, i));
	}
	return 0;
}