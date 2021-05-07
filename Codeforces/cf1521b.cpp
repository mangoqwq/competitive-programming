#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e5+1;

int a[MAXN];
struct Answer{ int i, j, x, y; };

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        vector<Answer> ans;
        for (int i=1;i<=n;++i) cin >> a[i];
        int mn=1;
        for (int i=2;i<=n;++i){
            if (a[i]<a[mn]) mn=i;
        }
        for (int i=mn+1;i<=n;++i){
            ans.push_back({mn,i,a[mn],a[mn]+(i-mn)%2});
        }
        for (int i=mn-1;i>=1;--i){
            ans.push_back({mn,i,a[mn],a[mn]+(mn-i)%2});
        }
        cout << ans.size() << '\n';
        for (auto [a,b,c,d]:ans) cout << a << " " << b << " " << c << " " << d << '\n';
    }
}