#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

struct uwu{
    int l,r,val;
    bool operator<(const uwu &a) const{
        return tie(val,r,l)<tie(a.val,a.r,a.l);
    }
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<int> arr(n+1),inv[n+1];
    for (int i=1;i<=n;++i) cin >> arr[i];
    ll tot=0;
    for (int i=1;i<=n;++i){
        for (int j=i+1;j<=n;++j){
            if (arr[j]<arr[i]) inv[i].push_back(j), tot++;
        }
    }
    cout << tot << '\n';
    for (int i=1;i<=n;++i){
        pii small={0x3f3f3f3f,i};
        for (int x:inv[i]){
            if (arr[x]<=small.first) small={arr[x],x};
        }
        if (small.second==i) continue;
        for (int x:inv[i]){
            if (x==small.second) continue;
            cout << i << " " << x << '\n';
            swap(arr[i],arr[x]);
        }
        swap(arr[i],arr[small.second]);
        cout << i << " " << small.second << '\n';
    }
}