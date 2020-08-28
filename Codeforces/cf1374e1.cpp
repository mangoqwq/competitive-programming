#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,k; cin >> n >> k;
    vector<pii> arr;
    int ca,cb; ca=cb=0;
    ll tot=0;
    for (int i=1,t,x,y;i<=n;++i){
        cin >> t >> x >> y;
        arr.push_back({t,x+2*y});
        if (x||y) tot+=t;
        if (x&&y) ca++, cb++;
        else if (x) ca++;
        else if (y) cb++;
    }
    if (ca<k||cb<k){ cout << -1 << '\n'; return 0;}
    sort(arr.begin(),arr.end()); reverse(arr.begin(),arr.end());
    for (int i=0;i<arr.size();++i){
        if (arr[i].second==1){
            if (ca>k) tot-=arr[i].first, ca--;
        }
        else if (arr[i].second==2){
            if (cb>k) tot-=arr[i].first, cb--;
        }
        else if (arr[i].second==3){
            if (ca>k&&cb>k) tot-=arr[i].first, ca--, cb--;
        }
    }
    cout << tot << '\n';
}