#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=2e5+5;

int arr[MAXN],cnt[MAXN],need[MAXN],uwu;

void Insert(int x){
    if (need[x]==-1) return;
    if (cnt[x]==need[x]-1) uwu--;
    cnt[x]++;
}

void Remove(int x){
    if (need[x]==-1) return;
    if (cnt[x]==need[x]) uwu++;
    cnt[x]--;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,k,r; cin >> n >> k >> r;
    ms(need,-1);
    for (int i=1;i<=n;++i) cin >> arr[i];
    for (int i=1,a;i<=r;++i){
        cin >> a; cin >> need[a];
    }
    int pl=1,pr=0,ans=0x3f3f3f3f; uwu=r;
    while (pr<=n){
        if (uwu==0){
            ans=min(ans,pr-pl+1);
            Remove(arr[pl++]);
        }
        else{
            Insert(arr[++pr]);
        }
    }
    if (ans==0x3f3f3f3f) cout << "impossible" << '\n';
    else cout << ans << '\n';
}