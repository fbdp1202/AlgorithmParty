// baekjoon 5988 yechan
#include <cstdio>
#include <cstring>
using namespace std;

int N;
char number[66];

int main() {
	scanf("%d", &N);
	for (int i=0; i<N; i++) {
		scanf("%s", number);
		if( (number[strlen(number)-1]-'0')%2) printf("odd\n");
		else printf("even\n");
	}
}
