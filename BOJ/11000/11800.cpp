// baekjoon 11800 yechan
#include <bits/stdc++.h>
using namespace std;

const char str[7][10] ={
	" ",
	"Yakk",
	"Doh",
	"Seh",
	"Ghar",
	"Bang",
	"Sheesh"
};

const char str2[7][10] {
	" ",
	"Habb Yakk",
	"Dobara",
	"Dousa",
	"Dorgy",
	"Dabash",
	"Dosh"
};

int T;

int main() {
	scanf("%d", &T);
	for (int t=1; t<=T; t++) {
		printf("Case %d: ", t);
		int x, y;
		scanf("%d%d", &x, &y);
		if (x < y) swap(x, y);
		if (x == y) {
			printf("%s\n", str2[x]);
		} else if (x == 6 && y == 5){
			printf("Sheesh Beesh\n");
		} else {
			printf("%s %s\n", str[x], str[y]);
		}
	}
	return 0;
}