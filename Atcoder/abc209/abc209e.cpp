#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=2e5+1;

vector<int> radj[MAXN];
int dp[MAXN], deg[MAXN];
string dict[MAXN], pre[MAXN], suf[MAXN];
unordered_map<string,int> id;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i) cin >> dict[i];
    for (int i=1;i<=n;++i){
        pre[i]=dict[i].substr(0,3);
        suf[i]=dict[i].substr(dict[i].size()-3);
        id[pre[i]]=0, id[suf[i]]=0;
    }
    int T=0;
    for (auto &[a,b]:id) b=++T;
    for (int i=1;i<=n;++i){
        int a=id[pre[i]];
        int b=id[suf[i]];
        deg[a]++, radj[b].push_back(a);
    }
    queue<int> q;
    for (int i=1;i<=T;++i){
        if (deg[i]==0) q.push(i), dp[i]=-1;
    }
    while (!q.empty()){
        int v=q.front(); q.pop();
        for (int to:radj[v]){
            if (dp[to]) continue;
            if (dp[v]==-1){
                dp[to]=1;
                q.push(to);
            }
            if (dp[v]==1){
                deg[to]--;
                if (deg[to]==0) dp[to]=-1, q.push(to);
            }
        }
    }
    for (int i=1;i<=n;++i){
        int a=id[suf[i]];
        if (dp[a]==1) cout << "Aoki" << '\n';
        if (dp[a]==0) cout << "Draw" << '\n';
        if (dp[a]==-1) cout << "Takahashi" << '\n';
    }
}