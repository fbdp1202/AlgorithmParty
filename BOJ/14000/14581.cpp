// baekjoon 14581 yechan
#include <iostream>
#include <string>

using namespace std;

int main() {
	string str;
	cin >> str;

	string fan = ":fan:";

	cout << fan << fan << fan << "\n";
	cout << fan << ":" << str << ":" << fan << "\n";
	cout << fan << fan << fan;
}