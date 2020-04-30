// baekjoon 1759 yechan
#include <cstdio>
#include <algorithm>
using namespace std;

int L, C, isVowel[16];
char values[16], result[16];

void BackTracking(int num, int start, int consonant, int vowel) {
	if (num == L) {
		if (consonant >= 2 && vowel >= 1) {
			printf("%s\n", result);
		}
		return;
	}

	for (int i=start; i<C; i++) {
		result[num]=values[i];
		BackTracking(num+1, i+1, consonant+!isVowel[i], vowel+isVowel[i]);
	}
}

int main() {
	scanf("%d %d", &L, &C);
	for (int i=0; i<C; i++){
		scanf(" %c", &values[i]);
	}
	sort(values, values+C);

	for (int i=0; i<C; i++) {
		switch(values[i]) {
			case 'a' :
			case 'e' :
			case 'i' :
			case 'o' :
			case 'u' : isVowel[i]=1; break;
		}
	}	

	BackTracking(0, 0, 0, 0);
	return 0;
}