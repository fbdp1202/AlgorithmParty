// baekjoon 1789 yechan
#include<iostream>
#include<cmath>
using namespace std;
typedef long long unsigned int LL;

int main()
{
	LL S;
	cin >> S;
	cout << (LL)(-1+sqrt(1+8*S))/2;
}