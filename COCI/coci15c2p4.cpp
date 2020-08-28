#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int seed=131; const ll mod=1e15+7;
map<ll,int> teleports;
ll seedpowers[2000001];
ll hashuwu[2000001];

int main(){
    seedpowers[0]=1;
    for (int i=1;i<2000001;++i){
        seedpowers[i]=(seedpowers[i-1]*seed);
    }
    int n; cin >> n;
    string uwu;
    ll start, end;
    int imsad=0;
    for (int __=0;__<n;++__){
        cin >> uwu;
        int maximum=-1;
        for (int index=0;index<uwu.size();++index){
            hashuwu[index+1]=((hashuwu[index]*seed)+uwu[index]);
        }
        for (int len=0;len<=uwu.size();++len){
            start=hashuwu[len];
            end=(hashuwu[uwu.size()]-(hashuwu[uwu.size()-len]*seedpowers[len]));
            //cout << uwu.substr(0,len) << " : " << start << " - " << (uwu.substr(uwu.length()-len,uwu.length())) << " : " << end << '\n';
            if (start==end){
                maximum=max(maximum,teleports[start]);
            }
        }
        teleports[hashuwu[uwu.size()]]=maximum+1;
        imsad=max(imsad,maximum+1);
    }
    cout << imsad << '\n';
}