#include <bits/stdc++.h>

using namespace std;

int main(){
    int N,a; cin >> N;
    int arr1[N]; int arr2[N];
    for (int i=0;i<N;++i){
        cin >> a; arr1[i]=a;
    }
    for (int i=0;i<N;++i){
        cin >> a; arr2[i]=a;
    }
    int count=0; bool war=false;
    for (int i=0;i<N;++i){
        if (arr1[i]==arr2[i]&&war==false){
            count++;
            war=true;
        }
        if (arr1[i]!=arr2[i]){
            war=false;
        }
    }
    cout << count << '\n';
}