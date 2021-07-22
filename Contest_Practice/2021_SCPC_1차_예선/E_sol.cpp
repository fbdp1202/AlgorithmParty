// blog.kyouko.moe/m/61
#include <cstdio>
#include <vector>
using namespace std;

struct UFD
{
    vector<pair<int, long long> > ufd;
    explicit UFD(int N) : ufd(N) {
        for (int i=0; i<N; ++i) ufd[i] = {i, 0LL};
    }
    bool isValid(int x)
    {
        return ufd[Find(x).first].second == 0LL;
    }
    void setInvalid(int x)
    {
        ufd[Find(x).first].second = -1LL;
    }
    pair<int, long long> Find(int a)
    {
        auto [p, u] = ufd[a]; // x[p] - x[a] = u;
        if (a == p) return {p, u};

        auto [r, v] = Find(p); // x[r] - x[p] = v;
        return ufd[a] = {r, u+v};
    }

    void Union(int a, int b, int t)
    {
        auto [pa, va] = Find(a); // x[pa]-x[a] = va
        auto [pb, vb] = Find(b); // x[pb]-x[b] = vb
        if (!isValid(a) || !isValid(b))
        {
            ufs[pb].first = pa; setInvalid(pa);
        }
        else if (pa == pb)
        {
            if (vb-va != t) setInvalid(pa);
        }
        else ufd[pb] = {pa, va-vb+t};
    }

    enum Cases {No, Yes, Any};
    pawir<Cases, long long> diff(int a, int b)
    {
        auto [pa, va] = Find(a); // x[pa]-x[a] = va
        auto [pb, vb] = Find(b); // x[pb]-x[b] = vb
        if (pa != pb) return {Any, 0LL};
        else if (!isValid(a)) return {No, 0LL};
        else return {Yes, vb-va}; // va-va = (x[p]-x[b])-(x[p]-x[a]) = x[a]-x[b]
    }
};

void solve()
{
    int N, Q; scanf("%d%d", &N,&Q);
    UFD ufd(N);
    while (Q--)
    {
        int c; scanf("%d", &c);
        if (c == 1)
        {
            int u, v, t; scanf("%d%d%d", &u, &v, &t);
            ufd.Union(u-1,v-1, t);
        }
        else
        {
            int u, v; scanf("%d%d", &u, &v);
            auto [res, val] = ufd.diff(u-1, v-1);
            if (res == ufd.No) puts("CF");
            else if (res == ufd.Any) puts("NC");
            else printf("%lld\n", val);
        }
    }
    return;
}

int main()
{
    int T; scanf("%d", &T);
    for (int i=1; i<=T; ++i)
    {
        printf("Case #%d\n", i);
        solve();
    }
}