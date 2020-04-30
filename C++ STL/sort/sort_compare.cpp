#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
using namespace std;


class Student{
public:
	string name;
	int age;
	Student(string name, int age):name(name), age(age){}
};

void Print(vector<Student> &v) {
	cout << "Student : ";
	for (int i=0; i<5; i++) {
		cout << "[" << v[i].name << ", " << v[i].age << "]";
	}
	cout << endl;
}

bool compare(Student a, Student b) {
	if (a.name == b.name) {
		return a.age < b.age;
	}else {
		return a.name < b.name;
	}
}

int main(void) {
	vector<Student> v;
	v.push_back(Student("cc", 10));
	v.push_back(Student("ba", 24));
	v.push_back(Student("aa", 11));
	v.push_back(Student("cc", 8));
	v.push_back(Student("bb", 21));

	Print(v);
	sort(v.begin(), v.end(), compare);
	Print(v);

	return 0;
}

// > output
// Student : [cc, 10][ba, 24][aa, 11][cc, 8][bb, 21]
// Student : [aa, 11][ba, 24][bb, 21][cc, 8][cc, 10]
// Program ended with exit code: 0