#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

set<int> ans;

void solve(int x, int bot, int add){
    ans.insert(add+x-1);
    for (int i=bot;i*i<=x;++i){
        if (x%i==0) solve(x/i,i,add+i-1);
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    solve(n,2,0);
    cout << ans.size() << '\n';
    for (int x:ans) cout << x << " ";
    cout << '\n';
}