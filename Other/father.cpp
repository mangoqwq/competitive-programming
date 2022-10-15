#include <bits/stdc++.h>

// incorrect but passes 

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=5001;

int n, m, a[MAXN];
priority_queue<int> pq;
vector<int> vec;

bool check(int x){
    while (!pq.empty()) pq.pop();
    for (int i=1;i<=n;++i) if (a[i]<m) pq.push(m-1-a[i]);
    vector<int> uwu;
    for (int i=1;i<=n;++i) if (a[i]>=m) uwu.push_back(a[i]-m+1);
    sort(uwu.begin(),uwu.end(), greater<int>());
    for (int rem:uwu){
        while (rem){
            if (pq.empty()||pq.top()==0) return 0;
            int v=pq.top(); pq.pop();
            int tmp=min({rem,x,v});
            rem-=tmp, v-=tmp;
            vec.push_back(v);
        }
        while (!vec.empty()) pq.push(vec.back()), vec.pop_back();
    }
    return 1;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n, n--;
    cin >> m;
    for (int i=1;i<=n;++i) cin >> a[i];
    int lo=0, hi=1000000, mid;
    while (lo<hi){
        mid=lo+hi>>1;
        if (check(mid)) hi=mid;
        else lo=mid+1;
    }
    if (check(lo)) cout << lo << '\n';
    else cout << "impossible" << '\n';
}