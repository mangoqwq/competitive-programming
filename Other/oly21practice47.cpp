#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    string a, b; cin >> a >> b;
    if (a==b) cout << "Yes" << '\n';
    else if (a.size()!=b.size()+1) cout << "No" << '\n';
    else{
        int l=0, r=a.size()-1;
        for (;l<b.size();++l){
            if (a[l]!=b[l]) break;
        }
        for (;r>0;--r){
            if (a[r]!=b[r-1]) break;
        }
        if (l>=r) cout << "Yes" << '\n';
        else cout << "No" << '\n';
    }
}