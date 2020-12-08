#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
#define f first
#define s second
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=1e5+1;

map<ll,int> cnt;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll m, n; cin >> m >> n;
    for (int i=1;i<=n;++i){
        ll a; cin >> a;
        cnt[a]++;
    }
    cnt[0]=0;
    while (true){
        auto it=--cnt.end();
        auto it2=--(--cnt.end());
        if (it->s*(it->f-it2->f)<m){
            m-=it->s*(it->f-it2->f);
            cnt[it2->f]+=it->s;
            cnt.erase(it);
        }
        else{
            int a=it->f, b=it->s;
            cnt.erase(it);
            cnt[a-m/b]+=b-m%b;
            cnt[a-m/b-1]+=m%b;
            break;
        }
    }
    ll tot=0;
    for (auto [a,b] : cnt){
        tot+=a*a*b;
    }
    cout << tot << '\n';
}