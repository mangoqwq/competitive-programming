#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
map<char,pii> m;


int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    char uwu='A';
    for (int i=0;i<4;++i){
        for (int k=0;k<4;++k){
            m[uwu]={i,k};
            uwu++;
        }
    }
    int ans=0;
    for (int i=0;i<4;++i){
        for (int k=0;k<4;++k){
            cin>>uwu;
            if (uwu=='.') continue;
            ans+=abs(i-m[uwu].first)+abs(k-m[uwu].second);
        }
    }
    cout << ans << '\n';
}