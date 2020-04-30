// baekjoon 1541 yechan
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int result = 0, tmp = 0;
	int op = 1; // '+': 1, '-': -1 
	char c;
	while((c = getchar()) && (c != EOF) && (c != '\n')){
		if('0'<= c && c <= '9') { tmp*=10; tmp += c -'0'; }
		if(c == '+'){ result+= op*tmp; tmp = 0; }
		if(c == '-'){ result+=op*tmp; op=-1; tmp=0; }
	}
	result+=op*tmp;
	printf("%d", result);
}