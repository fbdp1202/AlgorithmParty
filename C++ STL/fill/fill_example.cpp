// Reference : https://twpower.github.io/121-usage-of-fill-function
/* 기본 함수 구조 및 매개변수
#include <algorithm>

void fill (ForwardIterator first, ForwardIterator last, const T& val);
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	vector<int> v(8);

	// Array [0, 4) fill 1.
	fill(v.begin(), v.begin()+4, 1);
	// Array [4, 8) fill 2.
	fill (v.begin()+4, v.end(), 2);

	cout << "v contains :";
	for (vector<int>::iterator it=v.begin(); it!=v.end(); ++it)
		cout << '' << *it;
	cout << '\n';

	int a[8] = {0,};

	fill(a, a + 4, 1);

	printf("a contains :");
	for (int i = 0; i <sizeof(a)/sizeof(int); i++)
		printf(" %d", a[i]);
	printf("\n");

	return 0;
}