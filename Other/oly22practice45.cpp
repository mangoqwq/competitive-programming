#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<ll> pre;

struct Segtree{

#define mid ((l + r) >> 1)

    struct Node{
        int lc, rc; ll tot, lz;
    };

    int N;
    vector<Node> st;
    int T;

    Segtree() = default;
    Segtree(int N) : N(N) {
        st.resize(100 * N);
        T = 0;

        build(0, 1, N);
    }

    int build(int v, int l, int r){
        if (l == r) return v;
        st[v].lc = build(++T, l, mid);
        st[v].rc = build(++T, mid + 1, r);
        return v;
    }

    int insert(int v, int l, int r, int ql, int qr, int val){
        if (l > qr || r < ql || ql > qr) return v;
        int nv = ++T;
        if (l >= ql && r <= qr){
            st[nv] = {st[v].lc, st[v].rc, st[v].tot + (pre[r] - pre[l - 1]) * val, st[v].lz + val};
            return nv;
        }
        st[nv].lc = insert(st[v].lc, l, mid, ql, qr, val);
        st[nv].rc = insert(st[v].rc, mid + 1, r, ql, qr, val);
        st[nv].tot = st[st[nv].lc].tot + st[st[nv].rc].tot + st[v].lz * (pre[r] - pre[l - 1]);
        st[nv].lz = st[v].lz;
        return nv;
    }
    int insert(int v, int ql, int qr, int val){ return insert(v, 1, N, ql, qr, val); }

    ll query(int vl, int vr, int l, int r, int ql, int qr, ll downl, ll downr){
        if (l > qr || r < ql || ql > qr) return 0;
        if (l >= ql && r <= qr){
            ll ret = (downr - downl) * (pre[r] - pre[l - 1]);
            ret += st[vr].tot;
            ret -= st[vl].tot;
            return ret;
        }
        return query(st[vl].lc, st[vr].lc, l, mid, ql, qr, downl + st[vl].lz, downr + st[vr].lz) +
               query(st[vl].rc, st[vr].rc, mid + 1, r, ql, qr, downl + st[vl].lz, downr + st[vr].lz);
    }
    ll query(int vl, int vr, int ql, int qr){ return query(vl, vr, 1, N, ql, qr, 0, 0); }

#undef mid
};

using pii = pair<int, int>;

int main(){
    cin.tie(0)->sync_with_stdio(0);

#ifndef ONLINE_JUDGE
    freopen("txt.in", "r", stdin);
#endif

    int N, Q, A; cin >> N >> Q >> A;

    vector<int> skill(N + 1);
    vector<pii> skills;
    for (int i = 1; i <= N; ++i){
        cin >> skill[i];
        skills.push_back({skill[i], i});
    }

    sort(skills.begin(), skills.end());
    vector<int> ord(N + 1), s(N + 1);
    for (int i = 1; i <= N; ++i){
        ord[i] = lower_bound(skills.begin(), skills.end(), pii{skill[i], i}) - skills.begin() + 1;
        s[i] = skills[i].first;
    }

    struct Edge{ int to; ll w; };
    vector<vector<Edge>> adj(N + 1);
    for (int i = 0; i < N - 1; ++i){
        int a, b, w; cin >> a >> b >> w;
        a = ord[a], b = ord[b];
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
        // cout << a << " " << b << " " << w << '\n';
    }

    vector<ll> dist(N + 1);
    vector<int> sz(N + 1), par(N + 1), heavy(N + 1);
    vector<int> tmp1(N + 1);
    function<void(int)> dfs = [&](int v){
        sz[v] = 1;
        for (auto [to, w] : adj[v]){
            if (to == par[v]) continue;
            tmp1[to] = w;
            par[to] = v;
            dist[to] = dist[v] + w;
            dfs(to);
            sz[v] += sz[to];

            if (!heavy[v] || sz[to] > sz[heavy[v]]){
                heavy[v] = to;
            }
        }
    };
    dfs(1);

    vector<int> head(N + 1), tail(N + 1), in(N + 1), out(N + 1);
    vector<int> tmp(N + 1);
    int T = 0;
    function<void(int, int)> decomp = [&](int v, int h){
        in[v] = ++T;
        tmp[T] = v;
        head[v] = h;
        tail[v] = v;
        if (heavy[v]){
            decomp(heavy[v], h);
            tail[v] = tail[heavy[v]];
        }
        for (auto [to, w] : adj[v]){
            if (to == par[v] || to == heavy[v]) continue;
            decomp(to, to);
        }
        out[v] = T;
    };
    decomp(1, 1);

    // debug HLD
    // for (int i = 1; i <= N; ++i){
    //     if (i == tail[i]){
    //         int v = i;
    //         while (head[v] == head[i]){
    //             cout << v << " ";
    //             if (v == 0) break;
    //             v = par[v];
    //         }
    //         cout << '\n';
    //     }
    // }

    pre = vector<ll>(N + 1);
    vector<ll> pre1(N + 1);
    for (int i = 1; i <= N; ++i){
        pre1[i] = dist[i] + pre1[i - 1];
        pre[i] = tmp1[tmp[i]] + pre[i - 1];
    }

    vector<ll> rt(N + 1);
    Segtree st(N + 1);
    for (int i = 1; i <= N; ++i){
        int v = i;
        rt[i] = rt[i - 1];
        while (v){
            rt[i] = st.insert(rt[i], in[head[v]], in[v], 2);
            v = par[head[v]];
        }
    }

    ll ans = 0;
    while (Q--){
        ll v, L, R; cin >> v >> L >> R;
        v = ord[v];
        L = (L + ans) % A;
        R = (R + ans) % A;
        if (R < L) swap(L, R);
        L = lower_bound(skills.begin(), skills.end(), pii{L, -1}) - skills.begin() + 1;
        R = upper_bound(skills.begin(), skills.end(), pii{R, 1e9}) - skills.begin() - 1 + 1;

        ans = pre1[R] - pre1[L - 1];
        ans += dist[v] * (R - L + 1);
        while (v){
            ans -= st.query(rt[L - 1], rt[R], in[head[v]], in[v]);
            v = par[head[v]];
        }
        cout << ans << '\n';
#ifndef ONLINE_JUDGE
        ans = 0;
#endif
    }
}

/*
10 10 10
0 0 1 2 4 7 7 7 7 9
1 2 270
2 6 217
1 4 326
2 3 361
4 5 116
6 7 38
1 8 800
5 9 210
7 10 278
*/
