#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
#define get(x,a) ((int)((x/pows[a])%10))
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

ll dp[16][136][2][2],nxt[16][136][2][2],l,r,pows[16];

ll solve(int pos, int s, bool bot, bool top){
    if (pos<0){ return s==0; }
    ll &curr=dp[pos][s][bot][top];
    if (curr!=-1) return curr;
    int start=(bot?get(l,pos):0), end=min(s,(top?get(r,pos):9)); curr=0;
    for (int i=end;i>=start;--i){
        ll temp=solve(pos-1,s-i,bot&(i==start),top&(i==end));
        if (temp) nxt[pos][s][bot][top]=i;
        curr+=temp;
    }
    return curr;
}

void back(int pos, int s, bool bot, bool top, bool zero){
    if (pos<0) return;
    int curr=nxt[pos][s][bot][top];
    if (!(zero&(curr==0))) cout << curr;
    back(pos-1,s-curr,bot&(curr==get(l,pos)),top&(curr==get(r,pos)),zero&(curr==0));
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    pows[0]=1;
    for (int i=1;i<16;++i) pows[i]=pows[i-1]*10;
    int s; cin >> l >> r >> s;
    ms(dp,-1); ms(nxt,-1);
    cout << solve(log10(r),s,1,1) << '\n';
    back(log10(r),s,1,1,1); cout << '\n';
    
}