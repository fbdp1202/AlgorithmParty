// baejkoon 1009 yechan
#include <cstdio>
#include <algorithm>
using namespace std;
int T, a, b;

int f(int a, int b) {
	if (b==0)	return 1;
	if (b==1)	return a%10;
	int tmp=f(a, b/2)%10;
	tmp = (tmp*tmp)%10;
	if (b%2 ==1) tmp *= a;
	return (tmp%10);
}


int main(){
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &a, &b);
		int tmp = f(a,b);
		printf("%d\n", (!tmp) ? 10 : tmp);
	}
	return 0;
}