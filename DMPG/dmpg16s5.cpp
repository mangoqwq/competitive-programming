#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;
typedef long long ll;
typedef pair<ll,int> pll;
int a[200000];
ll pre[200000];
deque<pll> dq;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n,k; cin >> n >> k;
    for (int i=0;i<n;++i){
        cin >> a[i];
        a[i+n]=a[i];
    }
    pre[0]=a[0];
    for (int i=1;i<2*n;++i){
        pre[i]=a[i]+pre[i-1];
    }
    for (int i=0;i<k-1;++i){
        while (!dq.empty()){
            if (pre[i]<=dq.back().first){
                dq.pop_back();
            }else{
                break;
            }
        }
        dq.push_back({pre[i],i});
    }
    ll yumyum=-1;
    for (int i=k;i<k+n;++i){
        if (dq.front().second==i-k-1){
            dq.pop_front();
        }
        while (!dq.empty()){
            if (pre[i]<=dq.back().first){
                dq.pop_back();
            }else{
                break;
            }
        }
        dq.push_back({pre[i],i});
        //cout << pre[i]/*dq.front().first*/ << '\n';
        yumyum=max(yumyum,pre[i]-dq.front().first);
    }
    cout << yumyum << '\n';
    
}