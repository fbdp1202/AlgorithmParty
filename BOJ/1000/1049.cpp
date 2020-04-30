// baekjoon 1049
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 987654321
int main(void)
{
	int N, M;
	cin >> N >> M;
	int money = 0;
	int min_pkg = INF, min_line = INF;
	int tmp_pkg, tmp_line;
	for (int i = 0; i < M; ++i)
	{
		cin >> tmp_pkg >> tmp_line;
		if(tmp_pkg < min_pkg)
			min_pkg = tmp_pkg;
		if(tmp_line < min_line)
			min_line = tmp_line;
	}
	money += N%6*min_line;
	N -= N%6;
	if(min_line*6 > min_pkg){
	    if(money > min_pkg) money = min_pkg;
		money += min_pkg*(N/6);
	}
	else
		money += min_line*N;
	cout << money;
}