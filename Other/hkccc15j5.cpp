#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
#define f first
#define s second
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=1e3+1;

vector<int> graph[MAXN];
int vis[MAXN], p[MAXN], ans[MAXN];
bool dp[MAXN][MAXN];

void bfs(int node, int &val, int x, int root){
    p[node]=root;
    val+=x;
    vis[node]=x;
    for (int y:graph[node]){
        if (vis[node]==vis[y]){ val=-0x3f3f3f3f; return; }
        if (vis[y]==-1) bfs(y,val,!x,root);
    }
}

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for (int i=0,a,b;i<m;++i){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<pii> arr;
    int temp,index=1;
    for (int i=1;i<=n;++i){
        if (vis[i]) continue;
        temp=0;
        bfs(i,temp,0,i);
        if (temp<0){ cout << -1 << '\n'; return 0; }
        else if (temp==0) ans[i]=1;
        else arr.push_back({temp,i});
    }
    dp[0][0]=1;
    for (pii x:arr){
        for (int i=1000;i>=x.f;--i) dp[index][i-x.f]=dp[index-1][i-x.f]|dp[index-1][i];
        index++;
    }
    



}