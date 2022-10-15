#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int L=1000001;
int a[L],in[L],out[L];


int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n,k; cin >> n >> k;
    memset(in,0x3f,sizeof in); memset(out,-1,sizeof out);
    in[0]=0; out[0]=0;
    for (int i=1;i<=n;++i){
        cin >> a[i];
        a[i]=(a[i]+a[i-1])%k;
        in[a[i]]=min(in[a[i]],i);
        out[a[i]]=max(out[a[i]],i);
    }
    for (int i=0;i<=n;++i){
        //cout << i << "->" << in[i] << " " << out[i] << '\n';
    }
    int ans=0;
    for (int i=0;i<=k;++i){
        ans=max(ans,out[i]-in[i]);
    }
    if (ans==0) cout << -1 << '\n';
    else cout << ans << '\n';

}