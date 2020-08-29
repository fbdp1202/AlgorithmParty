/*
대경권 본선 3번

포멧하다가...
코드를 분실했다. ㅠ 그냥 짜봤다. 정답 여부 불확실.

일단 문제는 어떤 특정 형태(기억상 2진수중, 0이 2번 연속 나오지 않는)를 만족하면서
3의 배수인 N자리 2진수 개수를 출력하다.
이 수의 첫째 자리는 0일수 없다.

ex)
input:
4

output:
3

simulation:
1110
1101
1011

알고리즘:
- 일단 backtracking를 하면서 0이 연속 2번 나오지 않는 N자리 수를 앞에서 부터 생성한다.
- 3의 배수 확인 방법은 2진수에서 1의 개수가 3의 배수인지 확인하면 된다.
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N;

ll dfs(int here, bool flag, int oneNum) {
	if (here == N) return (oneNum % 3 == 0) ? 1 : 0;
	if (!flag) return dfs(here+1, false, oneNum+1);
	else return dfs(here+1, true, oneNum) + dfs(here+1, false, oneNum+1);
}

int main() {
	scanf("%d", &N);
	printf("%lld\n", dfs(1, false, 1));
	return 0;
}