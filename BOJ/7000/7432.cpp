// baekjoon 7432 yechan
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int N;
char path[81];

struct DIR{
	char data[9];
	vector<DIR> child;

	DIR(){};
	DIR(const char *str) {
		int i;
		for (i=0; str[i]; i++)
			data[i] = str[i];
		data[i]='\0';
	}
	void update(const char *str) {
		if (!*str) return;
		char input[9];
		int i, j;
		for (i=0; str[i] != '\\' && str[i]; i++)
			input[i] = str[i];
		input[i] = '\0';
		for (j=0; j<child.size(); j++) {
			if (!strcmp(child[j].data, input)) {
				if (str[i] == '\\') child[j].update(str+i+1);
				break;
			}
		}
		if (j == child.size()){
			child.push_back(DIR(input));
			if (str[i] == '\\') child[j].update(str+i+1);
		}
	}

	void dfs(int num) {
		if (num != -1) {
			for (int i=0; i<num; i++)
				printf(" ");
			printf("%s\n", data);
		}
		sort(child.begin(), child.end());
		for (int i=0; i<child.size(); i++) {
			child[i].dfs(num+1);
		}
	}

	bool operator<(const DIR &d) {
		if(strcmp(data, d.data) <= 0)
			return true;
		else
			return false;
	}
};

int main() {
	DIR root;
	int N;
	scanf("%d", &N);
	for (int i=0; i<N; i++) {
		scanf("%s", path);
		root.update(path);
	}
	root.dfs(-1);
	return 0;
}