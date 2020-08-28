#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int seed=131;
string uwu;
ll hashuwu[1000005];
ll exponent[1000005];


int main(){
    cin.tie(0);
    
    exponent[0]=1;
    for (int i=0;i<1000004;++i){
        exponent[i+1]=exponent[i]*seed;
    }
    int cases; cin >> cases;
    int partitions;
    for (int _=0;_<cases;++_){
        partitions=0;
        cin >> uwu;
        for (int i=0;i<uwu.size();++i){
            hashuwu[i+1]=hashuwu[i]*seed+uwu[i];
        }
        int l=1;
        int r=uwu.size();
        int len=1;
        while (l<=r){
            if (r-len+1==l || l+len-1==r){
                partitions++;
                break;
            }
            if (hashuwu[l+len-1]-hashuwu[l-1]*exponent[len]==hashuwu[r]-hashuwu[r-len]*exponent[len]){
                l+=len;
                r-=len;
                len=1;
                partitions+=2;
            }
            else{
                len++;
            }
        }
        cout << partitions << '\n';
    }
}