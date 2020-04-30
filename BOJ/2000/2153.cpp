// baekjoon 2153 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

char str[22];

int main()
{
	scanf("%s", str);
	int ret = 0;
	for (int i=0; str[i]; i++) {
		if ('a' <= str[i] && str[i] <= 'z') {
			ret += str[i] - 'a' + 1;
		} else {
			ret += str[i] - 'A' + 27;
		}
	}
	bool check=true;
	for (int i=2; i<ret; i++) {
		if (ret % i == 0){
			check=false;
			break;
		}
	}
	if (check) {
		puts("It is a prime word.");
	} else {
		puts("It is not a prime word.");
	}

	return 0;
}