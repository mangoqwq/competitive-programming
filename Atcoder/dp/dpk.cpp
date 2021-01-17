#include <bits/stdc++.h>

using namespace std;
bool win[100001];
vector<int> a;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n,k; cin >> n >> k;
    for (int i=0,x;i<n;++i){
        cin >> x;
        a.push_back(x);
    }
    for (int i=0;i<k;++i){
        if (!win[i]){
            for (auto&&x:a){
                if (i+x<=k){
                    win[i+x]=1;
                }
            }
        }
    }
    if (win[k]){
        cout << "First" << '\n';
    }
    else{
        cout << "Second" << '\n';
    }
}