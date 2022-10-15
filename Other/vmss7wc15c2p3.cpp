#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
stack<pair<ll,ll>> s;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n; cin >> n;
    long long count=0,uwu,values=0;
    pair<ll,ll> temp;
    for (int k=0;k<n;++k){
        cin >> uwu;
        while (!s.empty()){
            if (s.top().first<uwu){
                values-=s.top().second;
                count+=s.top().second;
                s.pop();
            }
            else{break;}
        }
        if (s.empty()){
            s.push({uwu,1});
        }
        else if (s.top().first==uwu){
            count+=s.top().second;
            if (s.size()!=1){
                count++;
            }
            s.top().second++;
            
        }
        else{
            if (uwu<s.top().first){
                count++;
            }
            else{
                count+=values;
            }
            s.push({uwu,1});
        }
        values++;
        
        //cout << '\t' << count << " " << values << '\n';
    }
    cout << count << '\n';
}
