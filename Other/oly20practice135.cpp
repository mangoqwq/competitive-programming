#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=1e5+1;

bool vis[MAXN];
int arr[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    iota(arr+1,arr+1+n,1);
    for (int i=1;i<=m;++i){
        int a, b; cin >> a >> b;
        swap(arr[a],arr[b]);
    }
    vector<int> len;
    for (int i=1;i<=n;++i){
        if (vis[i]) continue;
        for (int j=i,cnt=0;;j=arr[j],cnt++){
            if (vis[j]){ len.push_back(cnt); break; }
            vis[j]=1;
        }
    }
    ll ans=1;
    for (ll x:len) ans=lcm(ans,x);
    cout << ans << '\n';
}