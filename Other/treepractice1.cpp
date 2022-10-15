#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=5e5+1;

struct Edge{ int n,d,last; } adj[MAXN*2];
struct Item{ int val,idx; };
int head[MAXN],idx=1,dia,rad=0x3f3f3f3f;
Item dp1[MAXN], dp2[MAXN];

void dfs(int curr, int prev){
    Item &a=dp1[curr],&b=dp2[curr];
    for (int i=head[curr];i!=0;i=adj[i].last){
        Edge x=adj[i];
        if (x.n==prev) continue;
        dfs(x.n,curr);
        if (dp1[x.n].val+x.d>a.val) b=a, a={dp1[x.n].val+x.d,x.n};
        else if (dp1[x.n].val+x.d>b.val) b={dp1[x.n].val+x.d,x.n};
        else if (dp2[x.n].val+x.d>b.val) b={dp2[x.n].val+x.d,x.n};
    }
    //cout << curr << " " << a.val << " " << b.val << '\n';
    dia=max(dia,a.val+b.val);
}

void dfs2(int curr, int prev, int d){
    Item &a=dp1[curr],&b=dp2[curr];
    for (int i=head[curr];i!=0;i=adj[i].last){
        Edge x=adj[i];
        if (x.n==prev) continue;
        if (x.n==a.idx) dfs2(x.n,curr,max(d,b.val)+x.d);
        else dfs2(x.n,curr,max(d,a.val)+x.d);
    }
    //cout << curr << " " << d << " " << a.val << '\n';
    rad=min(rad,max(d,a.val));
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1,a,b,c;i<=n-1;++i){
        cin >> a >> b >> c;
        adj[idx]={b,c,head[a]}, head[a]=idx++;
        adj[idx]={a,c,head[b]}, head[b]=idx++;
    }
    dfs(1,1);
    dfs2(1,1,0);
    cout << dia << '\n' << rad << '\n';
}