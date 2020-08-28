#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;


int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int total=0; set<int> s;
    for (int i=0,a;i<9;++i){
        cin >> a;
        total+=a;
        s.insert(a);
    }
    total-=100;
    for (int x:s){
        if (s.count(total-x)){
            s.erase(x);
            s.erase(total-x);
            break;
        }
    }
    for (auto&&x:s){
        cout << x << '\n';
    }
}