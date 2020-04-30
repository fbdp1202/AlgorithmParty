// baekjoon 9342 yechan
#include<cstdio>
#include<algorithm>
using namespace std;

int T;
char str[201];

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%s", str);
		bool flag = true;

		int i=0;
		int cflag=0;
		char prev;
		while (str[i]) {
			if (cflag==0) {
				if ('A'<= str[i] && str[i] <= 'F') {
					cflag = 1;
				} else {
					flag =false;
					break;
				}
			}
			else if (cflag==1) { // A
				// if (str[0] == 'A' && str[i] == 'A') {
				// 	flag = false;
				// 	break;
				// }
				if (str[i] != 'A') {
					if (prev == 'A') {
						cflag=2;
						continue;
					}
					else {
						flag=false;
						break;
					}
				}
			}
			else if (cflag==2) { // F
				if (str[i] != 'F') {
					if (prev == 'F') {
						cflag=3;
						continue;
					}
					else {
						flag=false;
						break;
					}
				}
			}
			else if (cflag==3) { // C
				// if (prev == 'C' && str[i] == 'C' && str[i+1] == '\0') {
				// 	flag=false;
				// 	break;
				// }
				if (str[i] != 'C') {
					if (prev == 'C') {
						cflag=4;
						continue;
					}
					else {
						flag=false;
						break;
					}
				}
			}
			else if (cflag==4) {
				if ( !(('A'<= str[i] && str[i] <= 'F') && str[i+1]=='\0') ) {
					flag=false;
					break;
				}
			}
			prev = str[i];
			i++;
		}
		if (flag && cflag>=3) puts("Infected!");
		else puts("Good");
	}
	return 0;
}