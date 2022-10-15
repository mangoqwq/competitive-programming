#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n,k;
    cin >> n >> k;
    priority_queue<int> pq;
    for (int i=0,a;i<n;++i){
        cin >> a;
        pq.push(a);
    }
    int total=0;
    int count=0;
    while (!pq.empty()){
        total+=pq.top(); pq.pop();
        count++;
        if (total>=k){
            cout << count << '\n';
            return 0;
        }
    }
    cout << -1 << '\n';
}
