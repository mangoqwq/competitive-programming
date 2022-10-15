#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const ll mod=1e13+7,seed=331,MAXN=1e5+1;
random_device rd;
mt19937_64 gen(rd()); uniform_int_distribution<ll> dis(1, 1e12);

ll key[MAXN];
unordered_map<ll,int> cnt;

int main(){
    int n,m; cin >> n >> m;
    ll tot=0,ans=0,curr=0;
    for (int i=1;i<=m;++i) key[i]=dis(gen), tot+=key[i];
    cnt[0]=1;
    for (int i=1,a;i<=n;++i){
        cin >> a;
        curr+=key[a]; curr%=tot;
        if (cnt.count(curr)) ans+=cnt[curr];
        cnt[curr]++;
    }
    cout << ans << '\n';
}