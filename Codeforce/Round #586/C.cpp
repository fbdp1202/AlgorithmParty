#include <cstdio>
#include <cstring>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

const int MAX_N = 500001;
const int MAX_INF = 1e9;

int T, N, M;
char str[MAX_N];
int alpha[26];

int main()
{
	scanf("%s", str);
	for (int i=0; str[i]; i++) {
		bool check = false;
		for (int j=str[i]-'a'-1; j>=0; j--) {
			if (alpha[j]) check=true;
		}
		puts(check ? "Ann" : "Mike");
		alpha[str[i] - 'a']++;
	}
	return 0;
}