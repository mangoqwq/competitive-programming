#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=1e3+1, MAXM=2e3+1;

int a[MAXM], b[MAXM];
int val[MAXN], last[MAXN], curr[MAXN], ans=0; 

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m, c;
    cin >> n >> m >> c;
    for (int i=1;i<=n;++i) cin >> val[i];
    ms(curr,-0x3f), ms(last,-0x3f), curr[1]=0;
    for (int i=1;i<=m;++i) cin >> a[i] >> b[i];
    for (int i=1;i<=1000;++i){
        swap(last,curr);
        for (int j=1;j<=m;++j){
            curr[b[j]]=max(curr[b[j]],last[a[j]]+val[b[j]]);
        }
        ans=max(ans,curr[1]-c*i*i);
    }
    cout << ans << '\n';
}