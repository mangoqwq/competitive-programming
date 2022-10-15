#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int k, d; cin >> k >> d;
    int zero=0, mn=10;
    for (int i=1;i<=d;++i){
        int x; cin >> x;
        if (x==0) zero=1;
        else mn=min(mn,x);
    }
    if (zero){
        if (mn==10) cout << -1 << '\n';
        else{
            cout << mn;
            for (int i=1;i<=k-2;++i) cout << 0;
            if (k!=1) cout << mn;
            cout << '\n';
        }
    }
    else{
        for (int i=1;i<=k;++i) cout << mn;
        cout << '\n';
    }
}
