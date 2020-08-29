#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll DIV_NUM=1234567891;
const ll R=31;

const int MAX_L=51;

int N;
char str[MAX_L];

int main() {
	scanf("%d", &N);
	scanf("%s", str);

	ll ret = 0;
	ll cur_R = 1;
	for (int i=0; i<N; i++) {
		int num = (int)(str[i]-'a') + 1;
		ret += cur_R*num;
		ret %= DIV_NUM;
		cur_R = (cur_R * R)%DIV_NUM;
	}
	printf("%lld\n", ret);
	return 0;
}