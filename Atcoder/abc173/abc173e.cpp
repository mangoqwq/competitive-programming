#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=2e5+1;

vector<ll> pos, neg, arr;

int main(){
    //cin.tie(0)->sync_with_stdio(0);
    freopen("../../txt.in","r",stdin);
    int n, k; cin >> n >> k; arr.resize(n);
    int cpos=0;
    for (int i=0;i<n;++i){
        cin >> arr[i];
        if (arr[i]>=0) cpos++;
    }
    sort(arr.begin(),arr.end(),[](ll a, ll b){ return abs(a)<abs(b); });
    bool canpos=0;
    for (int i=0;i<=cpos;++i){
        if ((k-i)%2==0&&(k-i)<=n-cpos) canpos=1;
    }
    ll ans=1;
    if (canpos){
        int p=arr.size()-1;
        for (int i=1;i<=k;++i){
            ll a=arr[p--];
            if (a>=0) pos.push_back(a);
            else neg.push_back(a);
        }
        if (neg.size()%2==1){
            ll nxtp=0, nxtn=0;
            for (int i=p;i>=0;--i){
                if (arr[i]<0) nxtn=min(nxtn,arr[i]);
                if (arr[i]>0) nxtp=max(nxtp,arr[i]);
            }
            if (pos.empty()) neg.pop_back(), pos.push_back(nxtp);
            else if (neg.back()*nxtn>pos.back()*nxtp) pos.pop_back(), neg.push_back(nxtn);
            else neg.pop_back(), pos.push_back(nxtp);
        }
        for (ll x:neg) ans=ans*x%mod;
        for (ll x:pos) ans=ans*x%mod;

    }
    else{
        for (int i=0;i<k;++i) ans=ans*arr[i]%mod;
    }
    cout << (ans+mod)%mod << '\n';
}