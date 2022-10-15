#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

set<int> s;

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n; cin >> n;
    for (int i=0,a;i<n;++i){
        cin >> a;
        if (s.count(a)) s.erase(a);
        else s.insert(a);
    }
    for (int x:s) cout << x << '\n';
}