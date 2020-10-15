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
        bool math=0, ics=0;
        for (char x:s){
            if (x=='C') ics=1;
            if (x=='M') math=1;
        }
        if (ics&&math) cout << "NEGATIVE MARKS" << '\n';
        else if (!ics&&!math) cout << "PASS" << '\n';
        else cout << "FAIL" << '\n';
    }
}