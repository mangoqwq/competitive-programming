#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=1e5+1;

struct Item{
    int x, idx;
    bool operator<(Item a) const{
        if (a.x==x) return idx<a.idx;
        else return x<a.x;
    }
} arr[MAXN];

void solve(){
    int n, x; cin >> n >> x;
    for (int i=1,a;i<=n;++i){
        cin >> a;
        arr[i]={(a-1)/x,i};
    }
    sort(arr+1,arr+1+n);
    for (int i=1;i<=n;++i) cout << arr[i].idx << " ";
    cout << '\n';
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    for (int i=1;i<=t;++i){
        cout << "Case #" << i << ": ";
        solve();
    }
}