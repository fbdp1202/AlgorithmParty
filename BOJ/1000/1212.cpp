// baekjoon 1212 yechan
#include <cstdio>
using namespace std;

char d;

int main() {
	int flag = 1;
	while (scanf(" %c", &d) != -1) {
		switch(d) {
			case '0': break;
			case '1': printf("1"); break;
			case '2': printf("10"); break;
			case '3': printf("11"); break;
			case '4': printf("100"); break;
			case '5': printf("101"); break;
			case '6': printf("110"); break;
			case '7': printf("111"); break;
		}
		if (d != '0'){
			flag = 0;
			break;
		} 
	}
	if (flag) {
		printf("0\n"); return 0;
	}

	while (scanf(" %c", &d) != -1) {
		switch(d) {
			case '0': printf("000");break;
			case '1': printf("001"); break;
			case '2': printf("010"); break;
			case '3': printf("011"); break;
			case '4': printf("100"); break;
			case '5': printf("101"); break;
			case '6': printf("110"); break;
			case '7': printf("111"); break;
		}
	}
	return 0;
}