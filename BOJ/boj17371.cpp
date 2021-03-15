#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e3+1;

int x[MAXN], y[MAXN];
int ans, best=inf;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i) cin >> x[i] >> y[i];
    for (int i=1;i<=n;++i){
        int curr=0;
        for (int j=1;j<=n;++j){
            curr=max(curr,(x[j]-x[i])*(x[j]-x[i])+(y[j]-y[i])*(y[j]-y[i]));
        }
        if (curr<best) best=curr, ans=i;
    }
    cout << x[ans] << " " << y[ans] << '\n';
}