#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=1e5+1;

ll arr[MAXN],pre[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,q; cin >> n >> q;
    for (int i=1;i<=n;++i) cin >> arr[i];
    for (int i=1;i<=q;++i){
        int l,r; cin >> l >> r;
        pre[l]++; pre[r+1]--;
    }
    for (int i=1;i<=n;++i) pre[i]=pre[i-1]+pre[i];
    sort(pre+1,pre+1+n); sort(arr+1,arr+1+n); reverse(arr+1,arr+1+n);
    ll tot=0;
    for (int i=1;i<=n;++i) tot+=arr[i]*pre[i];
    cout << tot << '\n';
}