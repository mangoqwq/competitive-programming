// #include "books.h"
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll minimum_walk(vector<int> p, int s) {
    int N = p.size();

    ll ans = 0;
    for (int i = 0; i < N; ++i){
        ans += abs(p[i] - i);
    }

    vector<int> vis(N);

    using pii = pair<int, int>;

    auto extend = [&](int l, int r) -> pii{
        int lo = l, hi = r;
        queue<int> q;
        if (!vis[lo]) vis[lo] = 1, q.push(lo);
        if (!vis[hi]) vis[hi] = 1, q.push(hi);

        while (!q.empty()){
            int v = q.front(); q.pop();
            lo = min(lo, v);
            hi = max(hi, v);
            if (!vis[p[v]]) vis[p[v]] = 1, q.push(p[v]);
            while (l > lo) l--, vis[l] = 1, q.push(l);
            while (r < hi) r++, vis[r] = 1, q.push(r);
        }
        
        return {lo, hi};
    };

    int l = s + 1, r = s;
    int cl = 0, cr = 0;
    int bl = -2, br = 0;

    while (l > 0 || r < N - 1){
        if (l > 0){
            l--, bl += 2;
            if (p[l] != l){
                cl += bl;
                bl = 0;
            }
            auto [lo, hi] = extend(l, r);
            if (hi > r){
                l = lo, r = hi;
                ans += cl;
                cl = cr = bl = br = 0;
                continue;
            }
            else l = lo, r = hi;
        }
        if (r < N - 1){
            r++, br += 2;
            if (p[r] != r){
                cr += br;
                br = 0;
            }
            auto [lo, hi] = extend(l, r);
            if (lo < l){
                l = lo, r = hi;
                ans += cr;
                cl = cr = bl = br = 0;
                continue;
            }
            else l = lo, r = hi;
        }
    }
	ans += cl + cr;
    return ans;
}
