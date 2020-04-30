// baekjoon 10987 yechan
#include <cstdio>
using namespace std;

int i, result;
char buf[101];

int main() {
	scanf("%s", buf);
	while(buf[i]){
		switch(buf[i]){
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u': result++;
		}
		i++;
	}
	printf("%d", result);
	return 0;
}