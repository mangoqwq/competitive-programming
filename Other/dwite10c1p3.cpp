#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

int solve(int r, int c){
    if (r==0||c==0) return 0;
    int curr=1<<(int)min(log2(r),log2(c));
    return 1+solve(r-curr,curr)+solve(curr,c-curr)+solve(r-curr,c-curr);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t=5;
    while (t--){
        int n,m; cin >> n >> m;
        cout << solve(n,m) << '\n';
    }
}