#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=201;

int a[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        for (int i=1;i<=n;++i) cin >> a[i];
        sort(a+1,a+1+n);
        bool same=(n%2==0)&&(a[n]==a[1]);
        if (same) cout << -1 << '\n';
        else{
            if (n%2==0) swap(a[n-1],a[2]);
            for (int i=1;i<=n;++i) cout << a[i] << (i==n?'\n':' ');
        }
    }
}