#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 5e5 + 1;

struct Fenwick{
    int a[MN];
    void ins(int i, int v){
        for (; i < MN; i += i & -i) a[i] += v;
    }
    int qry(int i){
        int ret = 0;
        for (; i; i -= i & -i) ret += a[i];
        return ret;
    }
    int qry(int l, int r){ return qry(r) - qry(l - 1); }
    void reset(){ ms(a, 0); }
} bit;

ll fpow(ll b, ll e){
    ll ret = 1;
    while (e){
        if (1 & e) ret = ret * b % mod;
        b = b * b % mod, e >>= 1;
    }
    return ret;
}
ll inv(ll n){ return fpow(n, mod - 2); }

int a[MN];
bool seen[MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    ll ans = 0;
    for (int i = 1; i <= N; ++i){
        cin >> a[i];
        if (!a[i]) continue;
        seen[a[i]] = 1;
        ans = (ans + bit.qry(a[i] + 1, N)) % mod;
        bit.ins(a[i], 1);
    }
    bit.reset();
    ll M = 0;
    for (int i = 1; i <= N; ++i){
        if (!seen[i]) bit.ins(i, 1), M++;
    }
    ans = (ans + M * (M - 1) % mod * inv(4)) % mod;
    int bad = 0;
    for (int i = 1; i <= N; ++i){
        if (a[i] == 0) bad++;
        else{
            ans = (ans + bad * (bit.qry(a[i] + 1, N) * inv(M) % mod)) % mod;
        }
    }
    bad = 0;
    for (int i = N; i >= 1; --i){
        if (a[i] == 0) bad++;
        else{
            ans = (ans + bad * (bit.qry(1, a[i] - 1) * inv(M) % mod)) % mod;
        }
    }
    cout << ans << '\n';
}
