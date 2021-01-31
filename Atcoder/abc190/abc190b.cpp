#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, s, d; cin >> n >> s >> d;
    bool flag=0;
    while (n--){
        int x, y; cin >> x >> y;
        if (x<s&&y>d) flag=1;
    }
    cout << (flag?"Yes":"No") << '\n';
}