#include <bits/stdc++.h>
#pragma GCC optimize ("unroll-loops")

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int seed=137; const ll mod=1e9+7; 
string uwu; 
ll hashuwu[5001],exponent[5001];
set<ll> seen[5001];
bool visited[5001]; map<ll,int> ans;

void init(){
    exponent[0]=1;
    for (int i=1;i<=5000;++i){
        exponent[i]=(exponent[i-1]*seed)%mod;
    }
    for (int i=1;i<=uwu.size();++i){
        hashuwu[i]=(hashuwu[i-1]*seed+uwu[i-1])%mod;
    }
}

ll gethash(int l, int r){
    return (hashuwu[r]-(hashuwu[l-1]*exponent[r-l+1])%mod+mod)%mod;
}


int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> uwu;
    init();
    ll h;  int temp=0;
    for (int i=1;i<=uwu.size()/2;++i){
        memset(visited, 0, sizeof visited);
        for (int k=1;k<=uwu.size()-i+1;++k){
            temp=0;
            if (visited[k]) continue;
            h=gethash(k,k+i-1);
            if (seen[i].find(h)!=seen[i].end()) continue;
            for (int j=i+k;j<=uwu.size()-i+1;j+=i){
                if (gethash(j,j+i-1)!=h) break;
                temp++; visited[j]=1;
                seen[j+i-k].insert(gethash(k,i+j-1));
            }
            if (temp>0) ans[h]=max(ans[h],temp);
        }
    }
    int answer=0;
    for (auto&&x:ans){
        answer+=x.second;
    }
    cout << answer << '\n';
}