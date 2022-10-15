#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=2e5+1;

int n,arr[MAXN];
int cnt[MAXN],uwu,len,x;
ll ans;

void Insert(int val){
    if (cnt[val]==x) uwu--;
    cnt[val]++;
    if (cnt[val]==x) uwu++;
}

void Erase(int val){
    if (cnt[val]==x) uwu--;
    cnt[val]--;
    if (cnt[val]==x) uwu++;
}

void solve(){
    len=x*x; uwu=0; ms(cnt,0);
    for (int i=1;i<=len;++i){
        Insert(arr[i]);
    }
    if (uwu==x) ans++;
    for (int i=len+1;i<=n;++i){
        Insert(arr[i]);
        Erase(arr[i-len]);
        if (uwu==x) ans++;
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n; ans=n;
    for (int i=1;i<=n;++i) cin >> arr[i];
    for (x=2;x*x<=n;++x){
        solve();
    }
    cout << ans << '\n';
}