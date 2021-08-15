#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int n; cin >> n;
        vector<pair<int,int>> v(n);
        for (auto &[a, b] : v) cin >> a >> b;
        sort(v.begin(), v.end());
        int ans = 1;
        priority_queue<int, vector<int>, greater<int>> pq;
        int i = 0, p = 0;
        while (true){
            if (!pq.empty()){
                int x = pq.top(); pq.pop();
                if (x < i) ans = 0;
                i++;
            }
            else{
                if (p < n) i = v[p].first;
            }
            while (p < n && v[p].first == i) pq.push(v[p++].second);
            if (pq.empty() && p == n) break;
        }
        cout << (ans ? "Yes" : "No") << '\n';
    }
}
