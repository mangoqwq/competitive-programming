#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=20;

int n;
int a[MAXN], curr[MAXN];
bool vis[MAXN];
ll ans;

void dfs(int i){
    if (i==n+1) return void(ans++);
    int l=0, r=n+1;
    for (int p=i-1;p>=0;--p){
        if (a[p]==a[i]-1){
            r=curr[p];
            break;
        }
        l=max(l,curr[p]);
    }
    for (int to=l+1;to<r;++to){
        if (vis[to]) continue;
        vis[to]=1;
        curr[i]=to;
        dfs(i+1);
        curr[i]=0;
        vis[to]=0;
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    for (int _=1;_<=t;++_){
        ans=0;
        cout << "Case #" << _ << ": ";
        ms(a,0), ms(vis,0), ms(curr,0);
        cin >> n;
        curr[0]=n+1;
        for (int i=1;i<=n;++i) cin >> a[i];
        dfs(1);
        cout << ans%mod << '\n';
    }
}