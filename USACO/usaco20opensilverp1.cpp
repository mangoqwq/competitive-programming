#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
vector<pii> grass;
int n,m; 

int uwu(ll step){
    int cows=1;
    ll index=grass[0].first;
    int seg=0;
    index+=step;
    while (seg<=m-1){
        if (index<=grass[seg].second){
            index=max(index,grass[seg].first);
            cows++;
            index+=step;
        }else{
            seg++;
        }
    }
    return cows;
}

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    //freopen("socdist.in","r",stdin);
    //freopen("socdist.out","w",stdout);
    cin >> n >> m;
    ll l,r;
    
    for (int i=0;i<m;++i){
        cin >> l >> r;
        grass.push_back({l,r});
    }
    sort(begin(grass),end(grass));
    ll lo=0;
    ll hi=(grass[m-1].second+n)/(n-1);
    ll mid;
    while (lo<=hi){
        mid=(lo+hi)/2;
        if (uwu(mid)>=n){
            if (uwu(mid+1)<n){
                cout << mid << '\n';
                return 0;
            }
            else{
                lo=mid+1;
            }
        }
        else{
            hi=mid-1;
        }
    }
}