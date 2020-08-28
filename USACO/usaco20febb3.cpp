#include <bits/stdc++.h>

using namespace std;
vector<int> uwu;
vector<int> owo;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n,k; cin >> n >> k;
    for (int i=1;i<=n;++i){
        uwu.push_back(i);
        owo.push_back(i);
    }
    int l1,r1,l2,r2,period=k+1; cin >> l1 >> r1 >> l2 >> r2;
    for (int i=1;i<k+1;++i){
        reverse(uwu.begin()+l1-1,uwu.begin()+r1);
        reverse(uwu.begin()+l2-1,uwu.begin()+r2);
        /*
        for (auto&&x:uwu){
            cout << x << " ";
        }
        cout << '\n';
        for (auto&&x:owo){
            cout << x << " ";
        }
        cout << '\n' << '\n';
        */
        if (uwu==owo){
            period=i;
            break;
        }
    }
    //cout << "AAA " << period << '\n';
    for (int i=0;i<(k%period);++i){
        reverse(owo.begin()+l1-1,owo.begin()+r1);
        reverse(owo.begin()+l2-1,owo.begin()+r2);
    }
    for (auto&&x:owo){
        cout << x << '\n';
    }
}