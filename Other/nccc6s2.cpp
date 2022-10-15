#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")

using namespace std;
int uwu[1001][1001];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i){
        for (int k=1;k<=n;++k){
            cin >> uwu[i][k];
        }
    }
    int count=0;
    for (int i=1;i<=n;++i){
        for (int k=1;k<=n;++k){
            count++;
            if (uwu[i][k]!=count){
                for (int a=i;a<=n;++a){
                    if (uwu[a][k]==count){
                        cout << a-i+1 << '\n';
                        return 0;
                    }
                }
                for (int a=k;a<=n;++a){
                    if (uwu[i][a]==count){
                        cout << a-k+1 << '\n';
                        return 0;
                    }
                }
            }
        }
    }
}