// baekjoon 11404
#include <iostream>
#include <algorithm>
using namespace std;
#define INF 987654321

int main(void)
{
	int n, m;
	int a, b, c;
	cin >> n;
	cin >> m;
	int **graph = new int*[n];
	for (int i = 0; i < n; ++i) graph[i] = new int[n];
	// Array set 0
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j){
			graph[i][j] = INF;
			if(i == j) graph[i][j] = 0;
		}
	// initalize data
	for (int i = 0; i < m; ++i){
		cin >> a >> b >> c;
		graph[a-1][b-1] = min(graph[a-1][b-1], c);
	}
	for (int k = 0; k < n; ++k)
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
		    if(graph[i][j] == INF)  cout << 0 << ' ';
			else                    cout << graph[i][j] << ' ';
		}
		cout << endl;
	}
}