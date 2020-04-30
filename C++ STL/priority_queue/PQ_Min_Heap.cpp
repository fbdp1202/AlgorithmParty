#include <iostream>
#include <queue>
using namespace std;

int main() {
	priority_queue<int, vector<int>, greater<int> > pq;

	pq.push(5);
	pq.push(2);
	pq.push(8);
	pq.push(9);
	pq.push(1);
	pq.push(14);

	pq.pop();
	po.pop();

	cout << "pq top: "<< pq.top() << '\n';
	if (!pq.empty()) cout <<"pq.size: " << pq.size() << '\n';

	while (!pq.empty()) {
		cout << pq.top() << " ";
		pq.pop();
	}

	cout << '\n';

	return 0;
}