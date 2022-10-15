#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=5001;

ll arr[2*MAXN], tot[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    for (int i=1;i<=n;++i){
        cin >> arr[i];
        arr[i+n]=arr[i];
    }
    for (int i=1;i<=n;++i){
        for (int j=0;j<n;++j){
            tot[i]+=arr[i+j];
        }
    }
    
}