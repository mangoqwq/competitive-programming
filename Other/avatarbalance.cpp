#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=10001;

bool vis[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vis[0]=1;
    int tot=0;
    for (int i=1,a;i<=n;++i){
        cin >> a;
        tot+=a;
        for (int j=tot;j>=a;--j) if (vis[j-a]) vis[j]=1;
    }
    ll ans=0;
    for (int i=tot/2;i>=0;--i){
        if (vis[i]){
            cout << tot-2*i << '\n';
            break;
        }
    }
}