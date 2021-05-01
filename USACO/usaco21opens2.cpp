#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=8;
const int seed=131;

vector<ll> a;
struct Rule{ int x, i, j, c; };
vector<Rule> uwu={{0,3,1,-1},{0,4,2,-1},{0,6,5,-1},
                  {1,3,0,-1},{1,5,2,-1},{1,6,4,-1},
                  {2,4,0,-1},{2,5,1,-1},{2,6,3,-1},
                  {3,0,1,1},{3,6,2,-1},
                  {4,0,2,1},{4,6,1,-1},
                  {5,1,2,1},{5,1,2,1},
                  {6,3,2,1},{6,4,1,1},{6,5,0,1}};
ll eval(Rule r){
    return a[r.i]+a[r.j]*r.c;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        vector<ll> b(7,-inf);
        for (int i=0;i<n;++i) cin >> b[i];
        unordered_set<ll> ans;
        sort(b.begin(),b.end());
        do{
            a=b;
            for (int _=1;_<=4;++_){
                for (Rule r:uwu){
                    if (a[r.i]>0&&a[r.j]>0&&a[r.x]<=0){
                        a[r.x]=eval(r);
                    }    
                }
            }
            bool can=a[2]>=a[1]&&a[1]>=a[0];
            for (Rule r:uwu){
                can&=eval(r)==a[r.x];
            }
            for (int j=0;j<7;++j) can&=a[j]>0;
            if (can) ans.insert(a[0]*seed*seed+a[1]*seed+a[2]);
        } while (next_permutation(b.begin(),b.end()));
        cout << ans.size() << '\n';
    }    
}