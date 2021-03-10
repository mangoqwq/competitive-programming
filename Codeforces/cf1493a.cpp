#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n, k; cin >> n >> k;
        vector<int> ans;
        for (int i=k-1;i+i>=k;--i) ans.push_back(i);
        for (int i=k+1;i<=n;++i) ans.push_back(i);
        cout << ans.size() << '\n';
        for (int x:ans) cout << x << " ";
        cout << '\n';
    }
}