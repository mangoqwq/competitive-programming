#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >>n;
    int count=0;
    for (int i=0,a;i<n;++i){
        cin >> a;
        if (a>0){
            count++;
        }
    }
    cout << count << '\n';
}