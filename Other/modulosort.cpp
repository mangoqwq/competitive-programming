#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n,k; cin >> n >> k;   
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    for (int i=0,a;i<n;++i){
        cin >> a;
        pq.push({a%k,a});
    }
    while (!pq.empty()){
        cout << pq.top().second << " ";
        pq.pop();
    }
    cout << '\n';
}