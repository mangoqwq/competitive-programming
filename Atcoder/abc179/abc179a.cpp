#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    string s; cin >> s;
    if (s[s.size()-1]=='s') s+='e';
    s+='s';
    cout << s << '\n';
}