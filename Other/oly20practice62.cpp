#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

ll arr[41];

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n; ll m; cin >> n >> m;
    int mid=n/2;
    for (int i=0;i<n;++i) cin >> arr[i];
    vector<ll> s1,s2;
    ll temp=0;
    for (int mask=0;mask<(1<<mid);++mask){
        temp=0;
        for (int i=0;i<mid;++i) temp+=arr[i]*(1&(mask>>i));
        s1.push_back(temp);
    }
    for (int mask=0;mask<(1<<(n-mid));++mask){
        temp=0;
        for (int i=mid;i<n;++i) temp+=arr[i]*(1&(mask>>(i-mid)));
        s2.push_back(temp);
    }
    sort(s1.begin(),s1.end()); sort(s2.begin(),s2.end());
    // for (int x:s1) cout << x << " ";
    // cout << '\n';
    // for (int x:s2) cout << x << " ";
    // cout << '\n';
    ll ans=0;
    for (ll x:s1) ans+=upper_bound(s2.begin(),s2.end(),m-x)-s2.begin();
    cout << ans << '\n';
}