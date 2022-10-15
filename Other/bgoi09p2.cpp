#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=1e5+1;

int p[MAXN], ans;

int Find(int x){ return (p[x]==x?x:p[x]=Find(p[x])); }
void Union(int a, int b){
    a=Find(a); b=Find(b);
    if (a^b){
        ans--;
        p[b]=a;
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t=2;
    while (t--){
        int n; cin >> n; ans=n;
        iota(p+1,p+1+n,1);
        for (int i=1,a;i<=n;++i){
            cin >> a;
            Union(i,a);
        }
        cout << ans << " ";
    }
    cout << '\n';
}