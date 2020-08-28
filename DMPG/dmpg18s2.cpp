#include <bits/stdc++.h>
#pragma GCC optimize ("unroll-loops")
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int x[2000000];

int main(){
    int n; scan(n);
    ll total=0;
    for (int i=0;i<n;++i){
        scan(x[i]);
        total+=x[i];
    }
    ll ans=0;
    for (int i=0;i<n;++i){
        ans+=total;
        cout << ans << '\n';
        total-=(x[i]+x
        [n-i-1]);
    }
}