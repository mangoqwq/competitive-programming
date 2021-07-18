#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    multiset<int> a, b, c;
    for (int i=1;i<=n;++i){
        int x; cin >> x;
        a.insert(x);
    }
    for (int i=1;i<=n;++i){
        int x; cin >> x;
        b.insert(x);
    }
    for (int i=1;i<=n;++i){
        int x; cin >> x;
        c.insert(x);
    }
    int ans=0;
    while (!a.empty()){
        auto pa=a.begin();
        a.erase(pa);
        auto pb=b.upper_bound(*pa);
        if (pb==b.end()) break;
        b.erase(pb);
        auto pc=c.upper_bound(*pb);
        if (pc==c.end()) break;
        c.erase(pc);
        ans++;
    }
    cout << ans << '\n';
}
