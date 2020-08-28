#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=1e5+1,c=2e6+5;

int cnt[2*c+5], s1[MAXN], s2[MAXN], n, k;
ll tot, idx, ans=LLONG_MAX, l, r, pos;
vector<int> uwu; stack<int> small, large, ok;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k; pos=n;
    for (int i=1;i<=n;++i) cin >> s1[i];
    for (int i=1,x;i<=n;++i){
        cin >> s2[i];
        x=s2[i]-s1[i];
        cnt[x+c]++;
        uwu.push_back(x);
    }
    sort(uwu.begin(),uwu.end());
    for (int i=0;i<n;++i){
        tot+=uwu[n-1]+1-uwu[i];
        if (i<k) small.push(uwu[i]), l+=uwu[n-1]+1-uwu[i];
        ok.push(uwu[i]);
    }
    for (idx=uwu[n-1]+1;idx>=uwu[0]-1;){
        //cout << idx << " " << tot-l-r << '\n';
        if (tot-l-r>=0) ans=min(ans,tot-l-r);
        pos-=cnt[idx+c]; idx--;
        tot-=pos; tot+=(n-pos);
        l-=small.size(); r+=large.size();
        while (!small.empty() && !ok.empty() && abs(small.top()-idx)<=abs(ok.top()-idx)){
            l-=abs(idx-small.top()); r+=abs(idx-ok.top()); 
            small.pop(); large.push(ok.top()); ok.pop();
        }
    }
    cout << ans << '\n';
}