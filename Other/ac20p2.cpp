#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e5+1;

ll cnt[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    for (int i=1;i<=n;++i){
        int x; cin >> x;
        cnt[x]++;
    }
    while (q--){
        int op, x; cin >> op >> x;
        if (op==1){
            int mid=x/2;
            cnt[mid]+=cnt[x];
            cnt[x-mid]+=cnt[x];
            cnt[x]=0;
        }
        else{
            cout << cnt[x] << '\n';
        }
    }
}