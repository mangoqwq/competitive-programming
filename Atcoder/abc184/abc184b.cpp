#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, x; cin >> n >> x;
    string s; cin >> s;
    for (char c:s){
        if (c=='x') x--;
        if (c=='o') x++;
        if (x<0) x=0;
    }
    cout << x << '\n';
}