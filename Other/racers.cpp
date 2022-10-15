#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int seed=331;
bool a[100000]; string names[100000];
map<ll,int> m; string uwu;

ll gethash(){
    ll ans=0;
    for (int i=0;i<uwu.size();++i){
        ans=ans*seed+uwu[i];
    }
    return ans;
}

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n; cin >> n;
    getline(cin,uwu);
    for (int i=0;i<n;++i){
        getline(cin,uwu);
        names[i]=uwu;
        m[gethash()]=i;
        a[i]=true;
    }
    getline(cin,uwu); int count=0;
    while (uwu!="finished"){
        a[m[gethash()]]=false;
        getline(cin,uwu);
        count++;
    }
    cout << n-count+1 << '\n';
    for (int i=0;i<n;++i){
        if (a[i]) cout << names[i] << '\n';
    }
}