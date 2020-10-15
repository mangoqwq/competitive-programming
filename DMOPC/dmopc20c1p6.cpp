#include <bits/stdc++.h>

// Subtask 1

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=3e5+1;
const ll inf=0x3f3f3f3f3f3f3f3f;

ll arr[MAXN];
bool gacha[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    for (int i=1;i<=n;++i) cin >> arr[i];
    int op, l, r, x; ms(gacha,1);
    ll ans, curr;
    while (q--){
        cin >> op >> l >> r;
        if (op==1){
            for (int i=l;i<=r;++i) gacha[i]=1;
        }
        if (op==2){
            for (int i=l;i<=r;++i) gacha[i]=0;
        }
        if (op==3){
            cin >> x;
            for (int i=l;i<=r;++i) arr[i]=x;
        }
        if (op==4||op==5){
            ans=-inf;
            curr=-inf;
            bool one=0;
            for (int i=l;i<=r;++i){
                if (gacha[i]^(op==5)){
                    if (curr==-inf) curr=0;
                    if (one) curr=max(arr[i],curr+arr[i]);
                    else curr+=arr[i], one=1;
                }
                else curr=-inf, one=0;
                ans=max(ans,curr);
            }
            if (ans==-inf) cout << "breaks galore" << '\n';
            else cout << ans << '\n';
        }
    }
}