#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
using cd = complex<double>;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int SZ = 17, MN = 1 << SZ;
const double PI = acos(-1);

void fft(vector<cd> &a, bool invert){
    int n = a.size();
    for (int i = 1, j = 0; i < n; ++i){
        int bit = n >> 1;
        while (j & bit){
            j ^= bit;
            bit >>= 1;
        }
        j ^= bit;
        if (i < j) swap(a[i], a[j]);  
    }
    for (int sz = 2; sz <= n; sz <<= 1){
        double deg = 2 * PI / sz * (invert ? -1 : 1);
        cd w1 = {cos(deg), sin(deg)};
        for (int i = 0; i < n; i += sz){
            cd w = 1;
            for (int j = 0; j < (sz >> 1); ++j){
                cd y0 = a[i + j], y1 = a[i + j + (sz >> 1)];
                a[i + j] = y0 + w * y1;
                a[i + j + (sz >> 1)] = y0 - w * y1;
                w *= w1;
            }
        }
    }
    if (invert){
        for (auto &y : a) y /= n;
    }
}
vector<ll> multiply(const vector<ll> &va, const vector<ll> &vb){
    vector<cd> a(va.begin(), va.end()), b(vb.begin(), vb.end());
    int N = 1 << (__lg(a.size() + b.size() - 1) + 1);
    a.resize(N); b.resize(N);
    fft(a, 0); fft(b, 0);
    for (int i = 0; i < N; ++i) a[i] *= b[i];
    fft(a, 1);
    vector<ll> ret(N);
    for (int i = 0; i < N; ++i){
        ret[i] = round(a[i].real());
    }
    return ret;
}

ll ans[MN];
int sz[MN], height[MN], vis[MN], col[MN];
vector<int> adj[MN];

void dfs(int v, int p){
    sz[v] = 1;
    height[v] = col[v];
    for (int to : adj[v]){
        if (to == p || vis[to]) continue;
        dfs(to, v);
        sz[v] += sz[to];
        height[v] = max(height[v], col[v] + height[to]);
    }
}

int findcen(int v, int p, int src){
    for (int to : adj[v]){
        if (to == p || vis[to]) continue;
        if (sz[to] * 2 > sz[src]) return findcen(to, v, src);
    }
    return v;
}

void solve(int v, int p, int d, vector<ll> &cnt){
    d += col[v];
    cnt[d]++;
    for (int to : adj[v]){
        if (to == p || vis[to]) continue;
        solve(to, v, d, cnt);
    }
}

void go(int v){
    v = findcen(v, v, v); vis[v] = 1;

    vector<int> nei;
    for (int to : adj[v]){
        if (vis[to]) continue;
        dfs(to, v); nei.push_back(to);
    }
    sort(nei.begin(), nei.end(), [](int a, int b){ return height[a] < height[b]; });
    vector<ll> lst = {0, 0}; lst[col[v]]++;

    for (int i = 0; i < nei.size(); ++i){
        int to = nei[i];
        vector<ll> cnt(height[to] + 1);
        solve(to, v, 0, cnt);
        vector<ll> prod = multiply(cnt, lst);
        for (int i = 0; i < prod.size(); ++i) ans[i] += prod[i];

        if (col[v] == 1) cnt.insert(cnt.begin(), 0);
        if (lst.size() < cnt.size()) lst.resize(cnt.size());
        for (int i = 0; i < cnt.size(); ++i) lst[i] += cnt[i];
    }

    for (int to : adj[v]){
        if (!vis[to]) go(to);
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    for (int i = 1; i <= N; ++i) cin >> col[i];
    for (int i = 1; i < N; ++i){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 1); go(1);

    for (int i = 1; i <= N; ++i) ans[i] += ans[i - 1];
    int Q; cin >> Q;
    while (Q--){
        int l, r; cin >> l >> r;
        cout << ans[r] - (l == 0 ? 0 : ans[l - 1]) << '\n';
    }
}
