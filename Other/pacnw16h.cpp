#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
set<ll> s;

int main(){
    int n,k; cin >> n >> k;
    s.insert(1);
    ll a,b;
    for (int i=0;i<k;++i){
        cin >> a >> b;
        if (s.find(a)!=s.end()){
            s.insert(b+1);
        }
    }
    if (s.find(n+1)==s.end()){
        cout << 1 << '\n';
    }
    else{
        cout << 0 << '\n';
    }
}