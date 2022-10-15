#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int len,n; cin >> len >> n;
    vector<pii> arr;
    for (int i=0,a,b;i<n;++i){
        cin >> a >> b;
        arr.push_back({a,b});
    }
    sort(begin(arr),end(arr));
    int ans=arr[0].first;
    int l=arr[0].first,r=arr[0].second;
    for (int i=1;i<arr.size();++i){
        if (arr[i].first>r){
            ans=max(ans,arr[i].first-r);
            l=arr[i].first;
        }
        r=max(r,arr[i].second);
    }
    ans=max(ans,len-r);
    cout << ans << '\n';
}