#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=0;

set<int> pos[26];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    string s, t; cin >> s >> t;
    for (int i=0;i<n;++i) pos[s[i]-'a'].insert(i);
    ll cnt=0;
    for (int i=0;i<m;++i){
        if (pos[t[i]-'a'].empty()) return cout << -1 << '\n', 0;
        auto x=pos[t[i]-'a'].lower_bound(cnt%n);
        if (x==pos[t[i]-'a'].end()) cnt=(cnt/n)*n+n, i--;
        else cnt+=*x-cnt%n+1;
    }
    cout << cnt << '\n';
}