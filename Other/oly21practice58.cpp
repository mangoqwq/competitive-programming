#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=2e5+1;

int a[MAXN], vis[MAXN], T;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; ll k; cin >> n >> k;
    for (int i=1;i<=n;++i) cin >> a[i];
    int i=1;
    while (k--){
        T++;
        if (vis[i]){
            k%=(T-vis[i]);
        }
        vis[i]=T;
        i=a[i];
    }
    cout << i << '\n';
}