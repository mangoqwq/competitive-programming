#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n; cin >> n;
    int minimum=0x3f3f3f3f;
    ll total=0;
    bool zero=false;
    bool negative=false;
    for (int i=0,a;i<n;++i){
        cin >> a;
        minimum=min(minimum,abs(a));
        total+=abs(a);
        if (a==0) zero=true;
        if (a<0) negative=!negative;
    }
    if (zero) cout << total << '\n';
    else if (negative) cout << total-2*minimum <<'\n';
    else cout << total << '\n';
}