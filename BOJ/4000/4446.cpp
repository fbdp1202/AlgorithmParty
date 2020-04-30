// baekjoon 4446 yechan
#include <bits/stdc++.h>
using namespace std;

char str[101];
char consonant[27];
char vowel[27];
bool isvowel[27];

int main() {
	isvowel['a'-'a']=true;
	isvowel['i'-'a']=true;
	isvowel['e'-'a']=true;
	isvowel['y'-'a']=true;
	isvowel['o'-'a']=true;
	isvowel['u'-'a']=true;

	vowel['a'-'a']='e'-'a';
	vowel['i'-'a']='o'-'a';
	vowel['y'-'a']='u'-'a';
	vowel['e'-'a']='a'-'a';
	vowel['o'-'a']='i'-'a';
	vowel['u'-'a']='y'-'a';

	consonant['b'-'a']='p'-'a';
	consonant['k'-'a']='v'-'a';
	consonant['x'-'a']='j'-'a';
	consonant['z'-'a']='q'-'a';
	consonant['n'-'a']='t'-'a';
	consonant['h'-'a']='s'-'a';
	consonant['d'-'a']='r'-'a';
	consonant['c'-'a']='l'-'a';
	consonant['w'-'a']='m'-'a';
	consonant['g'-'a']='f'-'a';
	consonant['p'-'a']='b'-'a';
	consonant['v'-'a']='k'-'a';
	consonant['j'-'a']='x'-'a';
	consonant['q'-'a']='z'-'a';
	consonant['t'-'a']='n'-'a';
	consonant['s'-'a']='h'-'a';
	consonant['r'-'a']='d'-'a';
	consonant['l'-'a']='c'-'a';
	consonant['m'-'a']='w'-'a';
	consonant['f'-'a']='g'-'a';

	while (fgets(str, 101, stdin)) {
		for (int i=0; str[i]; i++) {
			if ('a' <= str[i] && str[i] <= 'z') {
				if (isvowel[str[i]-'a']) printf("%c", vowel[str[i]-'a']+'a');
				else printf("%c", consonant[str[i]-'a']+'a');
			} else if ('A' <= str[i] && str[i] <= 'Z') {
				if (isvowel[str[i]-'A']) printf("%c", vowel[str[i]-'A']+'A');
				else printf("%c", consonant[str[i]-'A']+'A');
			} else {
				printf("%c", str[i]);
			}
		}
	}

	return 0;
}