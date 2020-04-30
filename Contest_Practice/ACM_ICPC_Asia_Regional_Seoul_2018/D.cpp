///////////////////////////////////////
// ACM ICPC Asia Regional Seoul 2018 //
// Problem D.cpp                     //
// Write: Yechan(fbdp1202)           //
///////////////////////////////////////

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N;
char str[40];

int main() {
	scanf("%d", &N);
	while (N--) {
		scanf("%s", str);
		int slen = strlen(str);
		bool flag = false;
		switch(str[slen-1]) {
			// -s
			case 'a':
			case 'o':
			case 'u':
					str[slen]='s'; str[slen+1]='\0';
					flag = true;
					break;
			// -es
			case 'l':
			case 'r':
			case 'v':
					str[slen]='e'; str[slen+1]='s'; str[slen+2]='\0';
					flag = true;
					break;
			// -as
			case 't':
			case 'w':
					str[slen]='a'; str[slen+1]='s'; str[slen+2]='\0';
					flag = true;
					break;
			// -os
			case 'i':
					str[slen]='o'; str[slen+1]='s'; str[slen+2]='\0';
					flag = true;
					break;
			case 'y':
					str[slen-1]='i'; str[slen]='o'; str[slen+1]='s'; str[slen+2]='\0';
					flag = true;
					break;
			case 'n':
					str[slen-1]='a'; str[slen]='n'; str[slen+1]='e'; str[slen+2]='s'; str[slen+3]='\0';
					flag = true;
					break;
			case 'e':
					if (str[slen-2] == 'n') {
						slen--;
						str[slen-1]='a'; str[slen]='n'; str[slen+1]='e'; str[slen+2]='s'; str[slen+3]='\0';
						flag = true;
					}
					break;
		}
		if (!flag) {
			str[slen]='u'; str[slen+1]='s'; str[slen+2]='\0';
		}
		printf("%s\n", str);
	}
	return 0;
}