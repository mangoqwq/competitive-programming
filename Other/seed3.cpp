#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=1e5+1;

int pre[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,k,q; cin >> n >> k >> q;
    for (int i=0,l,r,v;i<q;++i){
        cin >> l >> r >> v;
        pre[l]+=v; pre[r+1]-=v;
    }
    int ans=0,tot=0;
    for (int i=1;i<=n;++i) tot+=pre[i], ans+=tot<k;
    cout << ans << '\n';
}