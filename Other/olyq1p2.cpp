#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,ans=0; cin >> n;
    vector<int> arr(n+1),q;
    for (int i=1;i<=n;++i){
        cin >> arr[i];
    }
    q.push_back(-1); q.push_back(arr[1]);
    for (int i=2;i<=n;++i){
        if (arr[i]>=q[q.size()-1]&&q[q.size()-1]>q[q.size()-2]) q.pop_back();
        else if (arr[i]<=q[q.size()-1]&&q[q.size()-1]<q[q.size()-2]) q.pop_back();
        q.push_back(arr[i]);
    }
    ans=max(ans,(int)q.size()-1);
    q.clear(); q.push_back(0x3f3f3f3f); q.push_back(arr[1]);
    for (int i=2;i<=n;++i){
        if (arr[i]>=q[q.size()-1]&&q[q.size()-1]>q[q.size()-2]) q.pop_back();
        else if (arr[i]<=q[q.size()-1]&&q[q.size()-1]<q[q.size()-2]) q.pop_back();
        q.push_back(arr[i]);
    }
    ans=max(ans,(int)q.size()-1);
    cout << ans << '\n';
}