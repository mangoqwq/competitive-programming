#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
#define mid ((l+r)>>1)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e6+1;

int k, n;
struct Function{
    ll c; double d;
    double operator()(ll x){
        if (x<c) return d;
        return pow(sqrt(x-c),k)+d;
    }
};
struct Node{
    Node *lc=0, *rc=0;
    Function f={-1,-1e12};
    void extendl(){ if (!lc) lc=new Node(); }
    void extendr(){ if (!rc) rc=new Node(); }
    void ins(Function x, int l=1, int r=n){
        bool lo=x(l)>f(l);
        bool mi=x(mid)>f(mid);
        if (mi) swap(f,x);
        if (l==r||(!lc&&!rc&&f.c==-1)) return;
        if (lo!=mi) extendl(), lc->ins(x,l,mid);
        else extendr(), rc->ins(x,mid+1,r);
    }
    double qry(int i, int l=1, int r=n){
        if (l==r||(!lc&&!rc)) return f(i);
        if (i<=mid) return extendl(), max(f(i),lc->qry(i,l,mid));
        else return extendr(), max(f(i),rc->qry(i,mid+1,r));
    }
} *lct[MAXN];
int c[MAXN]; double dp[MAXN];
vector<Function> uwu[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> k >> n;
    for (int i=1;i<=n;++i){
        int x; cin >> x;
        c[x]++;
        if (!lct[x]) lct[x]=new Node();
        lct[x]->ins({c[x]-1,dp[i-1]});
        dp[i]=lct[x]->qry(c[x]);
    }
    cout << fixed << setprecision(14) << dp[n] << '\n';
}