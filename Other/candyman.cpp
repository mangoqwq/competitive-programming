#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=11;

int n, idx[MAXN];
ll val[MAXN][11]; 
vector<int> stk;

bool solve(int x){
    if (x==n+1){ for (int a:stk) cout << a << " "; cout << '\n'; return 1; }
    for (int i=10;i>idx[x];--i){
        bool skip=0;
        for (int j=0;j<stk.size();++j) if (__gcd(val[x][i],val[j+1][stk[j]])!=1) skip=1;
        if (skip) continue;
        stk.push_back(i);
        if (solve(x+1)) return true;
        stk.pop_back();
    }
    return false;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=1;i<=n;++i){
        string a; cin >> a;
        for (char x:a) idx[i]=max(idx[i],x-'0');
        for (int base=10;base>idx[i];--base){
            for (char x:a) val[i][base]*=base, val[i][base]+=x-'0';
        }
    }
    solve(1);   
}