#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
using namespace std;

void Print(vector<int> &v) {
	cout << "vector : ";
	for (int i=0; i<10; i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}

int main(void) {
	srand((int)time(NULL));

	vector<int> v;
	int n = 10;

	for (int i=0; i<n; i++) {
		v.push_back(rand() % 10);
	}
	Print(v);
	sort(v.begin(), v.end(), greater<int>()); // [begin, end) 내림차순으로 정렬
	Print(v);

	return 0;
}

// > output
// vector : 9 7 8 0 1 5 6 5 4 5
// vector : 9 8 7 6 5 5 5 4 1 0
// Program ended with exit code: 0