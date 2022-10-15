#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int a, b, c; cin >> a >> b >> c;
    a+=b;
    for (int i=1;i<=3;++i){
        if (a>=c) return cout << a << '\n', 0;
        a+=b;
    }
    cout << "Who knows..." << '\n';
}