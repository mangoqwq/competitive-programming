#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    string a, b; cin >> a >> b;
    int v1=0, v2=0;
    for (char x:a) v1+=x-'0';
    for (char x:b) v2+=x-'0';
    cout << max(v1, v2) << '\n';
}