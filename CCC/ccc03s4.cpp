#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll seed = 131; const ll mod=1e9+7;
ll hashuwu[5001];
ll exponent[5001];
set<ll> seen;

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    exponent[0]=1;
    for (int i=1;i<5001;++i){
        exponent[i]=exponent[i-1]*seed;
    }
    int cases; cin >> cases;
    ll substring;
    int count;
    for (int _=0;_<cases;++_){
        count=0;
        string uwu;
        seen.clear();
        cin >> uwu;
        for (int i=0;i<uwu.size();++i){
            hashuwu[i+1]=hashuwu[i]*seed+uwu[i]; //hashuwu[1] = 0, hashuwu[2] = 1...
        }
        for (int len=1;len<=uwu.size();++len){
            for (int l=1;l<=uwu.size()+1-len;++l){
                substring=hashuwu[l+len-1]-hashuwu[l-1]*exponent[len];
                //cout << uwu.substr(l-1,len) << " - " << substring << '\n';
                if (seen.find(substring)==seen.end()){
                    count++;
                    seen.insert(substring);
                }
            }
            seen.clear();
        }
        cout << count+1 << '\n';
    }
}