#include <cstdio>
#include <algorithm>
#include <vector>
#define pb(a) push_back(a)
using namespace std;
 
typedef pair<int, int> pii;
typedef long long lld;
int N,L;
 
pii stick[100001];
 
lld T[100001];
lld D[100001];
 
vector<int> tpos;
vector<int> dpos;
int main()
{
    scanf("%d%d",&N,&L);
    for(int i=0;i<N;++i){
        scanf("%d%d",&stick[i].first,&stick[i].second);
        tpos.pb(stick[i].first);
        dpos.pb(stick[i].second);
    }
    sort(stick,stick+N);
    sort(tpos.begin(),tpos.end());
	for (auto &a : tpos) printf("%lld ", a);
	puts("");
    sort(dpos.begin(),dpos.end());
	for (auto &a : dpos) printf("%lld ", a);
	puts("");
    tpos.erase(unique(tpos.begin(),tpos.end()),tpos.end());
	for (auto &a : tpos) printf("%lld ", a);
	puts("");
    dpos.erase(unique(dpos.begin(),dpos.end()),dpos.end());
	for (auto &a : dpos) printf("%lld ", a);
	puts("");
    long long ans = 0;
    for(int i=0;i<N;++i){
        int tidx = lower_bound(tpos.begin(),tpos.end(),stick[i].first)-tpos.begin();
        int didx = lower_bound(dpos.begin(),dpos.end(),stick[i].second)-dpos.begin();
        long long t = T[tidx];
        long long d = D[didx];
        int len = L + (abs(stick[i].first-stick[i].second));
        T[tidx] = max(t,d+len);
        D[didx] = max(d,t+len);
        ans = max(T[tidx],max(ans,D[didx]));
    }
    printf("%lld\n",ans);
}