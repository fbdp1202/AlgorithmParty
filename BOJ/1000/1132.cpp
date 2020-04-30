// baekjoon 1132 yechan
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

int N;
bool used[10];
bool check[10]; // is top position?
char str[13];
pair<ll, int> data[10]; // (value, alpha pos)
ll ret;

int main()
{
	scanf("%d", &N);
	for (int i=0; i<10; i++)
		data[i].second = i;

	int count=0;
	while (N--) {
		scanf("%s", str);
		int slen = (int) strlen(str);

		ll position = 1;
		// first digit can't define to 0.
		check[str[0]-'A']=true;
		for (int i=slen-1; i>=0; i--) {
			data[str[i]-'A'].first += position;
			position *= 10;
			if (!used[str[i]-'A']) used[str[i]-'A']=true, count++;
		}
	}
	sort(data, data+10);

	int zero_pos = -1;
	if (count == 10) {
		for (int i=0; i<10; i++) {
			if (check[data[i].second]) continue;
			zero_pos=i;
			break;
		}
	}

	ll mul = 9;
	for (int i=9; i>=0; i--) {
		if (!used[data[i].second]) continue;
		if (zero_pos == i) continue;
		ret += (mul--)*data[i].first;
	}
	printf("%lld\n", ret);
	return 0;
}