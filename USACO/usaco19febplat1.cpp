#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
#define eval(l,r) ((a[r]/a[l-1])*(b[r]-b[l-1]))
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=1e6+1;

long double arr[MAXN], a[MAXN], b[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    a[0]=1;
    for (int i=1;i<=n;++i){
        cin >> arr[i]; arr[i]/=1e6;
        a[i]=a[i-1]*(1-arr[i]);
        b[i]=b[i-1]+arr[i]/(1-arr[i]);
    }
    long double ans=0;
    int l=1;
    for (int r=1;r<=n;++r){
        while (eval(l,r)<eval(l+1,r)) l++;
        ans=max(ans,eval(l,r));
    }
    cout << (int)(ans*1e6) << '\n';
}