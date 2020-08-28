#include <bits/stdc++.h>

using namespace std;

int main(){
    int question, N,a; cin >> question >> N;
    int arr1[N],arr2[N];
    for (int i=0;i<N;++i){
        cin >> a;
        arr1[i]=a;
    }
    for (int i=0;i<N;++i){
        cin >> a;
        arr2[i]=a;
    }
    sort(arr1,arr1+N);
    sort(arr2,arr2+N);
    int total=0;
    if (question==2){
        reverse(arr1,arr1+N);
    }
    for (int i=0;i<N;++i){
        total+=max(arr1[i],arr2[i]);
    }
    cout << total << '\n';
}