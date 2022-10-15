#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        string s; cin >> s;
        int x=(s[0]-'1')*4+(s[2]-'1');
        if (x<=1) cout << (8-x) << '\n';
        else if (x<=13) cout << (18-x) << '\n';
        else cout << (32-x) << '\n';
    }
}