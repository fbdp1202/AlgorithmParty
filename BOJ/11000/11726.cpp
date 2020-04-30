// baekjoon 11726
#include <iostream>
using namespace std;

int main(void)
{
	int arr1[1001]={0};
	int arr2[1001]={0};
	int N;
	cin >> N;
	arr1[1] = 1; arr1[2] = 1; arr2[2] = 1;
	for (int i = 3; i < N+1; ++i)
	{
		arr1[i] = (arr1[i-1] + arr2[i-1])%10007;
		arr2[i] = arr1[i-1];
	}
	cout << (arr1[N] + arr2[N])%10007 << endl;
}