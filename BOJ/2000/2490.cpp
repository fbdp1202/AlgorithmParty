//baekjoon 2490
#include <iostream>
using namespace std;
int main()
{
	int tmp, result;
	for (int i = 0; i < 3; ++i)
	{
		result = 0;
		for (int i = 0; i < 4; ++i)
		{
			cin >> tmp; result += tmp;
		}
		switch(result){
			case 0: cout << "D" << endl; break;
			case 1: cout << "C" << endl; break;
			case 2: cout << "B" << endl; break;
			case 3: cout << "A" << endl; break;
			case 4: cout << "E" << endl; break;
		}
	}
}