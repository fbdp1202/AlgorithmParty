#include <iostream>
#include <queue>
using namespace std;

struct Custom{
	int x;
	int y;
	int value;
	Custom(int value):x(0),y(0),value(value){}
};

struct cmp{
	bool operator()(Custom t, Custom u){
		return t.value > u.value;
	}
};


int main() {
	priority_queue<Custom, vector<Custom>, cmp > pq;

	pq.push(Custom(5));
	pq.push(Custom(2));
	pq.push(Custom(8));
	pq.push(Custom(9));
	pq.push(Custom(1));
	pq.push(Custom(14));

	pq.pop();
	pq.pop();

	cout << "pq top: " << pq.top().value << '\n';

	if (!pq.empty()) cout << "pq size: " << pq.size() << '\n';

	while (!pq.empty()) {
		cout << pq.top().value << " ";
		pq.pop();
	}
	cout << '\n';

	return 0;
}