#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define f first
#define s second
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

bool cmp(pii a, pii b){
    return a.s<b.s;
}

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n; cin >> n;
    vector<pii> arr;
    for (int i=0,a,b;i<n;++i){
        cin >> a >> b;
        arr.push_back({a,b});
    }
    sort(arr.begin(),arr.end(),cmp);
    int tot=0,ans=0x3f3f3f3f;
    for (pii x:arr){
        tot+=x.f;
        ans=min(ans,x.s-tot);
    }
    if (ans<0) cout << -1 << '\n';
    else cout << ans << '\n';
}