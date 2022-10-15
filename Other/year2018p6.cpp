#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)]
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=5e4+1,len=500,L=16;

struct Query{
    int l,r,c,lca,id;
    bool operator<(const Query &x) const{
        if (l/len!=x.l/len) return l<x.l;
        return (l/len)%2?(r<x.r):(r>x.r);
    }
} qs[MAXN];
struct Edge{ int n,nxt; } adj[2*MAXN];
int n,q,ans[MAXN],head[MAXN],Idx;
bitset<MAXN> seen;
int in[MAXN],out[MAXN],up[MAXN][L+1],t[2*MAXN],T;
multiset<int> s,diff;
int arr[MAXN];

void dfs(int curr, int prev){
    in[curr]=++T; t[T]=curr;
    up[curr][0]=prev;
    for (int i=1;i<=L;++i) up[curr][i]=up[up[curr][i-1]][i-1];
    for (int x=head[curr];x!=0;x=adj[x].nxt){
        if (adj[x].n==prev) continue;
        dfs(adj[x].n,curr);    
    }
    out[curr]=++T; t[T]=curr;
}

bool Is(int a, int b){ return in[a]<=in[b]&&out[a]>=out[b]; }

int Lca(int a, int b){
    if (Is(a,b)) return a;
    if (Is(b,a)) return b; 
    for (int i=L;i>=0;--i){
        if (!Is(up[a][i],b)) a=up[a][i];
    }
    return up[a][0];
}

inline void Insert(const int &x){
    if (s.empty()){ s.insert(x); return; }
    s.insert(x);
    auto ptr=s.lower_bound(x);
    auto l=ptr,r=ptr; l--, r++;
    if (r!=s.end()&&ptr!=s.begin()) diff.erase(diff.find(abs(*r-*l)));
    if (r!=s.end()) diff.insert(abs(*r-x));
    if (ptr!=s.begin()) diff.insert(abs(*l-x));
}

inline void Remove(const int &x){
    auto ptr=s.lower_bound(x);
    auto l=ptr,r=ptr; l--; r++;
    if (ptr!=s.begin()&&r!=s.end()) diff.insert(abs(*r-*l));
    if (r!=s.end()) diff.erase(diff.find(abs(*r-x)));
    if (ptr!=s.begin()) diff.erase(diff.find(abs(*l-x)));
    s.erase(ptr);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
    for (int i=1;i<=n;++i) cin >> arr[i];
    for (int i=1,a,b;i<=n-1;++i){
        cin >> a >> b;
        adj[++Idx]={b,head[a]}, head[a]=Idx;
        adj[++Idx]={a,head[b]}, head[b]=Idx;
    }
    dfs(1,1);
    for (int i=1,a,b;i<=q;++i){
        cin >> a >> b;
        if (in[b]<in[a]) swap(a,b); 
        int lca=Lca(a,b);
        if (lca==a) qs[i]={in[a],in[b],0,lca,i};
        if (lca!=a) qs[i]={out[a],in[b],1,lca,i};
    }
    sort(qs+1,qs+1+q);
    int pl=1,pr=0;
    for (int i=1;i<=q;++i){
        Query x=qs[i];
        while (pr<x.r){
            pr++;
            seen.flip(t[pr]);
            if (seen[t[pr]]) Insert(arr[t[pr]]);
            else Remove(arr[t[pr]]);
        }
        while (pl>x.l){
            pl--;
            seen.flip(t[pl]);
            if (seen[t[pl]]) Insert(arr[t[pl]]);
            else Remove(arr[t[pl]]);
        }
        while (pr>x.r){
            seen.flip(t[pr]);
            if (seen[t[pr]]) Insert(arr[t[pr]]);
            else Remove(arr[t[pr]]);
            pr--;
        } 
        while (pl<x.l){
            seen.flip(t[pl]);
            if (seen[t[pl]]) Insert(arr[t[pl]]);
            else Remove(arr[t[pl]]);
            pl++;
        }
        if (x.c) Insert(arr[x.lca]);
        ans[x.id]=*diff.begin();
        if (x.c) Remove(arr[x.lca]);
    }
    for (int i=1;i<=q;++i) cout << ans[i] << '\n';
}