#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e5+1;

struct Item{ int x, id; } a[2*MAXN];
int cnt[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i){
        int x, y; cin >> x >> y;
        a[2*i-1]={x,i};
        a[2*i]={y,i};
    }
    int d; cin >> d;
    sort(a+1,a+1+2*n,[](Item x, Item y){ return x.x<y.x; });
    int l=1, curr=0, ans=0;
    for (int r=1;r<=2*n;++r){
        cnt[a[r].id]++;
        if (cnt[a[r].id]==2) curr++;
        while (a[l].x<a[r].x-d){
            cnt[a[l].id]--;
            if (cnt[a[l].id]==1) curr--;
            l++;
        }
        ans=max(ans,curr);
    }
    cout << ans << '\n';
}