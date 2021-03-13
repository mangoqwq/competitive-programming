#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e5+1;

int c[MAXN], h[MAXN], p;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    while (true){
        int n; cin >> n;
        if (n==0) break;
        ll ans=0;
        p=1;
        for (int i=1;i<=n;++i){
            int x, last=i; cin >> x;
            while (p&&h[p]>=x){
                ans=max(ans,1LL*h[p]*(i-c[p]));
                last=c[p--];
            }
            h[++p]=x, c[p]=last;
        }
        while (p) ans=max(ans,1LL*h[p]*(n-c[p--]+1));
        cout << ans << '\n';
    }
}