// baekjoon ??
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;
const int MAX_N=1000001;
stack<int> st;

char str[MAX_N], com[MAX_N];
int failure[MAX_N];
bool visited[MAX_N]
int comlen;

void getFailure(){
	int j=0;
	for (int i=1; i<comlen; i++) {
		while (j > 0 && com[i] != com[j])
			j = failure[j-1];
		if (com[i] == com[j])
			com[i] = ++j;
	}
}

int main() {
	scanf("%s %s", str, com);
	comlen = strlen(com);
	getFailure();
	int com_pos=0;
	for (int i=0; i<N; i++) {
		if (str[i] == com[com_pos]) {

		}
	}
	return 0;
}