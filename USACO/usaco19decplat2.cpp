#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
#define fi first
#define se second
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=1e5+1;

int n, q;
vector<int> adj[MAXN];
map<int,int> s[MAXN];
int in[MAXN], out[MAXN], T;
ll st[2*MAXN], lz[2*MAXN];

void push(int v, int l, int r){
    if (!lz[v]) return;
    st[v]+=(r-l+1)*lz[v];
    int mid=l+r>>1;
    if (l!=r) lz[v+1]+=lz[v], lz[v+2*(mid-l+1)]+=lz[v];
    lz[v]=0;
}

void upd(int pl, int pr, ll val, int v=1, int l=1, int r=n){
    push(v,l,r);
    if (l>pr||r<pl) return;
    if (l>=pl&&r<=pr) lz[v]+=val, push(v,l,r);
    else{
        int mid=l+r>>1;
        upd(pl,pr,val,v+1,l,mid);
        upd(pl,pr,val,v+2*(mid-l+1),mid+1,r);
        st[v]=st[v+1]+st[v+2*(mid-l+1)];
    }
}

ll get(int pl, int pr, int v=1, int l=1, int r=n){
    push(v,l,r);
    if (l>pr||r<pl) return 0;
    if (l>=pl&&r<=pr) return st[v];
    else{
        int mid=l+r>>1;
        return get(pl,pr,v+1,l,mid)+get(pl,pr,v+2*(mid-l+1),mid+1,r);
    }
}

void dfs(int v, int p){
    in[v]=++T;
    for (int to:adj[v]) if (to!=p) dfs(to,v);
    out[v]=T;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
    for (int i=1,a,b;i<=n-1;++i){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i=1;i<MAXN;++i) s[i][0]=0;
    dfs(1,1);
    int l, r, v, c;
    while (q--){
        int op; cin >> op;
        if (op==1){
            cin >> v >> c;
            l=in[v], r=out[v];
            auto it=s[c].lower_bound(r);
            if (it!=s[c].end()&&it->se<=r) r=it->fi;
            else it--;
            while (it->fi>=l){
                l=min(l,it->se);
                upd(it->se,it->fi,-1);
                s[c].erase(it--);
            }
            upd(l,r,1);
            s[c][r]=l;
        }
        if (op==2){
            cin >> v;
            l=in[v], r=out[v];
            cout << get(l,r) << '\n';
        }
    }
}