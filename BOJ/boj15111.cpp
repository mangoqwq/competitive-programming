#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
#define mid ((l+r)>>1)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=2e5+1, MT=1e6;

struct Flight{
    ll x, t, c, id;
    bool operator<(const Flight &x) const{ return tie(t,c)<tie(x.t,x.c); }
}; vector<Flight> arr;
struct Function{
    ll c, d;
    ll operator()(ll x){ return (x-c)*(x-c)+d; }
};
struct Node{
    Node *lc=0, *rc=0;
    Function f={inf,inf};
    void extendl(){ if (!lc) lc=new Node(); }
    void extendr(){ if (!rc) rc=new Node(); }
    void ins(Function g, int l=0, int r=MT){
        bool lo=g(l)<f(l);
        bool mi=g(mid)<f(mid);
        if (mi) swap(g,f);
        if (l==r||(!lc&&!rc&&f.c==inf)) return;
        if (lo!=mi) extendl(), lc->ins(g,l,mid);
        else extendr(), rc->ins(g,mid+1,r);
    }
    ll qry(int x, int l=0, int r=MT){
        if (l==r||(!lc&&!rc)) return f(x);
        if (x<=mid) return extendl(), min(f(x),lc->qry(x,l,mid));
        else return extendr(), min(f(x),rc->qry(x,mid+1,r));
    }
} *lct[MAXN];
ll dp[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for (int i=1;i<=m;++i){
        int a, b, s, e; cin >> a >> b >> s >> e;
        assert(s<=e);
        arr.push_back({a,s,0,i});
        arr.push_back({b,e,1,i});
    }
    sort(arr.begin(),arr.end());
    ll ans=LLONG_MAX;
    lct[1]=new Node();
    lct[1]->ins({0,0});
    for (auto [x,t,c,id]:arr){
        if (c==0){
            if (!lct[x]){ dp[id]=-1; continue; }
            dp[id]=lct[x]->qry(t);
        }
        if (c==1){
            if (dp[id]==-1) continue;
            if (!lct[x]) lct[x]=new Node();
            lct[x]->ins({t,dp[id]});
            if (x==n) ans=min(ans,dp[id]);
        }
    }
    cout << ans << '\n';
}