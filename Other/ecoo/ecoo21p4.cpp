#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=0;

vector<ll> fact;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n; cin >> n; n++;
    for (ll i=2;i*i<=n;++i){
        while (n%i==0) fact.push_back(i), n/=i;
    }
    if (n!=1) fact.push_back(n);
    ll tot=0;
    for (ll x:fact) tot+=x-1;
    ll lim=1e5;
    if (tot>lim) cout << "Sad Chris" << '\n';
    else{
        cout << tot << '\n';
        for (int i=0;i<fact.size();++i){
            for (int j=1;j<=fact[i]-1;++j) cout << i+1 << ((i==fact.size()-1&&j==fact[i]-1)?'\n':' ');
        }
    }
}