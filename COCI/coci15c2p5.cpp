#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=1e6+1;

ll arr[MAXN];
vector<ll> c;
set<ll> seen;
int bit[MAXN];

void Insert(int idx){
    if (idx==0) return;
    for (int i=idx;i<MAXN;i+=i&-i) bit[i]++;
}

int Query(int idx){
    int ret=0;
    for (int i=idx;i>0;i-=i&-i) ret+=bit[i];
    return ret;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i) cin >> arr[i];
    ll p, tot=0, ans=0; cin >> p;
    for (int i=1;i<=n;++i){
        arr[i]-=p;
        tot+=arr[i];
        c.push_back(tot);
    }
    sort(c.begin(),c.end());
    c.resize(unique(c.begin(), c.end()) - c.begin());
    Insert(lower_bound(c.begin(),c.end(),0)-c.begin()+1);
    tot=0;
    for (int i=1;i<=n;++i){
        tot+=arr[i];
        ans+=Query(lower_bound(c.begin(),c.end(),tot)-c.begin()+1);
        Insert(lower_bound(c.begin(),c.end(),tot)-c.begin()+1);
    }
    cout << ans << '\n';
}