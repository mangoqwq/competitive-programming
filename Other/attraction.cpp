#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=0;

struct Item{
    int c, v;
    // -1 = end points
    // 0 = full range, even
    // 1 = full range, odd
    // 2 = half range, no make one
    // 3 = half range, make one
    // 4 = single point
    bool operator<(const Item &x) const{
        return tie(v,c)<tie(x.v,x.c);
    }
};
priority_queue<Item> pq;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        while (!pq.empty()) pq.pop();
        int n, a, b; cin >> n >> a >> b;
        vector<int> vec(a);
        for (int &x:vec) cin >> x;
        sort(vec.begin(),vec.end());
        for (int i=1;i<a;++i){
            int v=vec[i]-vec[i-1]-1;
            if (v==1) pq.push({4,1});
            else if (v%2==0) pq.push({0,v/2});
            else if (v%2==1) pq.push({1,v/2+1});
        }
        pq.push({-1,vec[0]-1}), pq.push({-1,n-vec.back()});
        int ans=0;
        for (int i=1;i<=b;++i){
            if (pq.empty()) break;
            auto [c,v]=pq.top(); pq.pop();
            ans+=v;
            if (c==0) pq.push({2,v});
            if (c==1) pq.push({3,v-2});
            if (c==3) pq.push({4,1});
        }
        cout << ans << '\n';
    }
}