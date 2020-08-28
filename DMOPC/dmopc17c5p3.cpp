#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    long long x; cin >> x;
    long long a;
    for (int i=0;i<n-1;++i){
        cin >> a;
        x=__gcd(x,a);
    }
    cout << x << '\n';
}