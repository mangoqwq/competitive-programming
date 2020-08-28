#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
vector<pii> moo;
int l[100000];
int r[100000];


int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    //freopen("moop.in","r",stdin);
    //freopen("moop.out","w",stdout);
    int n; cin >>n;
    for (int i=0,a,b;i<n;++i){
        cin >> a >> b;
        moo.push_back({a,b});
    }
    sort(begin(moo),end(moo));
    l[0]=moo[0].second;
    for (int i=1;i<n;++i){
        l[i]=min(moo[i].second,l[i-1]);
    }
    r[n-1]=moo[n-1].second;
    for (int i=n-2;i>=0;--i){
        r[i]=max(moo[i].second,r[i+1]);
    }
    int ans=1;
    for (int i=0;i<n-1;++i){
        ans+=l[i]>r[i+1];
    }
    cout << ans << '\n';
    
}