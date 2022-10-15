#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
vector<pii> uwu;
vector<int> planes[1000000];

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n, p; cin >> n >> p;
    int a,b;
    for (int i=0;i<p;++i){
        cin >> a >> b;
        planes[a].push_back(b);
    }
    priority_queue<int> pq;
    int i=n;
    ll total=0;
    for (int i=n;i>=1;--i){
        for (auto&&x:planes[i]){
            pq.push(x);
        }
        if (!pq.empty()){
            total+=pq.top(); pq.pop();
        }
    }
    cout << total << '\n';
    
}