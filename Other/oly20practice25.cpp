#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n,k; cin >> n >> k;
    int speed,hours,rest;
    for (int i=0;i<k;++i){
        cin >> speed >> hours >> rest;
        int time=ceil((double)n/(double)speed);
        int uwu=time/hours;
        int remainder=time%hours;
        if (time%hours==0){
            cout << uwu*(hours+rest)+remainder-rest <<'\n';
            continue;
        }
        cout << uwu*(hours+rest)+remainder <<'\n';
    }
}
