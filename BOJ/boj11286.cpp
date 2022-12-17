#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    struct Int{
        int x;
        bool operator<(const Int &other) const{
            return make_pair(abs(x), x) > make_pair(abs(other.x), other.x);
        }
    };
    priority_queue<Int> pq;
    while (N--){
        int x; cin >> x;
        if (x == 0){
            if (pq.empty()){
                cout << 0 << '\n';
                continue;
            }
            cout << pq.top().x << '\n';
            pq.pop();
        }
        else{
            pq.push({x});
        }
    }
}
