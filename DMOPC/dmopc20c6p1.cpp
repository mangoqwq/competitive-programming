#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=0;

ll tot=0, curr=0, idx=0;
ll eval(ll x){ return abs(x-(tot-x)); }

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<int> a(n);
    for (int i=0;i<n;++i) cin >> a[i];
    tot=accumulate(a.begin(),a.end(),0LL);
    for (int i=0;i<n;++i){
        while (eval(curr+a[idx])<eval(curr)) curr+=a[idx++];
        cout << eval(curr) << (i==n-1?'\n':' ');
        curr-=a[i]; a.push_back(a[i]);
    }
}