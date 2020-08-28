#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const ll mod=1e9+7;
vector<ll> powers;
set<int> s;


int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    int n,q; cin >> n >> q;
    powers.resize(n); powers[0]=1;
    for (int i=1;i<n;++i){
        powers[i]=(powers[i-1]*2)%mod;
    }
    reverse(powers.begin(),powers.end());
    char a;
    ll ans=0;
    for (int i=0;i<n;++i){
        cin >> a;
        if (a=='0') s.insert(i+1);
        else{
            ans+=powers[i];
            ans%=mod;
        }
    }
    int l,r,index;
    while (q--){
        cin >> l >> r;
        index=*s.lower_bound(l);
        while (index<=r&&index>=l&&!s.empty()){
            ans+=powers[index-1];
            ans%=mod;
            s.erase(index);
            index=*s.lower_bound(l);
            //cout << index << '\n';
        }
        cout << ans << '\n';
    }
}