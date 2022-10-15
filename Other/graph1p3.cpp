#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=11;

bool graph[MAXN][MAXN], instk[MAXN];
int stk[MAXN], p, cnt[MAXN], n, ans, src;

void dfs(int curr){
    instk[curr]=1;
    stk[p++]=curr;
    for (int i=1;i<=n;++i){
        if (!graph[curr][i]) continue;
        if (i==src){
            if (cnt[p]==0) ans++, cnt[p]=p;
            cnt[p]--;
        }
        if (!instk[i]) dfs(i);
    }
    p--;
    instk[curr]=0;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=1;i<=n;++i){
        for (int j=1;j<=n;++j){
            cin >> graph[i][j];
        }
    }
    for (int i=1;i<=n;++i) src=i, dfs(i);
    cout << ans << '\n';
}