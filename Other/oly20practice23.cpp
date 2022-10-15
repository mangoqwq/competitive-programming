#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    int count=0;
    for (int a=1;a<=500;++a){
        for (int b=1;b<=a;++b){
            if (a*a-b*b==n) count++;
        }
    }
    cout << count << '\n';
}