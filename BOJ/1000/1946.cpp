// baekjoon 1946

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
	int T, N, tmp1, tmp2, count;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		vector <pair<int,int>> pv;
		count = 1;
		cin >> N;
		for (int j = 0; j < N; ++j)
		{
			cin >> tmp1 >> tmp2;
			pv.push_back(make_pair(tmp1, tmp2));
		}
		sort(pv.begin(), pv.end());
		tmp1 = pv[0].second;
		for (int j = 1; j < pv.size(); ++j)
		{
			if(tmp1 > pv[j].second){
				count++;
				tmp1 = pv[j].second;
			}
		}
		cout << count << endl;
	}
}