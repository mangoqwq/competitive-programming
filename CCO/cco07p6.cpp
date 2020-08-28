#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=1001;

vector<int> graph[MAXN],span[MAXN],back[MAXN];
bool vis[MAXN];
int depth[MAXN],ans;

void dfs(int curr, int prev, int d){
    vis[curr]=1;
    depth[curr]=d;
    for (int x:graph[curr]){
        if (x==prev) continue;
        if (vis[x]){
            back[curr].push_back(x);
        }
        else{
            span[x].push_back(curr);
            span[curr].push_back(x);
            dfs(x,curr,d+1);
        }
    }
}

int solve(int curr, int prev){
    int cnt=0;
    for (int x:span[curr]){
        if (x==prev) continue;
        cnt+=solve(x,curr);
    }
    for (int x:back[curr]){
        if (depth[x]<depth[curr]) cnt++;
        if (depth[x]>depth[curr]) cnt--;
    }
    if (cnt==0&&curr!=1){ ans++; return 1001; }
    return cnt;

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,m; cin >> n >> m;
    for (int i=1,a,b;i<=m;++i){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1,1,0);
    solve(1,1);
    cout << (ans+1)/2 << '\n';
}