#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
const int L=1000001;
ll arr[L],pre[L];
deque<pii> q;


int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    int n,k; cin >> n >> k;
    for (int i=1;i<=n;++i){
        cin >> arr[i];
        arr[i+n]=arr[i];
    }
    ll ans=0;
    for (int i=1;i<=2*n;++i){
        pre[i]=pre[i-1]+arr[i];
    }
    q.push_back({0,0});
    pair<ll,pii> uwu={LLONG_MIN,{0,0}};
    for (int i=1;i<=n+k;++i){
        if (i-q.front().second>k){
            q.pop_front();
        }
        if (pre[i]-q.front().first>uwu.first){
            uwu={pre[i]-q.front().first,{q.front().second,i}};
        }
        while (!q.empty()){
            if (q.back().first<pre[i]) break;
            q.pop_back();
        }
        q.push_back({pre[i],i});
    }
    ans+=uwu.first;
    //are taken
    for (int i=uwu.second.first;i<=uwu.second.second;++i){
        arr[i]=0;
        if (i>n) arr[i-n]=0;
        else if (i<=n) arr[i+n]=0;
    }

    //second
    for (int i=1;i<=2*n;++i){
        pre[i]=pre[i-1]+arr[i];
    }
    q.clear();
    q.push_back({0,0});
    uwu={LLONG_MIN,{0,0}};
    for (int i=1;i<=n+k;++i){
        if (i-q.front().second>k){
            q.pop_front();
        }
        if (pre[i]-q.front().first>uwu.first){
            uwu={pre[i]-q.front().first,{q.front().second,i}};
        }
        while (!q.empty()){
            if (q.back().first<pre[i]) break;
            q.pop_back();
        }
        q.push_back({pre[i],i});
    }
    ans+=uwu.first;
    cout << ans << '\n';
}