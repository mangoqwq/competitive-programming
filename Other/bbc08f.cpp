#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    ll lights,pos; cin >> lights >> pos;
    ll l=pos,r=pos;
    ll currbot, currtop; 
    ll cost=0;
    for (int i=0;i<lights;++i){
        cin >> currbot >> currtop;
        if (currbot>=l && currtop<=r){
            l=currbot;
            r=currtop;
        }
        else if (currbot>=l && currbot<=r){
            l=currbot;
        }
        else if (currtop>=l && currtop<=r){
            r=currtop;
        }
        else if (currbot>r){
            l=r;
            r=currbot;
            cost+=r-l;
        }
        else if (currtop<l){
            r=l;
            l=currtop;
            cost+=r-l;
        }
    }
    cout << cost << '\n';
}