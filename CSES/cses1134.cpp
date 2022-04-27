#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    vector<int> deg(N + 1);
    vector<int> a(N - 1);
    for (int i = 1; i <= N - 2; ++i){
        cin >> a[i];
        deg[a[i]]++;
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= N; ++i) if (!deg[i]) pq.push(i);
    for (int i = 1; i <= N - 2; ++i){
        int leaf = pq.top(); pq.pop();
        cout << a[i] << " " << leaf << '\n';
        deg[a[i]]--;
        if (!deg[a[i]]) pq.push(a[i]);
    }
    cout << pq.top() << " ";
    pq.pop();
    cout << pq.top() << '\n';
}
