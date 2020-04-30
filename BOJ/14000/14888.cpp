// baekjoon 14888 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX_N 11

int N, ansmax, ansmin, data[MAX_N], operater[MAX_N];
bool visited[MAX_N];
// 1(+), 2(-), 3(*), 4(/) 

int operate(int a, int b, int op) {
	int tmp = 0;
	switch(op) {
		case 1: tmp = a+b; break;
		case 2: tmp = a-b; break;
		case 3: tmp = a*b; break;
		case 4: tmp = a/b; break;
	}
	return tmp;
}

void Calculate(int num, int curr_sum, int op) {
	if(num == N-1) {
		int tmp = operate(curr_sum, data[num],op);
		ansmax = max(ansmax, tmp);
		ansmin = min(ansmin, tmp);
		return;
	}

	for (int i=0; i<N-1; i++) {
		if(!visited[i]) {
			visited[i]=true;
			Calculate(num+1, operate(curr_sum, data[num], op), operater[i]);
			visited[i]=false;
		}
	}
}

int main(){
	scanf("%d", &N);
	for (int i=0; i<N; i++)
		scanf("%d", &data[i]);
	int opIdx=0;
	for (int i=1; i<5; i++) {
		int op_num=0;
		scanf("%d", &op_num);
		while (op_num--) {
			operater[opIdx++]=i;
		}
	}
	ansmin=1e9;
	ansmax=-1e9;
	for (int i=0; i<N-1; i++) {
		visited[i]=true;
		Calculate(1, data[0], operater[i]);
		visited[i]=false;
	}
	printf("%d\n%d", ansmax, ansmin);
	return 0;
}