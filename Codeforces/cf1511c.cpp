#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=51;

int top[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    for (int i=1;i<=n;++i){
        int a; cin >> a;
        if (!top[a]) top[a]=i;
    }
    while (q--){
        int x; cin >> x;
        for (int i=1;i<=50;++i){
            if (!top[i]) continue;
            if (top[i]<top[x]) top[i]++;
        }
        cout << top[x] << " ";
        top[x]=1;
    }
}