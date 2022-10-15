#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=5e5+1;

ll power(ll b, ll e){
    ll ret=1;
    for (int i=1;i<=e;++i) ret*=b;
    return ret;
}
ll n, p;
struct Person{
    ll points; string name;
    bool operator<(const Person&x) const{
        return points<x.points;
    }
} a[MAXN];
map<string,ll> mp;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> p;
    for (int i=1;i<=n;++i){
        string name; cin >> name;
        ll m, cs, e; cin >> m >> cs >> e;
        mp[name]=(ll)(4*sqrtl(m)+3*power(cs,p)-4*e);
    }
    n=0;
    for (auto [x,y]:mp){
        ++n;
        a[n].points=y;
        a[n].name=x;
    }
    sort(a+1,a+1+n);
    cout << a[n].name << " " << (ll)a[n].points << '\n';
    cout << a[1].name << " " << (ll)a[1].points << '\n';
}