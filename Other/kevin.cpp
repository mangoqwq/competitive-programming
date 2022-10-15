#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=1e5+1, L=17;

struct Edge{int n,prev; ll d;} graph[MAXN*2];
int head[MAXN],idx;
int up[L+1][MAXN];
int in[MAXN],out[MAXN],T;
int dist[MAXN]; ll uph[MAXN], downh[MAXN], powers[MAXN], inv[MAXN];

bool is_anc(int a, int b){ return in[a]<=in[b] && out[a]>=out[b]; }

ll uphash(int a, int b){ // a is anc of b
    return (uph[b]-(uph[a]*powers[dist[b]-dist[a]])%mod+mod)%mod;
}

ll downhash(int a, int b){ // b is anc of a
    return (((downh[a]-downh[b]+mod)%mod)*inv[dist[b]-1])%mod;
}

void dfs(int curr, int prev, ll upd, ll downd){
    in[curr]=++T;
    dist[curr]=dist[prev]+1; 
    uph[curr]=upd; downh[curr]=downd; 
    up[0][curr]=prev;
    for (int i=1,temp;i<=L;++i) up[i][curr]=up[i-1][up[i-1][curr]];
    for (int i=head[curr];i>=0;i=graph[i].prev){
        if (graph[i].n==prev) continue;
        dfs(graph[i].n,curr,(upd*seed+graph[i].d)%mod,(downd+graph[i].d*powers[dist[curr]-1])%mod);
    }
    out[curr]=T;
}

ll query(int a, int b){
    if (is_anc(a,b)) return uphash(a,b);
    if (is_anc(b,a)) return downhash(a,b);
    int temp=a;
    for (int i=L;i>=0;--i){
        if (!is_anc(up[i][a],b)) a=up[i][a];
    }
    int lca=up[0][a]; a=temp;
    return ((downhash(a,lca)*powers[dist[a]-dist[lca]])%mod+uphash(lca,b))%mod;
}

int main(){
    //cin.tie(0)->sync_with_stdio(0);
    int n,q; cin >> n >> q; ms(head,-1);
    powers[0]=1; inv[0]=1;
    for (int i=1;i<MAXN;++i){
        powers[i]=(powers[i-1]*seed)%mod;
        inv[i]=(inv[i-1]*190839696)%mod;
    }
    for (int i=0,a,b,c;i<n-1;++i){
        cin >> a >> b >> c;
        graph[idx]={a,head[b],c}, head[b]=idx++;
        graph[idx]={b,head[a],c}, head[a]=idx++;
    }
    dfs(1,1,0,0);
    for (int i=0,a,b,c,d;i<q;++i){
        cin >> a >> b >> c >> d;
        cout << (query(a,b)==query(c,d)?'T':'F') << '\n';
    }
    // for (int i=1;i<=n;++i){
    //     for (int k=1;k<=n;++k){
    //         cout << i << "->" << k << " " << query(i,k) << '\n';
    //     }
    // }
}