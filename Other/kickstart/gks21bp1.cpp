#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=0;

void solve(){
    int n; cin >> n;
    string s; cin >> s; s=" "+s;
    cout << 1 << " ";
    int curr=1;
    for (int i=2;i<=n;++i){
        if (s[i]>s[i-1]) curr++;
        else curr=1;
        cout << curr << " ";
    }
    cout << '\n';
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    for (int i=1;i<=t;++i){
        cout << "Case #" << i << ": ";
        solve();
    }
}