#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n; cin >> n;
    string uwu; cin >> uwu;
    pair<int,int> ans={0,0};
    int p=0,c=0;
    for (int i=0;i<n;++i){
        if (uwu[i]=='w'){
            if (p+c>ans.first+ans.second){
                ans={p,c};
            }
            p=c=0;
        }
        else if (uwu[i]=='p'){
            p++;
        }
        else{
            c++;
        }
    }
    if (p+c>ans.first+ans.second){
                ans={p,c};
            }
    cout << ans.first << " " << ans.second << '\n';
}