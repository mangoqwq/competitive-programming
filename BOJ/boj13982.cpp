#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN=2e5+1;
const ll inf=0x3f3f3f3f3f3f3f3f;

ll a[MAXN];
int nxt[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    for (int i=1;i<=n;++i) cin >> a[i];
    stack<pair<ll,int>> s; s.push({0,n+1});
    for (int i=n;i>=1;--i){
        while (s.top().first>=a[i]) s.pop();
        nxt[i]=s.top().second;
        s.push({a[i],i});
    }
    while (q--){
        ll v; cin >> v;
        int l, r; cin >> l >> r;
        for (int i=l;i<=r;i=nxt[i]) v%=a[i];
        cout << v << '\n';
    }
}