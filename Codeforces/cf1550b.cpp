#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n, a, b; cin >> n >> a >> b;
        string s; cin >> s;
        int ans=n*a;
        int c0=0, c1=0;
        for (int i=1;i<n;++i){
            if (s[i]!=s[i-1]){
                if (s[i-1]=='0') c0++;
                else c1++;
            }
        }
        if (s[n-1]=='0') c0++;
        else c1++;
        if (b>=0) ans+=n*b;
        else ans+=(min(c0,c1)+1)*b;
        cout << ans << '\n';
    }
}
