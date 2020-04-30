// baekjoon 5543
#include <iostream>
using namespace std;
#define INF 987654321
int main(void)
{
	int tmp, buger=INF, bever=INF;
	for (int i = 0; i < 3; ++i){
		cin >> tmp; buger = (tmp > buger) ? buger : tmp;
	}
	for (int i = 0; i < 2; ++i){
		cin >> tmp; bever = (tmp > bever) ? bever : tmp;
	}
	cout << buger+bever-50;
}