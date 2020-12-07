#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n; cin >> n;
    vector<int> ans, curr;
    for (ll i=1;i*i<=n;++i){
        if ((n-i)%i==0&&(n-i)/i>i) ans.push_back((n-i)/i);
        if (i==1) continue;
        curr.clear();
        ll e=1, x=n;
        while (e*i<=x) e*=i;
        while (e){
            curr.push_back(x/e);
            x%=e; e/=i;
        }
        bool flag=1;
        for (int i=0;i<curr.size();++i) flag&=curr[i]==curr[curr.size()-i-1];
        if (flag) ans.push_back(i);
    }
    sort(ans.begin(),ans.end());
    for (int x:ans) cout << x << '\n';
}