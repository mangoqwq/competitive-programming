#include <bits/stdc++.h>

using namespace std;
int french[100000];
int english[100000];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int words; cin >> words; 
    for (int i=0;i<words;++i){
        cin >> french[i];
    }
    for (int i=0;i<words;++i){
        cin >> english[i];
    }
    int two=0,one=0,zero=0,temp;
    for (int i=0;i<words;++i){
        temp=zero;
        zero=english[i]+max(zero,max(one,two));
        two=one+french[i];
        one=temp+french[i];
    }
    cout << max(zero,max(one,two)) << '\n';

}