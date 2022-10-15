#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=501;

ll cnt[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    for (int _=1;_<=t;++_){
        cout << "Case #" << _ << ": ";
        ms(cnt,0);
        int n; cin >> n;
        ll tot=0;
        for (int i=1;i<=n;++i){
            ll p; cin >> p;
            cin >> cnt[p];
            tot+=cnt[p]*p;
        }
        ll ans=0;
        for (ll i=tot;i>=max(tot-4000,1LL);--i){
            map<ll,ll> m;
            ll curr=i, sum=0;
            bool can=1;
            for (ll j=2;j<=500;++j){
                while (curr%j==0) m[j]++, curr/=j, sum+=j;
            }
            can&=curr==1;
            can&=sum+i==tot;
            for (auto [p,c]:m) can&=c<=cnt[p];
            if (can){ ans=i; break; }
        }
        cout << ans << '\n';
    }
}