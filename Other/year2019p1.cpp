#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int h1, w1; cin >> h1 >> w1;
    int h2, w2; cin >> h2 >> w2;
    for (int i=0;i<=(int)1e6;++i){
        if (i%w1==0) h2--;
        if (i%w2==0) h1--;
        if (!h1&&!h2){ cout << -1 << '\n'; return 0; }
        if (!h1){ cout << 2 << '\n'; return 0; }
        if (!h2){ cout << 1 << '\n'; return 0; }
    }
}