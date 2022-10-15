#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int l,n; cin >> l >> n;
        vector<ll> arr(l+2,0);
        for (int i=1,c,r,d;i<=n;++i){
            cin >> c >> r >> d;
            arr[max(1,c-r)]+=d;
            arr[min(l,c+r)+1]-=d;
        }
        for (int i=1;i<=l;++i) arr[i]+=arr[i-1];
        int q; cin >> q;
        for (int j=1;j<=q;++j){
            ll h; cin >> h;
            for (int i=1;i<=l+1;++i){
                if (i==l+1){ cout << "Bloon leakage\n"; break; }
                h-=arr[i];
                if (h<=0){ cout << i << '\n'; break; }
            }   
        }
    }
}