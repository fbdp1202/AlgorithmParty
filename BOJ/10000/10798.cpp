// baekjoon 10798 yechan
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAX_LEN 15

char text[MAX_LEN+1][MAX_LEN+1];
char buf[MAX_LEN+1];

int main()
{
	char c;
	int i=0, j=0;
	while(scanf("%s", buf) != -1){
		for(int b=0; b<strlen(buf); b++){
			text[b][i] = buf[b];
		}
		i++;
	}
	for(int i=0; i<15; i++){
		for(int j=0; j<15; j++){
			if(text[i][j]){
				printf("%c", text[i][j]);
			}
		}
	}
	return 0;
}