#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
vector<ll> ans, pre, cute;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    ll n, w; cin >> n >> w;
    char opr; ll a,b;
    ll index=0;
    ans.push_back(0); pre.push_back(0); cute.push_back(0);
    for (int i=0;i<n;++i){
        cin >> opr;
        if (opr=='A'){
            cin >> a >> b;
            pre.push_back(pre[pre.size()-1]+a);
            cute.push_back(cute[cute.size()-1]+b);
            index=lower_bound(pre.begin(),pre.end(),pre[pre.size()-1]-w)-pre.begin()+1;
            ans.push_back(max(ans[ans.size()-1],cute[cute.size()-1]-cute[index-1]));
            cout << ans[ans.size()-1] << '\n';
        }
        else{
            ans.pop_back();
            pre.pop_back();
            cute.pop_back();
        }
    }

}