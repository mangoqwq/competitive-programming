#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=0;

void go(string suf, int n, int k){
    if (k>n) return;
    if (k==0){
        cout << suf;
        for (int i=1;i<=n;++i) cout << 0;
        cout << '\n';
    }
    else{
        go(suf+"1",n-1,k-1);
        go(suf+"0",n-1,k);
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n, k; cin >> n >> k;
        cout << "The bit patterns are" << '\n';
        go("",n,k);
        cout << '\n';
    }
}