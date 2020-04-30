/*
벡터 기본 함수
iterator(반복자)
- begin(): beginning iterator를 반환
- end(): end iterator를 반환

추가 및 삭제
- push_back(element): 벡터 제일 뒤에 원소 추가
- pop_back(): 벡터 제일 뒤에 원소 삭제

조회
- [i]: i번째 원소를 반환
- at[i]: i번째 원소를 반환
- front(): 첫번째 원소를 반환
- back(): 마지막 원소를 반환

기타
- empty(): 벡터가 비어있으면 true 아니면 false를 반환
- size(): 벡터 원소들의 수를 반환

배열과의 차이
- 동적으로 원소를 추가할 수 있으며 크기가 자동으로 늘어난다.

 */
#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> v;

	v.push_back(1):
	v.push_back(2):
	v.push_back(3):
	v.push_back(4):
	v.push_back(5):

	v.pop_back();

	cout << "vector front value: " << v.front() << '\n';
	cout << "vector end value: " << v.back() << '\n';

	cout << "vector opeartor[]: " << v[3] << '\n';
	cout << "vector at: " << v.at(3) << '\n';

	cout << "vector size: " << v.size() << '\n';

	cout << "Is it empty?: " << (v.empty() ? "Yes" : "No") << '\n';

	vector<int>::iterator begin_iter = v.begin();
	vector<int>::iterator end_iter = v.end();

	cout << "vector begin value: " << *begin_iter << '\n';

	return 0;
}