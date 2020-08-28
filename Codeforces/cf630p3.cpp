#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")

using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
vector<int> a;
vector<int> b;
int n,q;

bool solve(int l, int r, int index){
    if (index==q-1){
        if (n-a[index]+1>=l && n-a[index]+1<=r){
            b[index]=n-a[index]+1;
            return true;
        }
        return false;
    }
    for (int i=l;i<=r;++i){
        if (solve(l+1,r+a[index],index+1)){
            b[index]=i;
            return true;
        }
    }
    return false;

}

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n >> q;
    for (int i=0,y;i<q;++i){
        cin >> y;
        a.push_back(y);
        b.push_back(0);
    }
    if (solve (1,1,0)){
        for (auto&&x:b){
            cout << x << " ";
        }
    }
    else{
        cout << -1 << '\n';
    }
    
}