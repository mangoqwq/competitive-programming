#include <bits/stdc++.h>

using namespace std;
typedef pair<pair<int,int>,pair<int,int>> owo;
typedef long long ll;
ll bit[100001],answers[100001];

void insert(int index,int val){
    while (index<100001){
        bit[index]+=val;
        index+=index&-index;
    }
}

ll add(int index){
    ll uwu=0;
    while (index>0){
        uwu+=bit[index];
        index-=index&-index;
    }
    return uwu;
}

int main(){
    int N,a,b,c; cin >> N;
    priority_queue<pair<int,int>> pq;
    for (int i=1;i<N+1;++i){
        cin >> a; pq.push({a,i});
    }
    int queries; cin >> queries;
    priority_queue<owo> qpq;
    for (int i=0;i<queries;++i){
        cin >> a >> b >> c; qpq.push({{c,i},{a,b}});
    }
    while (!qpq.empty()){
        while (pq.top().first>=qpq.top().first.first && !pq.empty()){
            insert(pq.top().second,pq.top().first);
            pq.pop();
        }
        answers[qpq.top().first.second]=add(qpq.top().second.second+1)-add(qpq.top().second.first);
        qpq.pop();
    }
    for (int i=0;i<queries;++i){
        cout << answers[i] << '\n';
    }

}