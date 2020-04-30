#include <cstdio>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX_N=100001;
typedef long long ll;
struct Pos{
	ll x, y, len;
	Pos():x(0),y(0),len(0){}
	Pos(ll x, ll y, ll len):x(x),y(y),len(len){}
};

int T, L, S, E;
int A, B;
Pos t[MAX_N], b[MAX_N];
int tpos, bpos;
ll x;
ll up, down;
ll cur;
ll ret;

int main() {
	setbuf(stdout, NULL);
	scanf("%d", &T);
	for (int test=1; test<=T; test++) {
		printf("Case #%d\n", test);
		scanf("%d%d%d", &L, &S, &E);
		scanf("%d", &A);
		printf("A: %d\n", A);
		ll pos = 0;
		for (int i=0; i<A; i++) {
			scanf("%lld%lld", &t[i].len, &t[i].y);
			pos += t[i].len;
			t[i].x = pos;
		}
		t[A].x = pos;
		t[A].y = E;

		pos = 0;
		scanf("%d", &B);
		printf("B: %d\n", B);
		for (int i=0; i<B; i++) {
			scanf("%lld%lld", &b[i].len, &b[i].y);
			pos += b[i].len;
			b[i].x = pos;
		}
		b[B].x = pos;
		b[B].y = E;

		tpos = bpos = 0;
		cur = S;
		ret = 0;
		stack<Pos> TopStack;
		stack<Pos> BottomStack;

		while (tpos < A || bpos < B) {
			printf("ret: %lld, tpos: %d, bpos: %d\n", ret, tpos, bpos);
			// printf("t[%d].x: %lld, t[%d].y: %lld, t[%d].len: %lld\n", tpos, t[tpos].x, tpos, t[tpos].y, tpos, t[tpos].len);
			// printf("b[%d].x: %lld, b[%d].y: %lld, b[%d].len: %lld\n", bpos, b[bpos].x, bpos, b[bpos].y, bpos, b[bpos].len);
			if (bpos < B && b[bpos].x <= t[tpos].x) {
				if (cur < b[bpos].y) {
					while (!BottomStack.empty()) BottomStack.pop();

					ll upcur = b[bpos].y;
					printf("Hello top\n");
					b[bpos].len += b[bpos-1].x - TopStack.top().x;
					ret += (b[bpos-1].x - TopStack.top().x)*(upcur - cur);
					while (!TopStack.empty()) {
						upcur = min(upcur, TopStack.top().y);
						printf("upcur: %lld, cur: %lld, len: %lld\n", upcur, cur, TopStack.top().len);
						printf("Bottom sum: %d\n", (upcur - cur)*TopStack.top().len);
						ret += (upcur - cur)*TopStack.top().len;
						TopStack.pop();
					}
					BottomStack.push(b[bpos]);
					TopStack.push(t[tpos]);
					cur = b[bpos].y;
					printf("cur: %d\n", cur);
					bpos++;
				} else {
					printf("Push: b[%d]\n", bpos);
					BottomStack.push(b[bpos]);
					bpos++;
				}
			}
			else {
				if (t[tpos].y < cur) {
					while (!TopStack.empty()) TopStack.pop();

					ll downcur = t[tpos].y;
					printf("Hello bottom\n");
					t[tpos].len += t[tpos-1].x - BottomStack.top().x;
					ret += (t[tpos-1].x - BottomStack.top().x)*(cur - downcur);
					while (!BottomStack.empty()) {
						downcur = max(downcur, BottomStack.top().y);
						printf("downcur: %lld, cur: %lld, len: %lld\n", downcur, cur, BottomStack.top().len);
						printf("Top sum: %d\n", (cur - downcur)*BottomStack.top().len);
						ret += (cur - downcur)*BottomStack.top().len;
						BottomStack.pop();
					}
					TopStack.push(t[tpos]);
					BottomStack.push(b[bpos]);
					cur = t[tpos].y;
					printf("cur: %d\n", cur);
					tpos++;
				} else {
					printf("Push: t[%d]\n", tpos);
					TopStack.push(t[tpos]);
					tpos++;
				}
			}
		}
		printf("ret: %lld, tpos: %d, bpos: %d\n", ret, tpos, bpos);
		if (cur <= E) {
			ll upcur = E;
			while (!TopStack.empty()) {
				upcur = min(upcur, TopStack.top().y);
				ret += (upcur - cur)*TopStack.top().len;
				TopStack.pop();
			}
		} else {
			ll downcur = E;
			while (!BottomStack.empty()) {
				downcur = max(downcur, BottomStack.top().y);
				ret += (cur - downcur)*BottomStack.top().len;
				BottomStack.pop();
			}
		}
		printf("%lld\n", ret);
	}
	return 0;
}