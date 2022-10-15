#include <bits/stdc++.h>

using namespace std;
int psa[100001];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cout.tie(0);
    cout.sync_with_stdio(0);
    string uwu; cin >> uwu;
    int count=0;
    for (int i=0;i<uwu.size();++i){
        if (uwu[i]=='G'){
            count++;
        }
        psa[i+1]=count;
    }
    int n; cin >> n;
    for (int i=0,a,b;i<n;++i){
        cin >> a >> b;
        cout << psa[b+1]-psa[a] << '\n';
    }
}