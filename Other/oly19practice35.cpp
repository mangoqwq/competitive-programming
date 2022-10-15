#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

string a,b;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> a >> b;
    ll ans=0;
    for (char x:a){
        for (char y:b){
            ans+=(x-'0')*(y-'0');
        }
    }
    cout << ans << '\n';
}