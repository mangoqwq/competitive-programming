#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    bool ans=0;
    int n; cin >> n;
    int curr=0;
    for (int i=1;i<=n;++i){
        int a, b; cin >> a >> b;
        if (a==b) curr++;
        else curr=0;
        ans|=curr>=3;
    }
    cout << (ans?"Yes":"No") << '\n';
}