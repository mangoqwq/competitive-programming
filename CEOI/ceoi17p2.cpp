#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=1e5+5;

double a[MAXN], b[MAXN], ta, tb, ans;
int pa, pb;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i) cin >> a[i] >> b[i];
    sort(a+1,a+1+n,greater<double>()), sort(b+1,b+1+n,greater<double>());
    while (pa!=n+1 && pb!=n+1){
        if (ta<tb) ta+=a[++pa]-1, tb--;
        else ta--, tb+=b[++pb]-1;
        // printf("%.4f, %.4f \n", ta, tb);
        ans=max(ans,min(ta,tb));
    }
    printf("%.4f",ans);
}