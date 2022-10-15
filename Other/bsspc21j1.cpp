#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int s; cin >> s;
    int n; cin >> n;
    s=(s+2)*3+16;
    cout << (s<=n?"Yes it fits!":"No, it's too small :(") << '\n';
}