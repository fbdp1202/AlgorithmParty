// baekjoon 1021 yechan
#include <bits/stdc++.h>
using namespace std;

const int MAX_N=51;

int N, M;
deque<int> q;

void forward() {
	int tmp = q.front();
	q.pop_front();
	q.push_back(tmp);
}

void backward() {
	int tmp = q.back();
	q.pop_back();
	q.push_front(tmp);
}

int forwardDistance(int here) {
	int ret = 0;
	while (1) {
		if (q.front() == here) break;
		forward();
		ret++;
	}
	for (int i=0; i<ret; i++) {
		backward();
	}
	return ret;
}

int backwardDistance(int here) {
	int ret = 0;
	while (1) {
		if (q.front() == here) break;
		backward();
		ret++;
	}
	for (int i=0; i<ret; i++)
		forward();
	return ret;
}

int solve(int here) {
	int forwardStep = forwardDistance(here);
	int backwardStep = backwardDistance(here);
	if (forwardStep <= backwardStep) {
		for (int i=0; i<forwardStep; i++)
			forward();
		q.pop_front();
		return forwardStep;
	} else {
		for (int i=0; i<backwardStep; i++)
			backward();
		q.pop_front();
		return backwardStep;
	}
}

int main() {
	scanf("%d%d", &N, &M);
	for (int i=1; i<=N; i++)
		q.push_back(i);

	int ret = 0;
	for (int i=0, x; i<M; i++) {
		scanf("%d", &x);
		ret += solve(x);
	}
	printf("%d\n", ret);
	return 0;
}