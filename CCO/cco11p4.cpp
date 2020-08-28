#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=1e5+1;

int arr[MAXN];

void solve(){
    int n; cin >> n;
    for (int i=1;i<=n;++i) cin >> arr[i];
    map<int,int> m; m[0]=1;
    for (int i=1;i<=n;++i){
        auto idx=(m.lower_bound(arr[i]));
        if (idx==m.begin()) { cout << "NO" << '\n'; return; }
        idx--;
        m[arr[i]]=2;
        m[idx->first]--;
        if (m[idx->first]==0) m.erase(idx->first);
    }
    cout << "YES" << '\n';
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    solve();
}