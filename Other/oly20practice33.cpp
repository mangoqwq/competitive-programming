#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
int arr[10001];
int ans[10001];

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n,index,h,q; cin >> n >> index >> h >> q;
    set<pii> s;
    for (int i=0,a,b;i<q;++i){
        cin >> a >> b;
        s.insert({min(a,b),max(a,b)});
    }
    for (auto&&x:s){
        arr[x.second]++;
        arr[x.first+1]--;
    }
    
    ans[index]=h;
    for (int i=index-1;i>0;--i){
        ans[i]=ans[i+1]-arr[i+1];
    }
    for (int i=index+1;i<=n;++i){
        ans[i]=ans[i-1]+arr[i];
    }
    for (int i=1;i<=n;++i){
        cout << ans[i] << '\n';
    }
    
}