#include <cstdio>
#include <cmath>
using namespace std;

typedef long long ll;
inline ll upper(ll n) { return (ll)(n+(n+1)*((1LL<<(n+1))-1));}
ll n;

int main(void)
{
  scanf("%lld", &n);
  int l = 1, r = 71, ans = 0;
  int i = 1;
  while (1) {
    if (upper(i) >= n) break;
    i++;
  }
  printf("%d\n", i);

  // while(l <= r){
  //   int m = (l + r) / 2;
  //   ll bound = upper(m);
  //   if(bound < n) l = m + 1;
  //   else if(bound > n){
  //     r = m - 1;
  //     ans = m;
  //   }
  //   else{
  //     ans = m;
  //     break;
  //   }
  // }
  // printf("%d\n",ans);
  return 0;
}