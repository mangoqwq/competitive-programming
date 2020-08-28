#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;


int main(){
    int n,p; cin >> n >> p;
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    int count=1, fuel=0;
    for (int i=1,a,b;i<=n;++i){
        cin >> a >> b;
        if (i==p){
            fuel=a;
            continue;
        }
        pq.push({a,b});
    }
    int a,b;
    while (!pq.empty()){
        a=pq.top().first; b=pq.top().second;
        pq.pop();
        if (a<b){
            continue;
        }
        if (b>fuel){
            break;
        }
        count++;
        fuel+=(a-b);
    }
    cout << fuel << '\n' << count << '\n';
}