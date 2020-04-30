// baekjoon 15956 yechan
#include <iostream>
#include <set>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <utility>
#include <map>
using namespace std;

const int MAX_N=1e6;
const int MIN_INF=2e9;

int N;
string data;
map<string, int> mStringInt;
vector<string> vIntString;

vector<pair<int,int> > diff;

bool isValue[MAX_N];
int root[MAX_N];
vector<string> group[MAX_N];

int dataStoring(string s) {
	if (mStringInt.count(s)) return mStringInt[s];
	mStringInt[s] = N++;
	vIntString.push_back(s);
	return N-1;
}

int find(int x) {
	if (root[x] < 0) return x;
	return root[x]=find(root[x]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	root[b] = a;
	return;
}

bool isDigit(char c) {
	if ('0' <= c && c <= '9') return true;
	if (c == '-') return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

    memset(root, -1, sizeof(root));

	cin >> data;
	data += "&&";
	N=0;
	int len = data.length();

	string s="";
	bool unequal = false, equal = false;
	bool ispossible = true;

	int x, y;
	for (int i=0; i<len; i++) {
		if (data[i] == '!') {
			x = dataStoring(s);
			unequal = true;
			i++;
			s = "";
		}
		else if (data[i] == '=') {
			x = dataStoring(s);
			equal = true;
			i++;
			s = "";
		}
		else if (data[i] == '&') {
			y = dataStoring(s);

			if (equal) merge(x, y);
			else diff.push_back({x, y});

			unequal = equal = false;
			i++;
			s = "";
		} else {
			s += data[i];
		}
	}

	for (int i=0; i<vIntString.size(); i++)
		group[find(i)].push_back(vIntString[i]);

	string ans;
	for (int i=0; i<vIntString.size(); i++) {
		int numInteger = 0;
		for (int j=0; j<group[i].size(); j++)
			numInteger += isDigit(group[i][j][0]);

		if (numInteger >= 2) {
			cout << "1==2";
			return 0;
		}

		if (numInteger)
			isValue[i] = true;

		if (group[i].size() < 2)
			continue;

		int minIdx = 0;
		int minLength = 1e9;
		for (int j=0; j<group[i].size(); j++) {
			int tmp = group[i][j].size();
			if (tmp < minLength) {
				minLength = tmp;
				minIdx = j;
			}
		}

		for (int j=0; j<group[i].size(); j++) {
			if (j == minIdx) continue;
			ans += group[i][j] + "==" + group[i][minIdx] + "&&";
		}

		swap(group[i][0], group[i][minIdx]);
	}

	set<pair<int,int> > diffSet;
	for (int i=0; i<diff.size(); i++) {
		int a = find(diff[i].first);
		int b = find(diff[i].second);

		if (a == b) {
			cout << "1!=1";
			return 0;
		}

		if (isValue[a] && isValue[b])
			continue;
		diffSet.insert({min(a, b), max(a,b)});
	}

	for (set<pair<int,int> >::iterator it=diffSet.begin(); it != diffSet.end(); it++) {
		int a = (*it).first;
		int b = (*it).second;

		ans += group[a][0] + "!=" + group[b][0] + "&&";
	}

	if (ans.empty()) {
		cout << "1==1";
		return 0;
	}

	for (int i=0; i<2; i++)
		ans.pop_back();

	cout << ans << endl;

	return 0;
}