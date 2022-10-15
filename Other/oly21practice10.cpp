#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e5+1;

struct Item{ int x, m; } arr[MAXN];
bool cmp(Item a, Item b){ return a.x<b.x; }

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k; k=k*2;
    for (int i=1;i<=n;++i) cin >> arr[i].m >> arr[i].x;
    sort(arr+1,arr+1+n,cmp);
    int p=1, ans=0, cnt=0;
    for (int i=1;i<=n;++i){
        cnt+=arr[i].m;
        while (arr[i].x-k>arr[p].x) cnt-=arr[p].m, p++;
        ans=max(ans,cnt);
    }
    cout << ans << '\n';
}