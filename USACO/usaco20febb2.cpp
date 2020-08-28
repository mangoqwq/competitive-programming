#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    string uwu1,uwu2; cin >> uwu1 >> uwu2;
    int count=0,a=false;
    for (int i=0;i<n;++i){
        if (uwu1[i]!=uwu2[i]){
            if (a==false){
                count++;
                a=true;
            }
        }
        else{
            a=false;
        }
    }
    cout << count << '\n';
}