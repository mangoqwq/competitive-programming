#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=5001, MAXW=2e5+1;

int a[MAXN];
bool vis[4*MAXW];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int w, n; cin >> w >> n;
    for (int i=1;i<=n;++i) cin >> a[i];
    for (int i=1;i<=n;++i){
        for (int j=i+1;j<=n;++j){
            int x=w-a[i]-a[j];
            if (x>=0&&vis[x]) return cout << "YES" << '\n', 0;
        }
        for (int j=i-1;j>=1;--j) vis[a[i]+a[j]]=1;
    }
    cout << "NO" << '\n';
}