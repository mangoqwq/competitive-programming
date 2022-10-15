#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    for (int _=1;_<=t;++_){
        cout << "Case #" << _ << ": ";
        int n, q; cin >> n >> q;
        string best; int ans=0;
        for (int i=1;i<=n;++i){
            string curr; int val;
            cin >> curr >> val;
            if (val>ans){
                ans=val;
                best=curr;
            }
            if (q-val>ans){
                ans=q-val;
                best="";
                for (char j:curr) best+=(j=='F'?'T':'F');
            }
        }
        cout << best << " " << ans << "/1" << '\n';
    }
}