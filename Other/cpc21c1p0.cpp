#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    string s; cin >> s;
    for (char c='a';c<='z';++c){
        if (s.find(c)==-1){
            cout << c << '\n';
            return 0;
        }
    }
}
