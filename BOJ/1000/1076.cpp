// baekjoon 1076
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
typedef unsigned long long int LL;
int find_data(string *data, string str)
{
	for (int i = 0; i < 10; ++i)
	{
		if(data[i].compare(str) == 0) return i;
	}
	return -1;
}
int main()
{
	string data[10] = {"black", "brown", "red", "orange", "yellow", 
					   "green", "blue", "violet", "grey", "white"};
	string str;	LL result;
	cin >> str; result=find_data(data, str); result *=10;
	cin >> str; result+=find_data(data, str);
	cin >> str; result*=pow(10, find_data(data, str));
	cout << result;
}