#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=2e5+1;

int n, arr[MAXN];
unordered_set<int> s;

void solve(){
    s.clear();
    cin >> n;
    for (int i=1;i<=n;++i) cin >> arr[i], s.insert(arr[i]);
    int best=0, ans=0, curr;
    for (int i=1;i<=n;++i){
        curr=best;
        while (s.count(curr^arr[i])) curr++;
        if (curr>best) best=curr, ans=arr[i];
        else if (curr==best) ans=min(ans,arr[i]);
    }
    cout << best << " " << ans << '\n';
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        solve();
    }
}