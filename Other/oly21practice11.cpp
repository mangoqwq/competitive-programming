#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e5+5;

int a[MAXN], rev[MAXN], uwu[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n; a[n+1]=a[0]=2;
    for (int i=1;i<=n;++i) cin >> a[i];
    for (int i=n;i>=1;--i){
        if (a[i]==a[i+1]) rev[i]=1;
        else rev[i]=rev[i+1]+1;
    }
    int last=1, ans=0;
    for (int i=1;i<=n;++i){
        if (a[i]==a[i-1]){
            uwu[i]=1;
            ans=max(ans,i-last+uwu[last-1]+rev[i]);
            last=i;
        }
        else{
            uwu[i]=uwu[i-1]+1;
            ans=max(ans,i-last+1+uwu[last-1]);
        }
    }
    cout << ans << '\n';
}