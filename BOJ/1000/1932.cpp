// baekjoon 1932
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
	int N, tmp;
	vector<vector<int>> v;
	cin >> N;
	for (int i = 0; i < N; ++i){
		vector<int> nums;
		nums.reserve(i+1);
		for(int j = 0; j < i+1; j++){
			cin >> tmp; nums.push_back(tmp);
		}
		v.push_back(nums);
	}
	for (int i = N-2; i >= 0; --i){
		for (int j = 0; j < i+1; ++j){
			v[i][j] += max(v[i+1][j], v[i+1][j+1]);
		}
	}
	cout << v[0][0];
}