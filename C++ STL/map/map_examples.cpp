#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
	map<string, int> m;

	m.insert(make_pair("a", 1));
	m.insert(make_pair("b", 2));
	m.insert(make_pair("c", 3));
	m.insert(make_pair("d", 4));
	m.insert(make_pair("e", 5));
	m["f"] = 6;


	m.erase("d");
	m.erase("e");
	m.erase(m.find("f"));

	if(!m.empty()) cout << "m.size : " << m.size() << '\n';

	cout << "a : " << m.find("a")->second << '\n';
	cout << "b : " << m.find("b")->second << '\n';

	cout << "a count : " << m.count("a") << '\n';
	cout << "b count : " << m.count("b") << '\n';

	cout << "traverse" << '\n';
	for (auto it = m.begin(); it != m.end(); it++) {
		cout << "key : " << it->first << " " << "value " << it->second << '\n';
	}

	return 0;
}