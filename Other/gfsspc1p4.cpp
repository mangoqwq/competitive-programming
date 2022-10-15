#include <bits/stdc++.h>

using namespace std;
int fib[501];

int main(){
    int n; cin >> n;
    string uwu; cin >> uwu;
    int curr1=1; int curr2=1; int temp;
    fib[curr1]=1; fib[curr2]=1;
    while (curr1+curr2<500){
        temp=curr2;
        curr2=curr1+curr2;
        curr1=temp;
        fib[curr2]=1;
    }
    for (int i=0;i<n;++i){
        if (uwu[i]=='A'&&!fib[i+1]){
            cout << "Bruno, GO TO SLEEP" << '\n';
            return 0;
        }
        if (fib[i+1]&&uwu[i]!='A'){
            cout << "Bruno, GO TO SLEEP" << '\n';
            return 0;
        }
    }
    cout <<"That's quite the observation!" << '\n';
}