// baekjoon 1068 yechan
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX_N=51;

int N;
int parent[MAX_N];
vector<int> child[MAX_N];
bool visited[MAX_N];

void delNode(int here) {
	visited[here]=true;
	for (int there: child[here])
		delNode(there);
}

int getReefNode(int here) {
	int num_child = 0;
	int ret = 0;
	for (int there: child[here]) {
		if (!visited[there]) {
			num_child++;
			ret += getReefNode(there);
		}
	}
	return ret + (num_child==0);
}

int main(void)
{
	scanf("%d", &N);
	for (int i=0; i<N; i++) {
		scanf("%d", &parent[i]);
		if (parent[i] == -1) continue;
		child[parent[i]].push_back(i);
	}

	int d;
	scanf("%d", &d);
	delNode(d);

	int ret = 0;
	for (int i=0; i<N; i++)
		if (!visited[i] && parent[i] == -1)
			ret = getReefNode(i);

	printf("%d\n", ret);
	return 0;
}