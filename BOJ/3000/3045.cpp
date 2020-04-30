// baekjoon 3045 yechan
#include <bits/stdc++.h>
using namespace std;
using P = pair<int,int>;

const int MAX_N=500002;
const int MAX_INF=1e9;

struct Linked_list{
	int value;
	Linked_list *front;
	Linked_list *back;
	Linked_list():Linked_list(-1){}
	Linked_list(int v):value(v), back(nullptr), front(nullptr){}
};

int N, M, K;
Linked_list *arr[MAX_N];
int seq[MAX_N];
int lia[MAX_N];

void connect_list(Linked_list *l1, Linked_list *l2) {
	l1->back = l2;
	l2->front = l1;
}

void delete_list(Linked_list *l) {
	Linked_list *tmp = l->front;
	if (l->front != nullptr) l->front->back = l->back;
	if (l->back != nullptr) l->back->front = tmp;
}

void insert_front_list(Linked_list *l1, Linked_list *l2) {
	Linked_list *tmp = l1->front;
	l1->front = l2;
	l2->back = l1;
	l2->front = tmp;
	if (tmp != nullptr)	tmp->back = l2;
}

void insert_back_list(Linked_list *l1, Linked_list *l2) {
	Linked_list *tmp = l1->back;
	l1->back = l2;
	l2->front = l1;
	l2->back = tmp;
	if (tmp != nullptr) tmp->front = l2;
}

int getStart() {
	for (int i=1; i<=N; i++)
		if (arr[i]->front == nullptr)
			return i;

	return -1;
}

void move_list(char c, int X, int Y) {
	delete_list(arr[X]);
	if (c == 'A') insert_front_list(arr[Y], arr[X]);
	if (c == 'B') insert_back_list(arr[Y], arr[X]);
}

void fill_seq(int start) {
	Linked_list *l = arr[start];
	for (int i=0; i<N; i++, l=l->back)
		seq[i] = l->value;
}

vector<int> lia_seq() {
	fill(lia, lia+N+1, MAX_INF);
	vector<P> tracking;
	for (int i=0; i<N; i++){
		int idx = lower_bound(lia, lia+N+1, seq[i]) - lia;
		lia[idx] = seq[i];
		tracking.push_back(P(idx, seq[i]));
	}

	int len=0;
	while (lia[len] != MAX_INF) {
		len++;
	}
	len--;

	int vsize = tracking.size();
	stack<int> st;
	for (int i=vsize-1; i>=0; i--) {
		if (tracking[i].first == len) {
			st.push(tracking[i].second);
			len--;
		}
	}
	vector<int> ans;
	while (!st.empty()) {
		ans.push_back(st.top());
		st.pop();
	}
	return ans;
}

int main() {
	scanf("%d%d", &N, &M);
	for (int i=1; i<=N; i++)
		arr[i] = new Linked_list(i);

	for (int i=1; i<N; i++)
		connect_list(arr[i], arr[i+1]);

	for (int i=0; i<M; i++) {
		char c;
		int X, Y;
		scanf(" %c %d %d", &c, &X, &Y);
		move_list(c, X, Y);
	}

	fill_seq(getStart());
	vector<int> ans = lia_seq();
	int ansSize = ans.size();

	printf("%d\n", N-ansSize);
	for (int i=1; i<ans[0]; i++)
		printf("A %d %d\n", i, ans[0]);

	for (int i=0; i<ansSize-1; i++)
		for (int j=ans[i]+1; j<ans[i+1]; j++)
			printf("A %d %d\n", j, ans[i+1]);

	for (int i=N; i>ans[ansSize-1]; i--)
		printf("B %d %d\n", i, ans[ansSize-1]);

	return 0;
}