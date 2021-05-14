#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    string s; cin >> s; s=" "+s;
    int q; cin >> q;
    bool rev=0;
    while (q--){
        int t, a, b; cin >> t >> a >> b;
        if (t==1){
            if (rev){
                a=a<=n?a+n:a-n;
                b=b<=n?b+n:b-n;
            }
            swap(s[a],s[b]);
        }
        else rev^=1;
    }
    if (!rev) cout << s.substr(1,n) << s.substr(1+n) << '\n';
    else cout << s.substr(1+n) << s.substr(1,n) << '\n';
}