#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=1e7+1;


bool prime(ll x){
    if (x==1) return 0;
    for (ll i=2;i*i<=x;++i){
        if (x%i==0) return 0;
    }
    return 1;
}

bool dive(ll x, ll prev, vector<ll> &ans){
    ans.push_back(x);
    if (x==2) return 1;
    if (prime(x-2)){ dive(2,x,ans); return 1; }
    bool temp;
    if (prime(x+2)) temp=dive(x+2,x,ans);
    if (temp) return 1;
    if (prime(x-2)) temp=dive(x-2,x,ans);
    if (temp) return 1;
    ans.pop_back();
    return 0;

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll a, b; cin >> a >> b;
    vector<ll> ans1, ans2;
    bool temp=dive(a,a,ans1);
    if (!temp){ cout << -1 << '\n'; return 0; }
    temp=dive(b,b,ans2);
    if(!temp){ cout << -1 << '\n'; return 0; }
    cout << ans1.size()+ans2.size()-1 << '\n';
    for (ll x:ans1) cout << x << " ";
    ans2.pop_back(); reverse(ans2.begin(),ans2.end());
    for (ll x:ans2) cout << x << " ";
    cout << '\n';
}