#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int a, b, c; cin >> a >> b >> c;
    while (true){
        if (!c){
            if (a==0) return cout << "Aoki" << '\n', 0;
            a--;
        }
        else{
            if (b==0) return cout << "Takahashi" << '\n', 0;
            b--;
        }
        c^=1;
    }
}