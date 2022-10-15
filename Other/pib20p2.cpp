#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll t;

bool uwu(ll problems){
    ll time=floor(problems/2)-floor(problems/7);
    if (time>t){
        return false;
    }
    return true;
}

int main(){
    cin >> t;
    ll bot=0,top=10000000000000000,mid; bool at,more; ll test;
    while (true){
        mid=(bot+top)/2;
        at=uwu(mid);
        more=uwu(mid+1);
        if (at&&!more){
            test = mid;
            break;
        }
        else if (more){
            bot=mid;
        }
        else{
            top=mid;
        }
    }
    for (ll i=50;i>=0;--i){
        if (uwu(i+test)){
            cout << i+test << '\n';
            return 0;
        }
    }
}