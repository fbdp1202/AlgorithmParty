// baekjoon 1120
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void)
{
	string str1, str2;
	cin >> str1 >> str2;
	int sl1 = str1.size();
	int sl2 = str2.size();
	int min = 987654321;
	int count = 0;
	cout << str1 << endl;
	cout << str2 << endl;
	for (int i = 0; i < sl2-sl1; ++i)
	{
	    count = 0;
		for (int j = 0; j < sl1; ++j)
		{
			if(str1[j] != str2[i+j])
				count++;
		}
		if(count < min)
			min = count;
	}
	cout << min;
}