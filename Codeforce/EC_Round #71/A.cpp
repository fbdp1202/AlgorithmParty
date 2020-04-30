#include <cstdio>
#include <algorithm>
using namespace std;


int T, b, p, f, h, c;

int main()
{
	scanf("%d", &T);
	while (T--) {
		int ret = 0;

		scanf("%d%d%d", &b, &p, &f);
		scanf("%d%d", &h, &c);

		if (h < c) {
			swap(p, f);
			swap(h, c);
		}

		int beef = min(b/2, p);
		b -= beef * 2;
		ret += beef * h;
		ret += c * min(b/2, f);
		printf("%d\n", ret);
	}
	return 0;
}