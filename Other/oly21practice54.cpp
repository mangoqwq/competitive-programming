#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=0;

set<int> s;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int x, n; cin >> x >> n;
    for (int i=1;i<=n;++i){
        int c; cin >> c;
        s.insert(c);
    }
    for (int i=0;;++i){
        int c=x-i;
        if (!s.count(c)){
            cout << c << '\n';
            return 0;
        }
        c=x+i;
        if (!s.count(c)){
            cout << c << '\n';
            return 0;
        }
    }
}