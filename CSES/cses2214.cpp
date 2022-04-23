#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    using ll = long long;
    deque<int> q;
    ll N, K; cin >> N >> K;
    for (int i = 1; i <= N; ++i) q.push_back(i);
    vector<int> ans;
    for (int i = N - 1; i >= 0; --i){
        if (i <= K){
            ans.push_back(q.back());
            q.pop_back();
            K -= i;
        }
        else{
            ans.push_back(q.front());
            q.pop_front();
        }
    }
    for (int x : ans) cout << x << " ";
    cout << '\n';
}
