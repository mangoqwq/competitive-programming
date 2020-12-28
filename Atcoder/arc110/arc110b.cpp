#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    ll lim=1e10;
    string t; cin >> t;
    if (t=="1") return cout << 2*lim << '\n', 0;
    string p="110";
    ll cnt=lim+1;
    for (int i=0;i<3;++i){
        ll curr=1, idx=i;
        for (char x:t){
            if (idx==3) curr++, idx=0;
            if (x!=p[idx++]) curr=lim+1;
        }
        cnt=min(cnt,curr);
    }
    cout << lim-cnt+1 << '\n';
}