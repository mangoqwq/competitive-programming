#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int f[26];


int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n,k; cin >> n >> k;
    string uwu; cin >> uwu;
    for (auto&&x:uwu){
        f[x-'a']++;
    }
    pii Min={0x3f3f3f3f,0x3f3f3f3f};
    for (int i=0;i<26;++i){
        Min=min(Min,{f[i],i+'a'});
    }
    if (k<Min.first||k>n){
        cout << "WRONGANSWER" << '\n';
        return 0;
    }
    char ans[n+1];
    ans[n]='\0';
    for (int i=0;i<n;++i){
        if (uwu[i]==Min.second){
            ans[i]=Min.second;
            k--;
            Min.first--;
        }
        else if (k>Min.first){
            ans[i]=uwu[i];
            k--;
        }
        else{
            ans[i]=Min.second;
        }
    }
    cout << ans << '\n';
}