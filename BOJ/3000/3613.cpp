// baekjoon 3613 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

char str[101];

int main()
{
	scanf("%s", str);

	bool upper = false;
	bool under = false;

	bool check = true;

	bool up = false;
	bool un = false;

	if (str[0] == '_') {
		check=false;
	}
	if ('A' <= str[0] && str[0] <= 'Z') {
		check=false;
	}

	for (int i=0; str[i]; i++) {
		if (str[i] == '_') {
			if (un) {
				check = false;
				break;
			}
			un = true;
			under = true;
			continue;
		}
		if ('A' <= str[i] && str[i] <= 'Z') {
			un = false;
			upper = true;
			continue;
		}
		un = false;
	}

	check = (un) ? false : check;

	if (check && !(upper && under)) {
		if (upper) {
			for (int i=0; str[i]; i++) {
				if ('A' <= str[i] && str[i] <= 'Z') {
					printf("_%c", 'a'+(str[i]-'A'));
				} else {
					printf("%c", str[i]);
				}
			}
		} else {
			un = false;
			for (int i=0; str[i]; i++) {
				if (un) {
					printf("%c", (str[i]-'a') + 'A');
					un = false;
					continue;
				}
				if (str[i] == '_') {
					un = true;
				} else {
					printf("%c", str[i]);
				}
			}
		}
	} else {
		printf("Error!\n");
	}

	return 0;
}