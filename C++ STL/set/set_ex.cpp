/*
기본형태
- set<T>: 원하는 자료형 및 클래스 T를 통해 생성

iterator(반복자)
- begin(): beginning iterator를 반환
- end(): end iterator를 반환

추가 및 삭제
- insert(element): 세트에 element를 추가
- erase(element): 세트에 해당하는 element를 삭제
- clear(): 세트에 있는 모든 원소 삭제

조회
- empty(): 비어있으면 true 아니면 false를 반환
- size(): 세트에 포함되어 있는 원소들의 수를 반환

특징
- 중복을 허용하지 않는다.
- 중복을 허용하려면 multiset을 사용해야한다.
 */
#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
	set<string> s;

	s.insert("abc");
	s.insert("def");
	s.insert("ghi");
	s.insert("jkl");

	s.erase("jkl");

	if (!s.empty()) cout << "s size: " << s.size() << '\n';

	cout << *s.find("abc") << '\n';
	cout << *s.find("def") << '\n';

	cout << "abc cout:" << s.count("abc") <<'\n';

	cout << "traverse" << '\n';
	for (auto it = s.begin(); it != s.end(); it++) {
		cout << "value: "<< *it << '\n';
	}

	return 0;
}
