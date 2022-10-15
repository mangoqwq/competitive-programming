#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=1e5+1,C=(1<<26)-1;

string arr[MAXN],ans;
int head[MAXN],cnt[MAXN][26];

int main(){
    //cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i){
        cin >> arr[i]; head[i]=arr[i].size()-1;
        reverse(arr[i].begin(),arr[i].end());
        for (char x:arr[i]) cnt[i][x-'a']++;
    }
    while (1){
        int mask=C; char curr;
        for (int i=1;i<=n;++i){
            for (int j=0;j<26;++j){
                if (!cnt[i][j]) mask&=C-(1<<j);
            }
        }
        if (mask==0) break;
        for (int i=25;i>=0;--i){
            if (1&(mask>>i)){ curr=i+'a'; break; }
        }
        ans+=curr;
        for (int i=1;i<=n;++i){
            while (arr[i][head[i]]!=curr){
                cnt[i][arr[i][head[i]]-'a']--;
                head[i]--;
            }
            cnt[i][curr-'a']--;
            head[i]--;
        }
    }
    cout << (ans==""?"-1":ans) << '\n';
}