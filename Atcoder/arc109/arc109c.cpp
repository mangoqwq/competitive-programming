#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=101;

char win(char a, char b){
    if (a==b) return a;
    if (a>b) swap(a,b);
    if (b=='S'&&a=='P') return b;
    else return a;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    string s, last; cin >> s;
    for (int i=1;i<=k;++i){
        last=""; swap(s,last);
        for (int j=0;j<n;++j){
            s+=win(last[(2*j)%n],last[(2*j+1)%n]);
        }
    }
    cout << s[0] << '\n';
}