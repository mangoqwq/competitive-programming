#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=1e7+1;

int arr[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i){
        int l,r; cin >> l >> r;
        arr[l]++; arr[r]--;
    }
    int ans=0;
    for (int i=1;i<MAXN;++i) {arr[i]+=arr[i-1]; ans=max(ans,arr[i]);}
    cout << ans << '\n';
}