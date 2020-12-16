#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m, t; cin >> n >> m >> t;
    int curr=n, last=0;
    bool ans=1;
    for (int i=1;i<=m;++i){
        int a, b; cin >> a >> b;
        curr-=a-last; if (curr<=0) ans=0;
        curr=min(curr+b-a,n);
        last=b;
    }
    curr-=t-last;
    if (curr<=0) ans=0;
    cout << (ans?"Yes":"No") << '\n';
}