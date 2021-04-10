#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=2e5+1;

ll a[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n; cin >> n; n+=2;
        multiset<ll> s;
        ll tot=0;
        for (int i=1;i<=n;++i){
            cin >> a[i]; s.insert(a[i]);
            tot+=a[i];
        }
        int idx=-1;
        for (int i=1;i<=n;++i){
            tot-=a[i], s.erase(s.find(a[i]));
            if (tot%2==0&&s.count(tot/2)) idx=i;
            tot+=a[i], s.insert(a[i]);
        }
        if (idx==-1) cout << -1 << '\n';
        else{
            for (int i=1;i<=n;++i){
                if (i==idx) continue;
                if (a[i]==(tot-a[idx])/2){ tot=LLONG_MAX; continue; }
                cout << a[i] << " ";
            }
            cout << '\n';
        }
    }
}