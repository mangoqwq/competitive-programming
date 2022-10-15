#include <bits/stdc++.h>

using namespace std;

int main(){
    int N; cin >> N;
    priority_queue<int,vector<int>,greater<int>> pq;
    for (int i=0;i<N;++i){
        int a; cin >> a;
        pq.push(a);
    }
    for (int i=0;i<N-1;++i){
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << pq.top() << '\n';
}