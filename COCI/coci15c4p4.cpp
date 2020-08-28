#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    ll n,k,q; cin >> n >> k >> q;
    ll a,b; int count;
    for (int i=0;i<q;++i){
        cin >> a >> b;
        a-=2; b-=2;
        count=0;
        while (a!=b){
            if (a>b) a=(a/k)-1;
            else b=(b/k)-1;
            count++;
        }
        cout << count << '\n';
    }
}