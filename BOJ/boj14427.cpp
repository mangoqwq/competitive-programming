#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e5+1;

int a[MAXN];
set<pair<int,int>> s;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i){
        cin >> a[i];
        s.insert({a[i],i});
    }
    int q; cin >> q;
    while (q--){
        int op; cin >> op;
        if (op==1){
            int i, v; cin >> i >> v;
            s.erase({a[i],i});
            a[i]=v;
            s.insert({a[i],i});
        }
        if (op==2){
            cout << s.begin()->second << '\n';
        }
    }
}