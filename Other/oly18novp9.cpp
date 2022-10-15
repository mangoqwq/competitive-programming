#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
#define get(x,pos) ((x/power[pos])%10)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

int l,r,power[10],dp[11][12][2][2][2];

int solve(int pos, int last, bool zero, bool low, bool high){
    if (pos==-1) return 1;
    int &curr=dp[pos][last][zero][low][high];
    if (curr!=-1) return curr;
    int bot=(low?get(l,pos):0), top=(high?get(r,pos):9);
    curr=0;
    for (int i=bot;i<=top;++i){
        if (abs(i-last)<=1) continue;
        curr+=solve(pos-1,(zero&&i==0?11:i),zero&(i==0),low&(i==bot),high&(i==top));
    }
    return curr;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    power[0]=1;
    for (int i=1;i<=9;++i) power[i]=power[i-1]*10;
    cin >> l >> r; ms(dp,-1);
    cout << solve(log10(r),11,1,1,1) << '\n';
}