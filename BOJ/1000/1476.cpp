// baekjoon 1476
#include <iostream>
using namespace std;
int main(void)
{
	int E, S, M; // Earth, Sun, Moon
	int result;
	int curE, curS, curM;
	int ME=15, MS=28, MM=19;
	int MES = ME*MS;
	cin >> E >> S >> M;
	result = E;
	curE = E-1; curS = E-1; curM = E-1;
	while(curS != S-1){
		result += ME;
		curS = (curS+ME)%MS;
		curM = (curM+ME)%MM;
	}
	while(curM != M-1){
		result += MES;
		curM = (curM+MES)%MM;
	}
	cout << result;
}