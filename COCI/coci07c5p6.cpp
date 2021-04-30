#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int seed=31;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=3e4+2;

struct Item{
    int hsh, idx;
    bool operator<(const Item &x) const{ return hsh<x.hsh; }
    bool operator<(const int &x) const{ return hsh<x; }
} hshs[MAXN];
int h[MAXN*30];
struct Edge{ char c; int idx, nxt; } trie[MAXN*30];
int val[MAXN*30], T, T1;
string ns[MAXN], qs[MAXN];
int idx[MAXN], ord[MAXN], ans[MAXN];

int get_hash(string s){
    ll ret=0;
    for (char x:s) ret=(ret*seed+x)%mod;
    return ret;
}

void ins(string s){
    int p=0;
    for (char x:s){
        int nxt=0;
        for (int i=h[p];i;i=trie[i].nxt){
            if (trie[i].c==x) nxt=trie[i].idx;
        }
        if (nxt==0){
            trie[++T1]={x,++T,h[p]}, h[p]=T1;
            nxt=T;
        }
        p=nxt;
        val[p]++;
    }
}

int qry(string s){
    int ret=0, p=0;
    for (char x:s){
        int nxt=0;
        for (int i=h[p];i;i=trie[i].nxt){
            if (trie[i].c==x) nxt=trie[i].idx;
        }
        if (nxt==0) break;
        p=nxt;
        ret+=val[p];
    }
    return ret;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i){
        cin >> ns[i];
        hshs[i]={get_hash(ns[i]),i};
    }
    hshs[n+1]={mod,n};
    sort(hshs+1,hshs+2+n);
    int q; cin >> q;
    for (int i=1;i<=q;++i){
        idx[i]=i;
        cin >> qs[i];
        int hsh=get_hash(qs[i]);
        auto [uwu,owo]=*lower_bound(hshs+1,hshs+1+n,hsh);
        if (uwu==hsh) ord[i]=owo;
        else ord[i]=n;
    }
    sort(idx+1,idx+1+q,[](const int &x, const int &y){ return ord[x]<ord[y]; });
    int poi=0;
    for (int j=1;j<=q;++j){
        int i=idx[j];
        while (poi<ord[i]) ins(ns[++poi]);
        ans[i]=qry(qs[i])+ord[i];
    }
    for (int i=1;i<=q;++i) cout << ans[i] << '\n';
}