#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=2001;
const ll inf=0x3f3f3f3f3f3f3f3f;

bool arr[MAXN][MAXN]; // column, row
ll dp[MAXN];
struct Line{
    ll m,b;
    ll eval(const ll &x){ return m*x+b; }
    double sect(const Line &x){ return ((double)(x.b-b))/(m-x.m); }
} temp;
vector<Line> last,curr;
vector<int> uwu(MAXN); 
bool cmp(const int &idx, const int &val){
    return last[idx].sect(last[idx+1])<(double)val;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    iota(uwu.begin(),uwu.end(),0);
    int n,m; char a; cin >> n >> m;
    for (int i=1;i<=m;++i){
        for (int j=1;j<=n;++j){
            cin >> a; arr[j][i]=a-'0';
        }
    }
    for (int i=1;i<=m;++i) last.push_back({2*i,-i*i});
    for (int c=1;c<=n;++c){
        for (int i=1;i<=m;++i){
            if (arr[c][i]){
                int idx=*lower_bound(uwu.begin(),uwu.begin()+last.size()-1,i,cmp);
                dp[i]=-last[idx].eval(i)+i*i;
                temp={2*i,-i*i-dp[i]};
                while (curr.size()>=2 && curr[curr.size()-1].sect(temp)<=curr[curr.size()-1].sect(curr[curr.size()-2]))
                    curr.pop_back();
                curr.push_back(temp);
            } else dp[i]=inf;
        }
        swap(last,curr); curr.clear();
    }
    ll ans=inf;
    for (int i=1;i<=m;++i) ans=min(ans,dp[i]);
    cout << ans << '\n';
}