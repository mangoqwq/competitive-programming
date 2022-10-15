#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
priority_queue<pii,vector<pii>,greater<pii>> pq;
int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int t,n; cin >> t >> n;
    int a;
    while (n--){
        cin >> a;
        if (a<0){
            pq.push({abs(a),-1});
        }
        else{
            pq.push({a,1});
        }
    }
    int pos=0;
    int count=0;
    while (!pq.empty()){
        a=pq.top().first*pq.top().second; pq.pop();
        t-=abs(pos-a);
        if (t<0){
            break;
        }
        count++;
        pos=a;
    }
    cout << count << '\n';
}
