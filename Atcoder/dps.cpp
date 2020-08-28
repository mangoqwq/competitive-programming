#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=1e4+1;

string n; int d;
int dp[MAXN][100][2];

int solve(int pos, int val, bool flag){
    int &curr=dp[pos][val][flag];
    if (curr!=-1) return curr;
    if (pos==n.size()) return val==0;
    int top=(flag?n[pos]-'0':9); curr=0;
    for (int i=0;i<=top;++i){
        curr+=solve(pos+1,(val+10*d-i)%d,flag&(i==top));
        curr%=mod;
    }
    return curr;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> d;
    ms(dp,-1);
    cout << solve(0,0,1)-1 << '\n';
}