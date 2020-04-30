// baekjoon 2002 yechan
#include <bits/stdc++.h>
using namespace std;

const int MAX_N=1001;

int N, arr[MAX_N];
bool visited[MAX_N];
map<string,int> m;

int main() {
	cin >> N;
	for (int i=0; i<N; i++) {
		string s;
		cin >> s;
		m[s] = i;
	}

	for (int i=0; i<N; i++) {
		string s;
		cin >> s;
		arr[i] = m[s];
		for (int j=i-1; j>=0; j--)
			if (arr[i] < arr[j])
				visited[j]=true;
	}

	int cnt = 0;
	for (int i=0; i<N; i++)
		if (visited[i])
			cnt++;
	printf("%d\n", cnt);

	return 0;
}