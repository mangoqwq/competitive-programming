#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    multiset<int> s;
    for (int i=1;i<=n;++i){
        int t; cin >> t;
        if (t==-1) t=-inf;
        s.insert(t-i);
    }
    for (int i=1;i<=m;++i){
        int t; cin >> t;
        if (t==-1) continue;
        if (s.count(t-i)) s.erase(s.find(t-i));
    }
    cout << n-s.size();
}
