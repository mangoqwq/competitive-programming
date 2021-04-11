#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=101;

int ans[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n, k; cin >> n >> k;
        ms(ans,0);
        vector<int> v;
        for (int i=1;i<=n;++i) v.push_back(i);
        for (int i=2;i<n;i+=2){
            if (k) ans[i]=v.back(), v.pop_back(), k--;
        }
        for (int i=1;i<=n;++i){
            if (!ans[i]) ans[i]=v.back(), v.pop_back();
        }
        if (k!=0) cout << -1 << '\n';
        else{
            for (int i=1;i<=n;++i) cout << ans[i] << " ";
            cout << '\n';
        }
    }
}