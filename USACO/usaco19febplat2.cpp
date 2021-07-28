#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
using mii = map<int, int>;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f, MAXN = 1501;

template<ll mod>
class Combinatorics{
private:
    vector<ll> fact;
    ll fpow(ll b, ll e){
        ll ret = 1;
        while (e){
            if (1 & e) ret=ret * b % mod;
            b = b * b % mod; e >>= 1;
        }
        return ret;
    }
public:
    Combinatorics(int n){
        fact.resize(n + 1, 0);
        fact[0] = 1;
        for (int i = 1; i <= n; ++i)
            fact[i] = fact[i - 1] * i % mod;
    }
    ll factorial(int n){
        return fact[n];
    }
    ll inv(int n){ return fpow(n, mod-2); }
};

int n, m, x, y;
struct Edge{ int to, w; };
vector<Edge> adj[MAXN];
bool vis[MAXN];
vector<mii> paths;
vector<int> roots, component;

void dfs0(int v, int p){
    vis[v] = 1;
    component.push_back(v);
    for (auto [to, w] : adj[v]){
        if (to == p) continue;
        dfs0(to, v);
    }
}

void dfs(int v, int p, int dist, mii &mp){
    if (v != p) mp[dist]++;
    for (auto [to, w] : adj[v]){
        if (to == p) continue;
        dfs(to, v, dist + w, mp);
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> x >> y;
    Combinatorics<mod> cmb(n);

    for (int i = 1; i <= m; ++i){
        int a, b, d;
        cin >> a >> b >> d;
        adj[a].push_back({b, d});
        adj[b].push_back({a, d});
    }
    for (int i = 1; i <= n; ++i){
        if (vis[i]) continue;
        roots.push_back(i);
        component.clear();
        dfs0(i, i);

        paths.push_back(mii());
        for (int v : component){
            dfs(v, v, 0, paths.back());
        }
    }
    int k = roots.size();
    y = max(0, y - k*x);
    vector<ll> dp(y + 1), last(y + 1);
    dp[0] = 1;

    int id = 0;
    for (mii mp : paths){
        id++;
        swap(last, dp);
        dp.assign(y + 1, 0);
        for (auto [len, cnt] : mp){
            for (int j = len; j <= y; ++j)
                dp[j] = (dp[j] + last[j - len] * cnt % mod * id) % mod;
        }
    }

    ll bad = 0;
    for (int len = 1; len < y; ++len)
        bad = (bad + (len + k * x) % mod * dp[len]) % mod;

    ll ans = 0;
    ll tot_paths = cmb.factorial(k);
    vector<ll> tot_len(k), tot_cnt(k);

    for (int i = 0; i < k; ++i){
        for (auto [len, cnt] : paths[i]){
            tot_len[i] = (tot_len[i] + 1LL * len * cnt) % mod;
            tot_cnt[i] = (tot_cnt[i] + cnt) % mod;
        }
        tot_paths = (tot_paths * tot_cnt[i]) % mod;
    }

    for (int i = 0; i < k; ++i){
        tot_paths = (tot_paths * cmb.inv(tot_cnt[i])) % mod;
        ans = (ans + tot_paths * tot_len[i]) % mod;
        tot_paths = (tot_paths * tot_cnt[i]) % mod;
    }

    ans = (ans + tot_paths * x % mod * k) % mod;

    // cout << tot_paths << " " << ans << " " << bad << '\n';
    cout << (ans - bad + mod) * cmb.inv(k) % mod * cmb.inv(2) % mod << '\n';
}
