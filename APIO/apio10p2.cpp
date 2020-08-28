#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
#define f first
#define s second
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=1e5+1;

struct Node{
    int val, n;
    bool operator<(const Node &b) const { return val<b.val; }
};
vector<int> graph[MAXN];
set<int> used[MAXN];
pii dp[MAXN];

void upd(pair<Node,Node> &a, Node b){
    if (b.val>a.f.val) a.s=a.f,a.f=b;
    else if (b.val>a.s.val) a.s=b;
}

int solve(int node, int prev, Node &ans){
    pair<Node,Node> uwu={{0,-1},{0,-1}};
    for (int x:graph[node]){
        if (x==prev) continue;
        upd(uwu,{solve(x,node,ans)+(used[node].count(x)?-1:1),x});
    }
    dp[node]={uwu.f.n,uwu.s.n};
    ans=max(ans,{max(uwu.f.val+uwu.s.val,uwu.f.val),node});
    return uwu.f.val;
}

void build(int node, int prev){
    if (node==-1) return;
    used[node].insert(dp[node].f);
    if (dp[node].f!=prev) build(dp[node].f,node);
}


int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n,k; scan(n); scan(k);
    for (int i=1,a,b;i<n;++i){
        scan(a); scan(b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int ans=2*(n-1);
    Node uwu={0,0};
    solve(1,1,uwu);
    ans+=-uwu.val+1;
    if (k==2){
        build(dp[uwu.n].f,dp[uwu.n].f);
        build(dp[uwu.n].s,dp[uwu.n].s);
        used[uwu.n].insert(dp[uwu.n].f);
        used[uwu.n].insert(dp[uwu.n].s);
        uwu={0,0};
        solve(1,1,uwu);
        ans+=-uwu.val+1;
    }
    cout << ans << '\n';
}