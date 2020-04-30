// baekjoon 10872
#include <iostream>
using namespace std;
typedef unsigned long long int LL;
LL factorial(int n)
{
	if(n == 0) return 1;
	if(n == 1) return 1;
	return n*factorial(n-1);
}
int main(void)
{
	int N;
	cin >> N;
	cout << factorial(N);
}