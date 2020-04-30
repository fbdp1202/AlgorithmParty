#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> wordlens[10001];

int getAnswer(string query) {
	int len = query.length();
	int ret = 0;
	for (int i=0; i<wordlens[len].size(); i++) {
		bool check = true;
		for (int j=0; j<len; j++) {
			if (query[j] == '?') continue;
			if (query[j] != wordlens[len][i][j]) {
				check = false;
				break;
			}
		}
		if (check) ret++;
	}
	return ret;
}

vector<int> solution(vector<string> words, vector<string> queries) {
    for (int i=0; i<words.size(); i++)
    	wordlens[words[i].length()].push_back(words[i]);

    vector<int> answer;
    for (int i=0; i<queries.size(); i++)
    	answer.push_back(getAnswer(queries[i]));
    return answer;
}

int main()
{
	int N, Q;
	string str;
	vector<string> words, queries;
	cin >> N >> Q;
	for (int i=0; i<N; i++) {
		string str;
		cin >> str;
		words.push_back(str);
	}

	for (int i=0; i<Q; i++) {
		string str;
		cin >> str;
		queries.push_back(str);
	}

	vector<int> answer = solution(words, queries);
	for (int i=0; i<answer.size(); i++) {
		printf("%d ", answer[i]);
	}
	return 0;
}