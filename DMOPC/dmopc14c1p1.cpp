#include <bits/stdc++.h>

using namespace std;
vector<double> tests;

int main(){
    int x; cin >> x;
    for (double i=0,a;i<x;++i){
        cin >> a;
        tests.push_back(a);
    }
    sort(tests.begin(),tests.end());
    if (x%2==0){
        cout << (int)round(((tests[(x/2)]+tests[(x/2)-1])/2)) << '\n';
    }
    else{
        cout << (int)tests[(x-1)/2] << '\n';
    }
}