#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

string l,r;
bool vis[19][163][2][2];
bitset<163> ans;

void solve(int pos, int tot, bool low, bool high){
    if (pos>=r.size()){ ans[tot]=1; return; }
    if (vis[pos][tot][low][high]) return;
    vis[pos][tot][low][high]=1;
    int start=(low?l[pos]-'0':0), end=(high?r[pos]-'0':9);
    for (int i=start;i<=end;++i) 
        solve(pos+1,tot+i,low&(i==start),high&(i==end));
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> l >> r;
    while (l.size()<r.size()) l='0'+l;
    solve(0,0,1,1);
    cout << ans.count() << '\n';
}