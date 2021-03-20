#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=0;

map<ll,int> cntr, cntc;
vector<ll> r, c;
vector<pair<ll,ll>> ans;

void ins(ll x, ll y){
    ans.push_back({x,y});
    cntr[x]++, cntc[y]++;
    if (cntr[x]%2) r.push_back(x);
    if (cntc[y]%2) c.push_back(y);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n, m, k; cin >> n >> m >> k;
    for (int i=1;i<=k;++i){
        ll x, y; cin >> x >> y;
        cntr[x]++, cntc[y]++;
    }
    for (auto x:cntr){
        if (x.second%2) r.push_back(x.first);
    }
    for (auto x:cntc){
        if (x.second%2) c.push_back(x.first);
    }
    while (!r.empty()||!c.empty()){
        if (r.empty()){
            ll x=c.back(); c.pop_back();
            ins(1,x);
        }
        else if (c.empty()){
            ll x=r.back(); r.pop_back();
            ins(x,1);
        }
        else{
            ll x=r.back(), y=c.back();
            r.pop_back(); c.pop_back();
            ins(x,y);
        }
    }
    cout << ans.size() << '\n';
    for (auto [a,b]:ans) cout << a << " " << b << '\n';
}