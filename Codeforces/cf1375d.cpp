#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        vector<int> arr(n+1),ans,cnt[n+15];
        for (int i=1;i<=n;++i){
            cin >> arr[i];
            cnt[arr[i]].push_back(i);
        }
        int index=0;
        for (int i=1;i<=n;++i){
            if (arr[i]==i-1) continue;
            while (cnt[index].size()) index++;
            for (int x:cnt[i-1]){
                ans.push_back(x);
                cnt[index].push_back(x);
                while (cnt[index].size()) index++;
            }
            cnt[i-1].clear(); cnt[i-1].push_back(i);
            ans.push_back(i);
        }
        cout << ans.size() << '\n';
        for (int x:ans) cout << x << " ";
        cout << '\n';
    }
}