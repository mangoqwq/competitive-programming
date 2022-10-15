#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 2e5 + 1, L = 17;

struct matrix{
    int n;
    vector<vector<ll>> m;
    matrix() = default;
    matrix(int sz) : n(sz), m(sz+1,vector<ll>(sz+1)){}
    ll& operator()(int r, int c){
        return m[r][c];
    }
    matrix operator*(matrix x){
        matrix a(n);
        for (int i=1;i<=n;++i){
            for (int j=1;j<=n;++j){
                for (int k=1;k<=n;++k){
                    a(i,j)+=m[i][k]*x(k,j);
                    a(i,j)%=mod;
                }
            }
        }
        return a;
    }
    ll sum(){
        ll tot=0;
        for (int i=1;i<=n;++i){
            for (int j=1;j<=n;++j){
                tot+=m[i][j];
                tot%=mod;
            }
        }
        return tot;
    }
    void print(){
        for (int i=1;i<=n;++i){
            for (int j=1;j<=n;++j){
                printf("%-4d ",m[i][j]);
            }
            printf("\n");
        }
    }
    void set_identity(){
        for (int i=1;i<=n;++i) m[i][i]=1;
    }
    matrix pow(ll x){
        matrix ans(n); ans.set_identity();
        matrix a=*this;
        while (x!=0){
            if (x&1) ans=ans*a;
            x>>=1; a=a*a;
        }
        return ans;
    }
    ll calc(ll k){
        return (m[1][1] * k + m[1][2]) % mod;
    }
};
int in[MN], out[MN], T;
int up[MN][L + 1];
matrix st[MN][L + 1];
ll a[MN], b[MN], prob[MN];
vector<int> adj[MN];
ll fpow(ll b, ll e){
    ll ret = 1;
    while (e){
        if (1 & e) ret = ret * b % mod;
        b = b * b % mod; e >>= 1;
    }
    return ret;
}
ll inv(ll n){ return fpow(n, mod - 2); }

void dfs(int v, int p){
    in[v] = ++T;
    if (v != 1){
        prob[v] = ((a[v] - b[v] + mod) * prob[p] + b[v]) % mod;
    }

    up[v][0] = p;
    st[v][0] = matrix(2);
    st[v][0](1, 1) = (a[v] - b[v] + mod) % mod;
    st[v][0](1, 2) = (b[v]);
    st[v][0](2, 1) = 0;
    st[v][0](2, 2) = 1;
    if (v == 1) st[v][0].set_identity();

    for (int i = 1; i <= L; ++i){
        up[v][i] = up[up[v][i - 1]][i - 1];
        st[v][i] = st[v][i - 1] * st[up[v][i - 1]][i - 1];
    }

    for (int to : adj[v]){
        if (to == p) continue;
        dfs(to, v);
    }
    out[v] = T;
}

bool is_anc(int a, int b){ return in[a] <= in[b] && out[a] >= out[b]; }
int getlca(int a, int b){
    if (is_anc(a, b)) return a;
    if (is_anc(b, a)) return b;
    for (int i = L; i >= 0; --i){
        if (!is_anc(up[a][i], b)) a = up[a][i];
    }
    return up[a][0];
}

matrix path(int v, int p){
    matrix ret = matrix(2);
    ret.set_identity();
    if (v == p) return ret;
    for (int i = L; i >= 0; --i){
        if (!is_anc(up[v][i], p)){
            ret = ret * st[v][i];
            v = up[v][i];
        }
    }
    return ret * st[v][0];
}

void solve(){
    int N, Q; cin >> N >> Q;
    for (int i = 1; i <= N; ++i){
        ms(up[i], 0);
        in[i] = out[i] = 0;
        for (int j = 0; j <= L; ++j) st[i][j] = matrix(0);
        adj[i].clear();
        prob[i] = 0;
    }
    T = 0;

    int K; cin >> K;
    prob[1] = K * inv(1e6) % mod;
    for (int i = 2; i <= N; ++i){
        int par, on, off; cin >> par >> on >> off;
        adj[par].push_back(i);
        a[i] = on * inv(1e6) % mod;
        b[i] = off * inv(1e6) % mod;
    }

    dfs(1, 1);
    while (Q--){
        int u, v; cin >> u >> v;
        int lca = getlca(u, v);
        matrix mu = path(u, lca), mv = path(v, lca);
        ll ans = prob[lca] * (mu.calc(1) * mv.calc(1) % mod) % mod;
        ans = (ans + (1 - prob[lca] + mod) % mod * (mu.calc(0) * mv.calc(0) % mod)) % mod;
        cout << ans << " ";
    }
    cout << '\n';

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    for (int i = 1; i <= t; ++i){
        cout << "Case #" << i << ": ";
        solve();
    }
}
