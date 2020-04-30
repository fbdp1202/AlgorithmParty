// Round 537 A.cpp yechan
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_LEN = 1001;

char A[MAX_LEN], B[MAX_LEN];
int vowel[MAX_LEN];

int main() {
	scanf("%s", A);
	scanf("%s", B);
	bool flag = true;

	int i;
	for (i=0; A[i] && B[i]; i++) {
		switch(A[i]) {
			case 'a':
			case 'A':
			case 'e':
			case 'E':
			case 'i':
			case 'I':
			case 'o':
			case 'O':
			case 'u':
			case 'U': { 
				vowel[i] = 1;
				break;
			}
			default: vowel[i] = 2;
		}
		switch(B[i]) {
			case 'a':
			case 'A':
			case 'e':
			case 'E':
			case 'i':
			case 'I':
			case 'o':
			case 'O':
			case 'u':
			case 'U': { 
				if (vowel[i] != 1) {
					flag = false;
				}
				break;
			}
			default: {
				if (vowel[i] != 2) {
					flag = false;
				}
			}
		}
		if (!flag) break;
	}

	if (A[i] || B[i]) flag = false;

	if (flag) printf("Yes");
	else printf("No");
	return 0;
}