#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=0;

set<int> s;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int g, p; cin >> g >> p;
    for (int i=1;i<=g;++i) s.insert(i);
    int tot=p;
    for (int i=1,a;i<=p;++i){
        cin >> a;
        auto it=s.upper_bound(a);
        if (it==s.begin()){ tot=i-1; break; }
        s.erase(--it);
    }
    cout << tot << '\n';
}