#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

map<string,priority_queue<pii,vector<pii>,greater<pii>>> m;

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        m.clear();
        int n; cin >> n;
        int mm,b,c; string a;
        for (int i=0;i<n;++i){
            cin >> mm;
            for (int k=0;k<mm;++k){
                cin >> a >> b >> c;
                m[a].push({b,c});
            }
        }
        int q; cin >> q;
        ll ans=0;
        while (q--){
            cin >> a >> b;
            while (b>m[a].top().second){
                ans+=m[a].top().first*m[a].top().second;
                b-=m[a].top().second;
                m[a].pop();
            }
            ans+=b*m[a].top().first;
        }
        cout << ans << '\n';
    }
}