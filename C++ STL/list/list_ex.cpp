/*
리스트 기본 함수

iterator(반복자)
- begin(): beginning iterator를 반환
- end(): end iterator를 반환

추가 및 삭제
- push_front(element): 리스트 제일 앞에 원소 추가
- pop_front(): 리스트 제일 앞에 원소 삭제
- push_back(element): 리스트 제일 뒤에 원소 추가
- pop_back(): 리스트 제일 뒤에 원소 샂게
- insert(iterator, element): iterator가 가리키는 부분 "앞"에 원소를 추가
- erase(iterator): iterator가 가리키는 부분에 원소를 삭제

조회
- *iterator: iterator가 가리키는 원소에 접근
- front(): 첫번째 원소를 반환
- back(): 마지막 원소를 반환

기타
- empty(): 리스트가 비어있으면 true 아니면 false를 반환
- size(): 리스트 원소들의 수를 반환

 */
#include <iostream>
#include <list>

using namespace std;

int main() {
	list<int> l;

	l.push_back(5);
	l.push_back(6);
	l.push_back(7);
	l.push_back(8);
	l.push_back(9);
	l.push_back(10);

	l.pop_back();

	l.push_front(4);
	l.push_front(3);
	l.push_front(1);
	l.push_front(0);

	l.pop_front();

	cout << "list front value:" << l.front() << '\n';
	cout << "list end value:" << l.back() << '\n';

	cout << "list size:"<< l.size() << '\n';

	cout << "Is it empty?:" << (l.empty() ? "Yes" : "No") << '\n';

	list<int>::iterator begin_iter = l.begin();
	list<int>::iterator end_iter = l.end();

	begin_iter++;
	l.insert(begin_iter, 2);

	end_iter--;
	l.erase(end_iter);

	cout << "list " << distance(l.begin(), begin_iter)+ 1 << " element: " << *begin_iter << '\n';

	return 0;
}
