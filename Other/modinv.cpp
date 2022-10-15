#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;

ull mod;

void egcd(ull n, ull m, ull &a, ull &b){
    if (m==0){
        a=1, b=0;
        return;
    }
    ull a1, b1;
    egcd(m,n%m,a1,b1);
    a=b1;
    b=a1-(n/m)*b1;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ull n, m, a, b; cin >> n >> m;
    egcd(n,m,a,b);
    cout << (a+m)%m << '\n';
}