#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int a,b,c; cin >> a >> b >> c;
    if (a+b>c&&b+c>a&&a+c>b){
        cout << "yes" << '\n';
    }
    else{
        cout << "no" << '\n';
    }
}