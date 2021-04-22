#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=2e5+1;

int lg2(ll a){ return 63-__builtin_clzll(a); }
ll p2(int a){ return (1LL<<a); }
unordered_map<ll,int> m[MAXN], curr;
struct Query{ ll r; int id; };
vector<Query> qs[MAXN];
struct Node{
    int id1, id2, nxt[2];
} t[64*MAXN];
int T, T1, T2, ans[MAXN];

void solve(int v){
    for (auto [a,b]:m[t[v].id1]){
        curr[a]+=b;
    }
    for (int i=0;i<=1;++i){
        int to=t[v].nxt[i];
        if (!to) continue;
        solve(to);
    }
    for (auto [r,id]:qs[t[v].id2]){
        for (int i=0;p2(i)<=r;++i){
            ll msk=((p2(i+1)-1)&r)|p2(i);
            if (curr.count(msk)) ans[id]+=curr[msk];
        }
    }
    for (auto [a,b]:m[t[v].id1]){
        curr[a]-=b;
        if (curr[a]==0) curr.erase(a);
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    for (int _=1;_<=n;++_){
        ll x, y, v; cin >> x >> y >> v;
        int p=0;
        while (y!=1){
            bool b=1&y; y>>=1;
            if (!t[p].nxt[b]) t[p].nxt[b]=++T;
            p=t[p].nxt[b];
        }
        if (!t[p].id1) t[p].id1=++T1;
        m[t[p].id1][x]+=v;
    }
    for (int i=1;i<=q;++i){
        ll r, c; cin >> r >> c;
        int p=0, place=0;
        while (c){
            place=p;
            bool b=1&c; c>>=1;
            if (!t[p].nxt[b]) break;
            p=t[p].nxt[b];
        }
        if (!t[place].id2) t[place].id2=++T2;
        qs[t[place].id2].push_back({r,i});
    }
    solve(0);
    for (int i=1;i<=q;++i) cout << ans[i] << '\n';
}